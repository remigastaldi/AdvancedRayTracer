#include "Transform3D.hpp"
#include <QDebug>

// Transform By (Add/Scale)
void Transform3D::translate(const QVector3D &dt) {
  _dirty = true;
  _translation += dt;
}

void Transform3D::scale(const QVector3D &ds) {
  _dirty = true;
  _scale *= ds;
}

void Transform3D::rotate(const QQuaternion &dr) {
  _dirty = true;
  _rotation = dr * _rotation;
}

void Transform3D::grow(const QVector3D &ds) {
  _dirty = true;
  _scale += ds;
}

// Transform To (Setters)
void Transform3D::setTranslation(const QVector3D &t) {
  _dirty = true;
  _translation = t;
}

void Transform3D::setScale(const QVector3D &s) {
  _dirty = true;
  _scale = s;
}

void Transform3D::setRotation(const QQuaternion &r) {
  _dirty = true;
  _rotation = r;
}

// Accessors
const QMatrix4x4 &Transform3D::toMatrix() {
  if (_dirty) {
    _dirty = false;
    _world.setToIdentity();
    _world.translate(_translation);
    _world.rotate(_rotation);
    _world.scale(_scale);
  }
  return _world;
}

// Qt Streams
QDebug operator<<(QDebug dbg, const Transform3D &transform) {
  dbg << "Transform3D\n{\n";
  dbg << "Position: <" << transform.translation().x() << ", " << transform.translation().y() << ", "
      << transform.translation().z() << ">\n";
  dbg << "Scale: <" << transform.scale().x() << ", " << transform.scale().y() << ", " << transform.scale().z() << ">\n";
  dbg << "Rotation: <" << transform.rotation().x() << ", " << transform.rotation().y() << ", "
      << transform.rotation().z() << " | " << transform.rotation().scalar() << ">\n}";
  return dbg;
}

QDataStream &operator<<(QDataStream &out, const Transform3D &transform) {
  out << transform._translation;
  out << transform._scale;
  out << transform._rotation;
  return out;
}

QDataStream &operator>>(QDataStream &in, Transform3D &transform) {
  in >> transform._translation;
  in >> transform._scale;
  in >> transform._rotation;
  transform._dirty = true;
  return in;
}