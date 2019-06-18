#pragma once

#include "Global3D.hpp"
#include "globals.h"

#include "Shape3D.hpp"
#include "MaterialPicker.hpp"
#include "PlaneMesh.hpp"

#include <memory>

namespace ART::Logic {

class Plane : public Shape3D {

public:
  Plane(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
    auto *materialPicker = new Modules::MaterialPicker(*this, "MaterialPicker");
    materialPicker->pickMaterial("PhongMaterial");
    new Modules::PlaneMesh(*this, "PlaneMesh");

    auto &tran = getChildren<Modules::Transform3D>("Transform3D");
    tran.setY(-20.0);
  }

  Type type() const noexcept override {
    return Type::PLANE;
  }

private:
};

} // namespace ART::Logic