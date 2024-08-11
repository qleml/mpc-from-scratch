add_library(Controllers STATIC PIDController.cpp MPCController.cpp)
target_include_directories(Controllers PUBLIC ${PROJECT_SOURCE_DIR}/include/controllers)
