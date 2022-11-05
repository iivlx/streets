cmake_minimum_required (VERSION 3.20)

project(streets)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_library(${PROJECT_NAME} SHARED)

add_subdirectory(include)
add_subdirectory(src)