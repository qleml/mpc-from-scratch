add_library(PhysicsObjects STATIC PhysicsObject.cpp MassSpringDamper.cpp Simulator.cpp)
target_link_libraries(PhysicsObjects PRIVATE Utils)
target_include_directories(PhysicsObjects PUBLIC ${PROJECT_SOURCE_DIR}/include/physics)
