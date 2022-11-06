target_link_directories(${PROJECT_NAME} PUBLIC
 lib/detours
 lib/DX9
)

target_link_libraries(${PROJECT_NAME}
 ${PROJECT_SOURCE_DIR}/lib/detours/detours.lib
 ${PROJECT_SOURCE_DIR}/lib/DX9/d3d9.lib
 ${PROJECT_SOURCE_DIR}/lib/DX9/d3dx9.lib
)