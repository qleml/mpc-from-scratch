add_library(Utils STATIC Logger.cpp)
target_include_directories(Utils PUBLIC ${PROJECT_SOURCE_DIR}/include/utils)
