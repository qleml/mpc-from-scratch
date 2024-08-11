add_library(MassSpringDamper STATIC MassSpringDamper.cpp Simulation.cpp)
target_include_directories(MassSpringDamper PUBLIC ${PROJECT_SOURCE_DIR}/include/physics)
