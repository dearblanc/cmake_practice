cmake_minimum_required(VERSION 3.2)

add_library(gtest IMPORTED SHARED GLOBAL)
set_target_properties(
  gtest PROPERTIES IMPORTED_LOCATION
                   ${CMAKE_CURRENT_SOURCE_DIR}/libs/linux/libgtest.so)
target_include_directories(gtest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
