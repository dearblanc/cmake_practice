cmake_minimum_required(VERSION 3.2)
project(module_a)

set(TARGET ${PROJECT_NAME})
set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})

add_library(${TARGET} SHARED src/module_a.cc)
target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(sub::b ALIAS ${TARGET})

set(TEST_TARGET ${PROJECT_NAME}_test)
autorun_test(${TEST_TARGET} src/module_a_test.cc src/module_a.cc)
generate_coverage(${TEST_TARGET})

set_target_properties(
  ${TARGET} ${TEST_TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                      ${CMAKE_INSTALL_PREFIX})
