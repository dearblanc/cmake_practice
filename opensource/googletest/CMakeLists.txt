cmake_minimum_required(VERSION 3.2)

add_library(gtest IMPORTED STATIC GLOBAL)
set_target_properties(
  gtest PROPERTIES IMPORTED_LOCATION
                   ${CMAKE_CURRENT_SOURCE_DIR}/libs/libgtest.a)
target_include_directories(gtest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(gtest_main IMPORTED STATIC GLOBAL)
set_target_properties(
  gtest_main PROPERTIES IMPORTED_LOCATION
                        ${CMAKE_CURRENT_SOURCE_DIR}/libs/libgtest_main.a)
target_include_directories(gtest_main
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
