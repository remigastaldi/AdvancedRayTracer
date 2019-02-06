#include "RendererModel.hpp"

namespace ART {
namespace Models {

RendererModel::RendererModel()
: _program{nullptr}
{
  initializeOpenGLFunctions();

  _program = std::make_unique<QOpenGLShaderProgram>();
  _program->addCacheableShaderFromSourceCode(QOpenGLShader::Vertex, "attribute highp vec4 vertices;"
                                                                     "varying highp vec2 coords;"
                                                                     "void main() {"
                                                                     "    gl_Position = vertices;"
                                                                     "    coords = vertices.xy;"
                                                                     "}");
  _program->addCacheableShaderFromSourceCode(
      QOpenGLShader::Fragment, "uniform lowp float t;"
                               "varying highp vec2 coords;"
                               "void main() {"
                               "    lowp float i = 1. - (pow(abs(coords.x), 4.) + pow(abs(coords.y), 4.));"
                               "    i = smoothstep(t - 0.8, t + 0.8, i);"
                               "    i = floor(i * 20.) / 20.;"
                               "    gl_FragColor = vec4(coords * .5 + .5, i, i);"
                               "}");

  _program->bindAttributeLocation("vertices", 0);
  _program->link();
}

QOpenGLFramebufferObject *RendererModel::createFramebufferObject(const QSize &size) {
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    format.setSamples(4);

    return new QOpenGLFramebufferObject(size, format);
}

void RendererModel::render() noexcept {
  std::cout << "Start rendering" << std::endl;
  glClear(GL_COLOR_BUFFER_BIT);
  
  _program->bind();

  _program->enableAttributeArray(0);

  float values[] = {-1, -1, 1, -1, -1, 1, 1, 1};
  _program->setAttributeArray(0, GL_FLOAT, values, 2);
  // m_program->setUniformValue("t", (float)m_t);

  // glViewport(0, 0, 800, 600);

  glDisable(GL_DEPTH_TEST);

  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE);

  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  _program->disableAttributeArray(0);
  _program->release();

  // m_window->resetOpenGLState();
}

} // namespace Models
} // namespace ART
