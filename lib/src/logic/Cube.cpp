#include  "Cube.hpp"

#include "Vertex.hpp"
// Front Verticies
#define VERTEX_FTR Vertex( QVector3D( 0.5f,  0.5f,  0.5f), QVector3D( 1.0f, 0.0f, 0.0f ) )
#define VERTEX_FTL Vertex( QVector3D(-0.5f,  0.5f,  0.5f), QVector3D( 0.0f, 1.0f, 0.0f ) )
#define VERTEX_FBL Vertex( QVector3D(-0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 1.0f ) )
#define VERTEX_FBR Vertex( QVector3D( 0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 0.0f ) )
 
// Back Verticies
#define VERTEX_BTR Vertex( QVector3D( 0.5f,  0.5f, -0.5f), QVector3D( 1.0f, 1.0f, 0.0f ) )
#define VERTEX_BTL Vertex( QVector3D(-0.5f,  0.5f, -0.5f), QVector3D( 0.0f, 1.0f, 1.0f ) )
#define VERTEX_BBL Vertex( QVector3D(-0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 0.0f, 1.0f ) )
#define VERTEX_BBR Vertex( QVector3D( 0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 1.0f, 1.0f ) )
 
// Create a colored cube
static const Vertex sg_vertexes[] = {
  // Face 1 (Front)
    VERTEX_FTR, VERTEX_FTL, VERTEX_FBL,
    VERTEX_FBL, VERTEX_FBR, VERTEX_FTR,
  // Face 2 (Back)
    VERTEX_BBR, VERTEX_BTL, VERTEX_BTR,
    VERTEX_BTL, VERTEX_BBR, VERTEX_BBL,
  // Face 3 (Top)
    VERTEX_FTR, VERTEX_BTR, VERTEX_BTL,
    VERTEX_BTL, VERTEX_FTL, VERTEX_FTR,
  // Face 4 (Bottom)
    VERTEX_FBR, VERTEX_FBL, VERTEX_BBL,
    VERTEX_BBL, VERTEX_BBR, VERTEX_FBR,
  // Face 5 (Left)
    VERTEX_FBL, VERTEX_FTL, VERTEX_BTL,
    VERTEX_FBL, VERTEX_BTL, VERTEX_BBL,
  // Face 6 (Right)
    VERTEX_FTR, VERTEX_FBR, VERTEX_BBR,
    VERTEX_BBR, VERTEX_BTR, VERTEX_FTR
};
 
#undef VERTEX_BBR
#undef VERTEX_BBL
#undef VERTEX_BTL
#undef VERTEX_BTR
 
#undef VERTEX_FBR
#undef VERTEX_FBL
#undef VERTEX_FTL
#undef VERTEX_FTR

namespace ART {
namespace Logic {

Cube::Cube(): _program{nullptr} {
  translate({0.0, 0.0, 0.0});
  init();
}

Cube::Cube(const QVector3D &translation): _program{nullptr} {
  translate(translation);
  init();
}

Cube::Cube(const Transform3D &transform): Transform3D{transform} {
    init();
  }

void Cube::init() noexcept {
  _program = std::make_unique<QOpenGLShaderProgram>();
  _program->addCacheableShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/test.vert");
  _program->addCacheableShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/test.frag");
  // _program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/test.vert");
  // _program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/test.frag");
  _program->link();
  // _program->bindAttributeLocation("vertices", 0);
  _program->bind();

  // Cache Uniform Locations
  _modelToWorld = _program->uniformLocation("modelToWorld");
  _worldToView = _program->uniformLocation("worldToView");
 
  // Create Buffer (Do not release until VAO is created)
  _vertex.create();
  _vertex.bind();
  _vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
  _vertex.allocate(sg_vertexes, sizeof(sg_vertexes));
 
  // Create Vertex Array Object
  _object.create();
  _object.bind();
  _program->enableAttributeArray(0);
  _program->enableAttributeArray(1);
  _program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
  _program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

  // Release (unbind) all
  _object.release();
  _vertex.release();
  _program->release();
}

Cube::~Cube()  noexcept {
  _object.destroy();
  _vertex.destroy();
}

void Cube::update(const QMatrix4x4 &projection) noexcept {
    // Render using our shader
  _program->bind();
  _program->setUniformValue(_worldToView, projection);
  
  _object.bind();
  _program->setUniformValue(_modelToWorld, toMatrix());
  glDrawArrays(GL_TRIANGLES, 0, sizeof(sg_vertexes) / sizeof(sg_vertexes[0]));
  _object.release();

  _program->release();
}

} // namespace Logic
} // namespace ART
