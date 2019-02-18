#pragma once

#include <memory>

#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

#include "RenderObject.hpp"
#include "Transform3D.hpp"

#include "globals.h"
#include <iostream>

namespace ART {

namespace Logic {

// class FbItem;

class ADVANCED_RAY_TRACER_EXPORT Cube : public RenderObject, public Transform3D {
public:
  typedef Cube Type;

  Cube();
  explicit Cube(const QVector3D &translation);
  explicit Cube(const Transform3D &transform);
  virtual ~Cube() noexcept;

  Cube(const Cube &other) = delete;
  Cube(Cube &&other) = delete;
  Cube &operator=(const Cube &other) = delete;
  Cube &operator=(Cube &&other) = delete;

  void update(const QMatrix4x4 &projection) noexcept override;
  
private:
  void init() noexcept;

private:
  // OpenGL State Information
  std::unique_ptr<QOpenGLShaderProgram> _program;
  QOpenGLBuffer _vertex;
  QOpenGLVertexArrayObject _object;

  // Shader Information
  int _modelToWorld;
  int _worldToView;
  // Transform3D m_transform;
};

} // nameSpace Logic
} // namespace ART
