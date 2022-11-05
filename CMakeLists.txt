cmake_minimum_required (VERSION 3.20)

project(streets)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_library(${PROJECT_NAME} SHARED)
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".asi")

add_subdirectory(include)
add_subdirectory(src)