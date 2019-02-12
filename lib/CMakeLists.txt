cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)
project(advancedRayTracer-lib VERSION 1.0.0 LANGUAGES C CXX)
set(LIBRARY_NAME advancedraytracer)

###########################
# Dependencies
find_package(Qt5 COMPONENTS  Quick QuickControls2 Widgets REQUIRED)

###########################
# Targets
add_library(${PROJECT_NAME} SHARED
  # Src
  ## Controllers
  src/controllers/MainController.cpp
  src/controllers/ToolbarController.cpp
  src/controllers/RightSidebarController.cpp
  src/controllers/LeftSidebarController.cpp
  src/controllers/RendererController.cpp

  ## Models
  src/models/ToolbarModel.cpp
  src/models/RightSidebarModel.cpp
  src/models/LeftSidebarModel.cpp
  src/models/RendererModel.cpp

  # Public
  ## Controllers
  public/controllers/MainController.hpp
  public/controllers/ToolbarController.hpp
  public/controllers/RightSidebarController.hpp
  public/controllers/LeftSidebarController.hpp
  public/controllers/RendererController.hpp

  ## Models
  public/models/ToolbarModel.hpp
  public/models/RightSidebarModel.hpp
  public/models/LeftSidebarModel.hpp
  public/models/RendererModel.hpp

  public/globals.h
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:
      public
      public/controllers
      public/models
     >
    $<BUILD_INTERFACE:
      ${CMAKE_CURRENT_SOURCE_DIR}/public
      ${CMAKE_CURRENT_SOURCE_DIR}/public/controllers
      ${CMAKE_CURRENT_SOURCE_DIR}/public/models
     >
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/controllers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    ADVANCED_RAY_TRACER_LIBRARY
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    Qt5::Widgets
    Qt5::Quick
    Qt5::QuickControls2
)

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_17
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
