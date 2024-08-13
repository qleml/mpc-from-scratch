

add_executable(main main.cpp)

target_link_libraries(main PhysicsObjects Controllers)

set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build) 