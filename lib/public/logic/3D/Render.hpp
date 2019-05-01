#pragma once

#include "globals.h"

#include "Geometry.hpp"
#include "MetalRoughMaterial.hpp"
#include "Shape3D.hpp"
#include "SphereMesh.hpp"
#include "Transform3D.hpp"

#include <fstream>
#include <unordered_map>

#include "stb_image.h"

namespace ART::Logic {

struct RenderLight {
  RenderLight(const Vec3f &p, const float &i) : position(p), intensity(i) {}
  Vec3f position;
  float intensity;
};

struct RenderMaterial {
  RenderMaterial(const float &r, const Vec4f &a, const Vec3f &color, const float &spec)
      : refractive_index(r), albedo(a), diffuse_color(color), specular_exponent(spec) {}
  RenderMaterial() : refractive_index(1), albedo(1, 0, 0, 0), diffuse_color(), specular_exponent() {}
  float refractive_index;
  Vec4f albedo;
  Vec3f diffuse_color;
  float specular_exponent;
};

struct RenderSphere {
  Vec3f center;
  float radius;
  RenderMaterial material;

  RenderSphere(const Vec3f &c, const float &r, const RenderMaterial &m) : center(c), radius(r), material(m) {}

  bool ray_intersect(const Vec3f &orig, const Vec3f &dir, float &t0) const {
    Vec3f L = center - orig;
    float tca = L * dir;
    float d2 = L * L - tca * tca;
    if (d2 > radius * radius)
      return false;
    float thc = sqrtf(radius * radius - d2);
    t0 = tca - thc;
    float t1 = tca + thc;
    if (t0 < 0)
      t0 = t1;
    if (t0 < 0)
      return false;
    return true;
  }
};

class Render {
public:
  Render(){};

  Vec3f reflect(const Vec3f &I, const Vec3f &N) { return I - N * 2.f * (I * N); }

  Vec3f refract(const Vec3f &I, const Vec3f &N, const float &refractive_index) { // Snell's law
    float cosi = -std::max(-1.f, std::min(1.f, I * N));
    float etai = 1, etat = refractive_index;
    Vec3f n = N;
    if (cosi < 0) { // if the ray is inside the object, swap the indices and invert the normal to get the correct result
      cosi = -cosi;
      std::swap(etai, etat);
      n = -N;
    }
    float eta = etai / etat;
    float k = 1 - eta * eta * (1 - cosi * cosi);
    return k < 0 ? Vec3f(0, 0, 0) : I * eta + n * (eta * cosi - sqrtf(k));
  }

  bool scene_intersect(const Vec3f &orig, const Vec3f &dir, const std::vector<RenderSphere> &spheres, Vec3f &hit,
                       Vec3f &N, RenderMaterial &material) {
    float spheres_dist = std::numeric_limits<float>::max();

    for (size_t i = 0; i < spheres.size(); i++) {
      float dist_i;
      if (spheres[i].ray_intersect(orig, dir, dist_i) && dist_i < spheres_dist) {
        spheres_dist = dist_i;
        hit = orig + dir * dist_i;
        N = (hit - spheres[i].center).normalize();
        material = spheres[i].material;
      }
    }

    float checkerboard_dist = std::numeric_limits<float>::max();
    if (fabs(dir.y) > 1e-3) {
      float d = -(orig.y + 4) / dir.y; // the checkerboard plane has equation y = -4
      Vec3f pt = orig + dir * d;
      if (d > 0 && fabs(pt.x) < 10 && pt.z < -10 && pt.z > -30 && d < spheres_dist) {
        checkerboard_dist = d;
        hit = pt;
        N = Vec3f(0, 1, 0);
        material.diffuse_color = (int(.5 * hit.x + 1000) + int(.5 * hit.z)) & 1 ? Vec3f(.3, .3, .3) : Vec3f(.3, .2, .1);
      }
    }
    return std::min(spheres_dist, checkerboard_dist) < 1000;
  }

  Vec3f cast_ray(const Vec3f &orig, const Vec3f &dir, const std::vector<RenderSphere> &spheres,
                 const std::vector<RenderLight> &lights, size_t depth) {
    Vec3f point, N;
    RenderMaterial material;

    if (depth > 6 || !scene_intersect(orig, dir, spheres, point, N, material)) {
      // int a = std::max(
          // 0, std::min(envmap_width - 1, static_cast<int>((atan2(dir.z, dir.x) / (2 * M_PI) + .5) * envmap_width)));
      // int b = std::max(0, std::min(envmap_height - 1, static_cast<int>(acos(dir.y) / M_PI * envmap_height)));
      // return envmap[a + b * envmap_width]; // background color
      return Vec3f(0.4, 0.7, 0.8);
    }

    Vec3f reflect_dir = reflect(dir, N).normalize();
    Vec3f refract_dir = refract(dir, N, material.refractive_index).normalize();
    Vec3f reflect_orig = reflect_dir * N < 0
                             ? point - N * 1e-3
                             : point + N * 1e-3; // offset the original point to avoid occlusion by the object itself
    Vec3f refract_orig = refract_dir * N < 0 ? point - N * 1e-3 : point + N * 1e-3;
    Vec3f reflect_color = cast_ray(reflect_orig, reflect_dir, spheres, lights, depth + 1);
    Vec3f refract_color = cast_ray(refract_orig, refract_dir, spheres, lights, depth + 1);

    float diffuse_light_intensity = 0, specular_light_intensity = 0;

    for (size_t i = 0; i < lights.size(); i++) {
      Vec3f light_dir = (lights[i].position - point).normalize();
      float light_distance = (lights[i].position - point).norm();

      Vec3f shadow_orig = light_dir * N < 0
                              ? point - N * 1e-3
                              : point + N * 1e-3; // checking if the point lies in the shadow of the lights[i]
      Vec3f shadow_pt, shadow_N;
      RenderMaterial tmpmaterial;
      if (scene_intersect(shadow_orig, light_dir, spheres, shadow_pt, shadow_N, tmpmaterial) &&
          (shadow_pt - shadow_orig).norm() < light_distance)
        continue;
      diffuse_light_intensity += lights[i].intensity * std::max(0.f, light_dir * N);
      specular_light_intensity +=
          powf(std::max(0.f, -reflect(-light_dir, N) * dir), material.specular_exponent) * lights[i].intensity;
    }
    return material.diffuse_color * diffuse_light_intensity * material.albedo[0] +
           Vec3f(1., 1., 1.) * specular_light_intensity * material.albedo[1] + reflect_color * material.albedo[2] +
           refract_color * material.albedo[3];
  }

  void render(const std::vector<RenderSphere> &spheres, const std::vector<RenderLight> &lights) {
    const int width = 1024;
    const int height = 768;
    float fov = M_PI / 3;
    std::vector<Vec3f> framebuffer(width * height);

    for (size_t j = 0; j < height; j++) {
      for (size_t i = 0; i < width; i++) {
        float x = (2 * (i + 0.5) / (float)width - 1) * tan(fov / 2.) * width / (float)height;
        float y = -(2 * (j + 0.5) / (float)height - 1) * tan(fov / 2.);
        Vec3f dir = Vec3f(x, y, -1).normalize();
        framebuffer[i + j * width] = cast_ray(_cameraPos, dir, spheres, lights, 0);
      }
    }

    _pixmap.reserve(width * height * 3);
    for (size_t i = 0; i < height * width; ++i) {
      Vec3f &c = framebuffer[i];
      float max = std::max(c[0], std::max(c[1], c[2]));
      if (max > 1)
        c = c * (1. / max);
      for (size_t j = 0; j < 3; j++) {
        _pixmap[i * 3 + j] = (unsigned char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
      }
    }
    std::cout << "=== END ===" << std::endl;
    std::ofstream ofs; // save the framebuffer to file
    ofs.open("./out.jpg");
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (size_t i = 0; i < height * width; ++i) {
      Vec3f &c = framebuffer[i];
      float max = std::max(c[0], std::max(c[1], c[2]));
      if (max > 1)
        c = c * (1. / max);
      for (size_t j = 0; j < 3; j++) {
        ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
      }
    }
    ofs.close();
  }

  void startRendering(std::unordered_map<std::string, std::unique_ptr<Entity>> &entities, const QVector3D &cameraPos) {
    RenderMaterial ivory(1.0, Vec4f(0.6, 0.3, 0.1, 0.0), Vec3f(0.4, 0.4, 0.3), 50.);
    RenderMaterial glass(1.5, Vec4f(0.0, 0.5, 0.1, 0.8), Vec3f(0.6, 0.7, 0.8), 125.);
    RenderMaterial red_rubber(1.0, Vec4f(0.9, 0.1, 0.0, 0.0), Vec3f(0.3, 0.1, 0.1), 10.);
    RenderMaterial mirror(1.0, Vec4f(0.0, 10.0, 0.8, 0.0), Vec3f(1.0, 1.0, 1.0), 1425.);

    // int n = -1;
    // unsigned char *pixmap = stbi_load(":/skybox.jpg", &envmap_width, &envmap_height, &n, 0);
    // if (!pixmap || 3 != n) {
    //   std::cerr << "Error: can not load the environment map" << std::endl;
    //   return;
    // }
    // envmap = std::vector<Vec3f>(envmap_width * envmap_height);
    // for (int j = envmap_height - 1; j >= 0; j--) {
    //   for (int i = 0; i < envmap_width; i++) {
    //     envmap[i + j * envmap_width] =
    //         Vec3f(pixmap[(i + j * envmap_width) * 3 + 0], pixmap[(i + j * envmap_width) * 3 + 1],
    //               pixmap[(i + j * envmap_width) * 3 + 2]) *
    //         (1 / 255.);
    //   }
    // }
    // stbi_image_free(pixmap);

    std::vector<RenderSphere> spheres;
    // {Vec3f(-3, 0, -16), 2, ivory},
    //                                   {Vec3f(-1.0, -1.5, -12), 2, glass},
    //                                   {Vec3f(1.5, -0.5, -18), 3, red_rubber},
    //                                   {Vec3f(7, 5, -18), 4, mirror}};

    // std::vector<RenderLight> lights;
    // {Vec3f(-20, 20, 20), 1.5}, {Vec3f(30, 50, -25), 1.8}, {Vec3f(30, 20, 30), 1.7}};
    std::vector<RenderLight> lights{{Vec3f(-20, 20, 20), 1}};

    _cameraPos = Vec3f(cameraPos.x(), cameraPos.y(), cameraPos.y());
    // _cameraPos = Vec3f(cameraPos.x(), cameraPos.y(), cameraPos.y());

    for (auto &[key, value] : entities) {
      Shape3D *shape = dynamic_cast<Shape3D *>(value.get());
      std::cout << (int)shape->type() << std::endl;
      if (shape->type() == Type::SPHERE) {
        auto &mesh = value->getChildren<Modules::SphereMesh>("SphereMesh");
        auto &tran = value->getChildren<Modules::Transform3D>("Transform3D");
        RenderMaterial material = ivory;
        if (value->hasChildren("MetalRoughMaterial")) {
          material = mirror;
        } else if (value->hasChildren("PhongAlphaMaterial")) {
          material = glass;
        } else if (value->hasChildren("PhongAlphaMaterial")) {
          material = red_rubber;
        }
        spheres.emplace_back(RenderSphere{Vec3f{tran.x(), tran.y(), tran.z()}, mesh.radius(), material});
      } else if (shape->type() == Type::LIGHT) {
        auto &tran = value->getChildren<Modules::Transform3D>("Transform3D");

        lights.emplace_back(RenderLight{Vec3f{tran.x(), tran.y(), tran.z()}, 1});
      }
    }
    render(spheres, lights);
  }

  const std::vector<unsigned char> &pixmap() const noexcept { return _pixmap; }

  bool empty() const noexcept { return _pixmap.empty(); }

private:
  int envmap_width;
  int envmap_height;
  std::vector<Vec3f> envmap;
  Vec3f _cameraPos;
  std::vector<unsigned char> _pixmap;
};

} // namespace ART::Logic
