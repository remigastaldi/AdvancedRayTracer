#include "WireframeMaterial.hpp"

namespace ART::Logic::Modules {

WireframeMaterial::WireframeMaterial(Shape3D &parent, std::string id, Qt3DRender::QMaterial *material)
    : Material<Qt3DRender::QMaterial>{parent, id, material} {
  material->addParameter(new Qt3DRender::QParameter{"ka", QVector3D{0.2, 0.0, 0.0}});
  material->addParameter(new Qt3DRender::QParameter{"kd", QVector3D{0.8, 0.0, 0.0}});
  material->addParameter(new Qt3DRender::QParameter{"ksp", QVector3D{0.95, 0.95, 0.95}});
  material->addParameter(new Qt3DRender::QParameter{"shininess", 150.0});
  material->addParameter(new Qt3DRender::QParameter{"line.width", 0.3});
  material->addParameter(new Qt3DRender::QParameter{"line.color", qRgba(0.0, 0.0, 0.0, 1.0)});

  auto *effect = new Qt3DRender::QEffect{material};
  effect->addParameter(new Qt3DRender::QParameter{"ka", QVector3D{0.1, 0.1, 0.1}});
  effect->addParameter(new Qt3DRender::QParameter{"kd", QVector3D{0.7, 0.7, 0.7}});
  effect->addParameter(new Qt3DRender::QParameter{"ks", QVector3D{0.95, 0.95, 0.95}});
  effect->addParameter(new Qt3DRender::QParameter{"shininess", 150.0});
  auto *technique = new Qt3DRender::QTechnique{effect};
  technique->addParameter(new Qt3DRender::QParameter{"light.position", QVector4D{0.0, 0.0, 0.0, 1.0}});
  technique->addParameter(new Qt3DRender::QParameter{"light.intensity", QVector3D{1.0, 1.0, 1.0}});
  technique->addParameter(new Qt3DRender::QParameter{"line.width", 1.0});
  technique->addParameter(new Qt3DRender::QParameter{"line.color", QVector4D{1.0, 1.0, 1.0, 1.0}});
  // Set the targeted GL version for the technique
  technique->graphicsApiFilter()->setApi(Qt3DRender::QGraphicsApiFilter::OpenGL);
  technique->graphicsApiFilter()->setMajorVersion(3);
  technique->graphicsApiFilter()->setMinorVersion(1);
  technique->graphicsApiFilter()->setProfile(Qt3DRender::QGraphicsApiFilter::CoreProfile);
  auto *filterKey = new Qt3DRender::QFilterKey{technique};
  filterKey->setName("renderingStyle");
  filterKey->setValue("forward");
  technique->addFilterKey(filterKey);
  auto *renderPass = new Qt3DRender::QRenderPass{technique};
  auto *shaderProgram = new Qt3DRender::QShaderProgram{renderPass};
  shaderProgram->setVertexShaderCode(Qt3DRender::QShaderProgram::loadSource(QString("qrc:/shaders/robustwireframe.vert")));
  shaderProgram->setGeometryShaderCode(Qt3DRender::QShaderProgram::loadSource(QString("qrc:/shaders/robustwireframe.geom")));
  shaderProgram->setFragmentShaderCode(Qt3DRender::QShaderProgram::loadSource(QString("qrc:/shaders/robustwireframe.frag")));
  renderPass->setShaderProgram(shaderProgram);
  technique->addRenderPass(renderPass);
  effect->addTechnique(technique);

  material->setEffect(effect);
}

// QColor WireframeMaterial::diffuse() { return get()->diffuse(); }
// QColor WireframeMaterial::specular() { return get()->specular(); }
// QColor WireframeMaterial::ambient() { return get()->ambient(); }

// void WireframeMaterial::setDiffuse(const QColor &color) noexcept { get()->setDiffuse(color); }
// void WireframeMaterial::setAmbient(const QColor &color) noexcept { get()->setAmbient(color); }
// void WireframeMaterial::setSpecular(const QColor &color) noexcept { get()->setSpecular(color); }
WireframeMaterial::~WireframeMaterial() {}

} // namespace ART::Logic::Modules