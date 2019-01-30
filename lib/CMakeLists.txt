cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)
project(advancedRayTracer-lib VERSION 1.0.0 LANGUAGES C CXX)
set(LIBRARY_NAME advancedraytracer)

###########################
# Dependencies
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

###########################
# Targets
add_library(${PROJECT_NAME} SHARED
  # Src
  ## Controllers
  src/controllers/main-controller.cpp
  src/controllers/menu-controller.cpp

  ## Models
  src/models/menu-model.cpp

  # Public
  ## Controllers
  public/controllers/main-controller.hpp
  public/controllers/menu-controller.hpp

  ## Models
  public/models/menu-model.hpp

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
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_14
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
