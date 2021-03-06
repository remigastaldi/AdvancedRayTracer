cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)
project(advancedRayTracer-lib VERSION 1.0.0 LANGUAGES C CXX)
set(LIBRARY_NAME advancedraytracer)

###########################
# Dependencies
find_package(OpenGL COMPONENTS OpenGL REQUIRED)
find_package(Qt5 COMPONENTS QuickControls2 Widgets 3DCore 3DRender 3DInput 3DLogic 3DExtras 3DAnimation Concurrent  REQUIRED)

###########################
# Targets
add_library(${PROJECT_NAME} SHARED
  # Src
  ## Controllers
  src/controllers/MainController.cpp
  src/controllers/ToolbarController.cpp
  src/controllers/RightSidebarController.cpp
  src/controllers/DrawToolbar3DController.cpp
  src/controllers/DrawToolbar2DController.cpp

  ## Models
  src/models/ToolbarModel.cpp
  src/models/RightSidebarModel.cpp
  src/models/Outliner.cpp

  ## Logic
  src/logic/Entity.cpp
  ## 3D
  src/logic/3D/LightEntity.cpp
  src/logic/3D/Torus.cpp
  src/logic/3D/Cuboid.cpp
  src/logic/3D/Object3D.cpp
  src/logic/3D/SceneLoader.cpp
  src/logic/3D/Scene3D.cpp
  src/logic/3D/Sphere.cpp
  src/logic/3D/Shape3D.cpp
  src/logic/3D/RootEntity.cpp
  src/logic/3D/RenderItem.cpp
  
  ### Modules
  src/logic/3D/modules/Material.cpp
  src/logic/3D/modules/Mesh.cpp
  src/logic/3D/modules/Light.cpp
  src/logic/3D/modules/Transform3D.cpp
  src/logic/3D/modules/MaterialPicker.cpp
  src/logic/3D/modules/LightPicker.cpp

  #### Modules Meshes
  src/logic/3D/modules/meshes/TorusMesh.cpp
  src/logic/3D/modules/meshes/CuboidMesh.cpp
  src/logic/3D/modules/meshes/SphereMesh.cpp
  src/logic/3D/modules/meshes/PlaneMesh.cpp
  src/logic/3D/modules/meshes/ConeMesh.cpp

  #### Modules Materials
  src/logic/3D/modules/materials/PhongAlphaMaterial.cpp
  src/logic/3D/modules/materials/PhongMaterial.cpp
  src/logic/3D/modules/materials/MetalRoughMaterial.cpp
  src/logic/3D/modules/materials/WireframeMaterial.cpp

  #### Modules Lights 
  src/logic/3D/modules/lights/SpotLight.cpp
  src/logic/3D/modules/lights/PointLight.cpp
  src/logic/3D/modules/lights/DirectionalLight.cpp
  
  ## 2D
  src/logic/2D/Scene2D.cpp
  src/logic/2D/Shape2D.cpp
  src/logic/2D/Line.cpp
  src/logic/2D/Rectangle.cpp
  src/logic/2D/Circle.cpp
  src/logic/2D/Triangle.cpp
  src/logic/2D/Polygon.cpp
  src/logic/2D/Image.cpp
  src/logic/2D/PaintedItem.cpp
  ## 2D
  src/logic/2D/modules/ZIndex.cpp
  src/logic/2D/modules/Transform2D.cpp
  src/logic/2D/modules/Brush.cpp
  src/logic/2D/modules/Pen.cpp

  # Public
  ## Controllers
  public/controllers/MainController.hpp
  public/controllers/ToolbarController.hpp
  public/controllers/RightSidebarController.hpp
  public/controllers/DrawToolbar3DController.hpp
  public/controllers/DrawToolbar2DController.hpp
  public/controllers/CameraController.hpp

  ## Logic
  public/logic/Entity.hpp
  public/logic/Scene.hpp
  ## 3D
  public/logic/3D/LightEntity.hpp
  public/logic/3D/Torus.hpp
  public/logic/3D/Plane.hpp
  public/logic/3D/Cuboid.hpp
  public/logic/3D/SceneLoader.hpp
  public/logic/3D/Object3D.hpp
  public/logic/3D/Scene3D.hpp
  public/logic/3D/Sphere.hpp
  public/logic/3D/Shape3D.hpp
  public/logic/3D/RootEntity.hpp
  public/logic/3D/Global3D.hpp
  public/logic/3D/Geometry.hpp
  public/logic/3D/Render.hpp
  public/logic/3D/RenderItem.hpp
  
  ### Modules
  public/logic/3D/modules/Material.hpp
  public/logic/3D/modules/Mesh.hpp
  public/logic/3D/modules/Light.hpp
  public/logic/3D/modules/Transform3D.hpp
  public/logic/3D/modules/MaterialPicker.hpp
  public/logic/3D/modules/LightPicker.hpp

  #### Modules Meshes
  public/logic/3D/modules/meshes/TorusMesh.hpp
  public/logic/3D/modules/meshes/CuboidMesh.hpp
  public/logic/3D/modules/meshes/SphereMesh.hpp
  public/logic/3D/modules/meshes/PlaneMesh.hpp
  public/logic/3D/modules/meshes/ConeMesh.hpp

  #### Modules Materials
  public/logic/3D/modules/materials/PhongMaterial.hpp
  public/logic/3D/modules/materials/PhongAlphaMaterial.hpp
  public/logic/3D/modules/materials/MetalRoughMaterial.hpp
  public/logic/3D/modules/materials/WireframeMaterial.hpp

  #### Modules Lights 
  public/logic/3D/modules/lights/SpotLight.hpp
  public/logic/3D/modules/lights/PointLight.hpp
  public/logic/3D/modules/lights/DirectionalLight.hpp

  ## 2D
  public/logic/2D/Scene2D.hpp
  public/logic/2D/Shape2D.hpp
  public/logic/2D/Line.hpp
  public/logic/2D/Rectangle.hpp
  public/logic/2D/Circle.hpp
  public/logic/2D/Triangle.hpp
  public/logic/2D/Polygon.hpp
  public/logic/2D/Image.hpp
  public/logic/2D/PaintedItem.hpp
  ### Modules
  public/logic/2D/modules/ZIndex.hpp
  public/logic/2D/modules/Transform2D.hpp
  public/logic/2D/modules/Brush.hpp
  public/logic/2D/modules/Pen.hpp

  ## Models
  public/models/ToolbarModel.hpp
  public/models/RightSidebarModel.hpp
  public/models/Outliner.hpp

  public/globals.h
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:
      public
      public/controllers
      public/models
      public/logic
      public/logic/2D
      public/logic/2D/modules
      public/logic/3D
      public/logic/3D/modules
      public/logic/3D/modules/meshes
      public/logic/3D/modules/materials
      public/logic/3D/modules/lights
     >
    $<BUILD_INTERFACE:
      ${CMAKE_CURRENT_SOURCE_DIR}/public
      ${CMAKE_CURRENT_SOURCE_DIR}/public/controllers
      ${CMAKE_CURRENT_SOURCE_DIR}/public/models
      ${CMAKE_CURRENT_SOURCE_DIR}/public/logic
      ${CMAKE_CURRENT_SOURCE_DIR}/public/logic/3D
      ${CMAKE_CURRENT_SOURCE_DIR}/public/logic/3D/modules
      ${CMAKE_CURRENT_SOURCE_DIR}/public/logic/3D/modules/meshes
      ${CMAKE_CURRENT_SOURCE_DIR}/public/logic/3D/modules/materials
      ${CMAKE_CURRENT_SOURCE_DIR}/public/logic/3D/modules/lights
      ${CMAKE_CURRENT_SOURCE_DIR}/public/logic/2D
      ${CMAKE_CURRENT_SOURCE_DIR}/public/logic/2D/modules
     >
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/controllers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic/3D
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic/3D/modules
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic/3D/modules/meshes
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic/3D/modules/materials
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic/3D/modules/lights
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic/2D
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic/2D/modules
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    ADVANCED_RAY_TRACER_LIBRARY
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    OpenGL::GL
    Qt5::QuickControls2
    Qt5::Widgets
    Qt5::3DRender
    Qt5::3DInput
    Qt5::3DLogic
    Qt5::3DExtras
    Qt5::3DAnimation
    Qt5::Concurrent
)

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_17
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
  -fdiagnostics-color=always
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    AUTOMOC ON
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

###########################
# Include tests

# cotire(${PROJECT_NAME})

add_subdirectory(tests)
