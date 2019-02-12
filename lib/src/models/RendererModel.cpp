#include "RendererController.hpp"
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
  qInfo() << "Start rendering";

  QSize drawRectSize(static_cast<int>(_controller->size().width()), static_cast<int>(_controller->size().height()));
  const QRect drawRect(0, 0, drawRectSize.width(), drawRectSize.height());

  QOpenGLPaintDevice device(drawRectSize);
  // p.beginNativePainting();

  _program->bind();

  _program->enableAttributeArray(0);

  float values[] = {-1, -1, 1, -1, -1, 1, 1, 1};
  _program->setAttributeArray(0, GL_FLOAT, values, 2);
  _program->setUniformValue("t", 0);

  // glViewport(0, 0, 800, 600);

  glDisable(GL_DEPTH_TEST);

  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE);

  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  _program->disableAttributeArray(0);
  _program->release();

  // QPainter painter;
  // painter.begin(&device);
  // painter.setRenderHints(QPainter::Antialiasing | QPainter::HighQualityAntialiasing);

  // painter.fillRect(drawRect, Qt::blue);

  // painter.drawTiledPixmap(drawRect, QPixmap(":/qt-project.org/qmessagebox/images/qtlogo-64.png"));

  // painter.setPen(QPen(Qt::green, 5));
  // painter.setBrush(Qt::red);
  // painter.drawEllipse(0, 100, 400, 200);
  // painter.drawEllipse(100, 0, 200, 400);

  // painter.setPen(QPen(Qt::white, 0));
  // QFont font;
  // font.setPointSize(24);
  // painter.setFont(font);
  // painter.drawText(drawRect, "Hello FBO", QTextOption(Qt::AlignCenter));

  // painter.end();

  _window->resetOpenGLState();
}

void  RendererModel::synchronize(QQuickFramebufferObject* qqfbo) noexcept {
    qInfo() << "Synchronize data before rendering";

    auto parentItem = dynamic_cast<Controllers::RendererController*>(qqfbo);
    _window = parentItem->window();
    _controller = parentItem;
}

} // namespace Models
} // namespace ART
