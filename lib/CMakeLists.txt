cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)
project(advancedRayTracer-lib VERSION 1.0.0 LANGUAGES C CXX)
set(LIBRARY_NAME advancedraytracer)

###########################
# Dependencies
find_package(OpenGL COMPONENTS OpenGL REQUIRED)
find_package(Qt5 COMPONENTS QuickControls2 Widgets 3DCore 3DRender 3DInput 3DLogic 3DExtras 3DAnimation  REQUIRED)

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
  src/logic/3D/Scene3D.cpp
  src/logic/3D/Sphere.cpp
  src/logic/3D/Shape3D.cpp
  ### Modules
  src/logic/3D/modules/Material.cpp
  src/logic/3D/modules/Mesh.cpp
  ## 2D
  src/logic/2D/Scene2D.cpp
  src/logic/2D/Shape2D.cpp
  src/logic/2D/Line.cpp
  src/logic/2D/Rectangle.cpp
  src/logic/2D/Image.cpp

  # Public
  ## Controllers
  public/controllers/MainController.hpp
  public/controllers/ToolbarController.hpp
  public/controllers/RightSidebarController.hpp
  public/controllers/DrawToolbar3DController.hpp
  public/controllers/DrawToolbar2DController.hpp

  ## Logic
  public/logic/Entity.hpp
  public/logic/Module.hpp
  ## 3D
  public/logic/3D/Scene3D.hpp
  public/logic/3D/Sphere.hpp
  public/logic/3D/Shape3D.hpp
  ### Modules
  public/logic/3D/modules/Material.hpp
  public/logic/3D/modules/Mesh.hpp
  ## 2D
  public/logic/2D/Scene2D.hpp
  public/logic/2D/Shape2D.hpp
  public/logic/2D/Line.hpp
  public/logic/2D/Rectangle.hpp
  public/logic/2D/Image.hpp

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
      public/logic/3D
      public/logic/3D/modules
     >
    $<BUILD_INTERFACE:
      ${CMAKE_CURRENT_SOURCE_DIR}/public
      ${CMAKE_CURRENT_SOURCE_DIR}/public/controllers
      ${CMAKE_CURRENT_SOURCE_DIR}/public/models
      ${CMAKE_CURRENT_SOURCE_DIR}/public/logic
      ${CMAKE_CURRENT_SOURCE_DIR}/public/logic/3D
      ${CMAKE_CURRENT_SOURCE_DIR}/public/logic/2D
      ${CMAKE_CURRENT_SOURCE_DIR}/public/logic/3D/modules
     >
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/controllers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic/3D
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic/2D
    ${CMAKE_CURRENT_SOURCE_DIR}/src/logic/3D/modules
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
