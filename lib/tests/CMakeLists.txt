cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)
project(advancedRayTracer-test VERSION 1.0.0 LANGUAGES C CXX)

###########################
# Dependencies

find_package(Qt5 COMPONENTS Test REQUIRED)

###########################
# Targets

add_executable(${PROJECT_NAME}
# Tests
  src/test-runner.hpp
  src/test-runner.cpp
  src/main.cpp
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    src
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Qt5::Test
    advancedRayTracer-lib
)

target_compile_features(${PROJECT_NAME}
  PRIVATE
    cxx_std_14
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    AUTOMOC ON
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# cotire(${PROJECT_NAME})
