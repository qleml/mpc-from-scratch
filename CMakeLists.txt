cmake_minimum_required(VERSION 3.5.0)
project(mpc VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(src/physics)
add_subdirectory(src/controllers)
add_subdirectory(src/main)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)