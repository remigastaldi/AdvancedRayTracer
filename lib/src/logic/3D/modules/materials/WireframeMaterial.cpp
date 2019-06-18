#include "WireframeMaterial.hpp"
#include <QSeamlessCubemap>
namespace ART::Logic::Modules {

WireframeMaterial::WireframeMaterial(Shape3D &parent, std::string id)
    : Material<Qt3DRender::QMaterial>{parent, id}, _alphaCoverage{false}, _qAlphaCoverage{nullptr}, _qMultisample{nullptr} {
  makeMaterial();
}

void WireframeMaterial::makeMaterial() noexcept {
  Qt3DRender::QMaterial *material = get();
  material->addParameter(new Qt3DRender::QParameter{"ka", QVector3D{0.0, 0.0, 0.0}});
  material->addParameter(new Qt3DRender::QParameter{"kd", QVector3D{0.0, 0.0, 0.0}});
  material->addParameter(new Qt3DRender::QParameter{"ksp", QVector3D{0.95, 0.95, 0.95}});
  material->addParameter(new Qt3DRender::QParameter{"shininess", 150.0});
  material->addParameter(new Qt3DRender::QParameter{"line.width", 0.4});
  material->addParameter(new Qt3DRender::QParameter{"line.color", QVector4D{0.0, 100.0, 100.0, 1.0}});
  material->addParameter(new Qt3DRender::QParameter{"opacity", 0.5});
  
  auto *effect = new Qt3DRender::QEffect{material};
  // effect->addParameter(new Qt3DRender::QParameter{"ka", QVector3D{0.1, 0.1, 0.1}});
  // effect->addParameter(new Qt3DRender::QParameter{"kd", QVector3D{0.7, 0.7, 0.7}});
  // effect->addParameter(new Qt3DRender::QParameter{"ks", QVector3D{0.95, 0.95, 0.95}});
  // effect->addParameter(new Qt3DRender::QParameter{"shininess", 150.0});
  auto *technique = new Qt3DRender::QTechnique{effect};
  // technique->addParameter(new Qt3DRender::QParameter{"light.position", QVector4D{0.0, 0.0, 0.0, 1.0}});
  // technique->addParameter(new Qt3DRender::QParameter{"light.intensity", QVector3D{1.0, 1.0, 1.0}});
  technique->addParameter(new Qt3DRender::QParameter{"line.width", 0.4});
  technique->addParameter(new Qt3DRender::QParameter{"line.color", QVector4D{0.0, 100.0, 100.0, 1.0}});
  // technique->addParameter(new Qt3DRender::QParameter{"position", QVector3D{0.0, 0.0, 0.0}});
  // technique->addParameter(new Qt3DRender::QParameter{"barycentric", QVector3D{0.0, 0.0, 0.0}});
  // effect->addParameter(new Qt3DRender::QParameter{"position", QVector3D{0.0, 0.0, 0.0}});
  // effect->addParameter(new Qt3DRender::QParameter{"barycentric", QVector3D{0.0, 0.0, 0.0}});
  // technique->addParameter(new Qt3DRender::QParameter{"position", QVector3D{0.0, 0.0, 0.0}});
  // technique->addParameter(new Qt3DRender::QParameter{"barycentric", QVector3D{0.0, 0.0, 0.0}});
  // Set the targeted GL version for the technique
  technique->graphicsApiFilter()->setApi(Qt3DRender::QGraphicsApiFilter::OpenGL);
  technique->graphicsApiFilter()->setMajorVersion(3);
  technique->graphicsApiFilter()->setMinorVersion(1);
  technique->graphicsApiFilter()->setProfile(Qt3DRender::QGraphicsApiFilter::CoreProfile);
  auto *filterKey = new Qt3DRender::QFilterKey{technique};
  filterKey->setName("renderingStyle");
  filterKey->setValue("forward");
  technique->addFilterKey(filterKey);
  _renderPass = new Qt3DRender::QRenderPass{technique};
  auto *shaderProgram = new Qt3DRender::QShaderProgram{_renderPass};
  shaderProgram->setVertexShaderCode(
      Qt3DRender::QShaderProgram::loadSource(QString("qrc:/shaders/robustwireframe.vert")));
  shaderProgram->setGeometryShaderCode(
      Qt3DRender::QShaderProgram::loadSource(QString("qrc:/shaders/robustwireframe.geom")));
  shaderProgram->setFragmentShaderCode(
      Qt3DRender::QShaderProgram::loadSource(QString("qrc:/shaders/robustwireframe.frag")));
  _renderPass->setShaderProgram(shaderProgram);
  technique->addRenderPass(_renderPass);
  effect->addTechnique(technique);

  get()->setEffect(effect);
}

// QColor WireframeMaterial::diffuse() { return get()->diffuse(); }
// QColor WireframeMaterial::specular() { return get()->specular(); }
// QColor WireframeMaterial::ambient() { return get()->ambient(); }

// void WireframeMaterial::setDiffuse(const QColor &color) noexcept { get()->setDiffuse(color); }
// void WireframeMaterial::setAmbient(const QColor &color) noexcept { get()->setAmbient(color); }
// void WireframeMaterial::setSpecular(const QColor &color) noexcept { get()->setSpecular(color); }
WireframeMaterial::~WireframeMaterial() {}

bool WireframeMaterial::alphaCoverage() const noexcept {
  return _alphaCoverage;
}

void WireframeMaterial::enableAlphaCoverage(bool enable) noexcept {
  _alphaCoverage = enable;
  if (enable && _renderPass != nullptr) {
    if (_qAlphaCoverage == nullptr) {
      _qAlphaCoverage = new Qt3DRender::QAlphaCoverage{_renderPass};
      _qMultisample =  new Qt3DRender::QMultiSampleAntiAliasing{_renderPass};
    }
    if (_qAlphaCoverage == nullptr || _qMultisample == nullptr)
      return;
    _renderPass->addRenderState(_qAlphaCoverage);
    _renderPass->addRenderState(_qMultisample);
  } else if (_renderPass != nullptr && _qAlphaCoverage != nullptr && _qMultisample != nullptr) {
    _renderPass->removeRenderState(_qAlphaCoverage);
    _renderPass->removeRenderState(_qMultisample);
  }
}

} // namespace ART::Logic::Modules