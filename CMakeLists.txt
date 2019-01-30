cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
# include(cotire)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(AdvancedRayTracer VERSION 0.0.1 LANGUAGES C CXX)

add_subdirectory(lib)
add_subdirectory(ui-qml)
