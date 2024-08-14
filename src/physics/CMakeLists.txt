add_library(
    PhysicsObjects 
    STATIC PhysicsObject.cpp 
    MassSpringDamper.cpp 
    Simulator.cpp
    Renderer.cpp
    )

set(SFML_DIR "/usr/local/lib/cmake/SFML")
set(CMAKE_FIND_FRAMEWORK "LAST")

find_package(SFML 2 COMPONENTS graphics REQUIRED)

target_include_directories(
    PhysicsObjects 
    PRIVATE 
    ${SFML_INCLUDE_DIRS}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include/physics 
    )

target_link_libraries(
    PhysicsObjects
    Utils
    sfml-graphics
    )

