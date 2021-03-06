cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)
project(advancedRayTracer VERSION 1.0.0 LANGUAGES C CXX)

###########################
# Dependencies

find_package(Qt5 COMPONENTS Core Gui Qml 3DCore 3DRender 3DInput 3DLogic 3DExtras 3DAnimation REQUIRED)

###########################
# Targets

# # Only used to make qml files accessible in VS
# file(GLOB_RECURSE QML_SRC "*.qml")
# source_group("Qml Files" FILES ${QML_SRC})

add_executable(${PROJECT_NAME}
  src/main.cpp
  src/QmlOutliner.hpp
  src/QmlOutliner.cpp

  # TODO : FIND WHY WINDOWS NEED THIS / linkage dosen't work ?
  # ../lib/src/models/Outliner.cpp

  resources.qrc
  components/components.qrc
  fonts/fonts.qrc
  shaders/shaders.qrc
  skybox/skybox.qrc
  styles/styles.qrc
  views/views.qrc
)



target_include_directories(${PROJECT_NAME}
  PUBLIC
    src
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    Qt5::Core
    Qt5::Gui
    Qt5::Qml
    Qt5::3DRender
    Qt5::3DInput
    Qt5::3DLogic
    Qt5::3DExtras
    Qt5::3DAnimation
    advancedRayTracer-lib
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
    AUTORCC ON
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# cotire(${PROJECT_NAME})
