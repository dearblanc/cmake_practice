cmake_minimum_required(VERSION 3.2)
project(module_b)

set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})

set(TARGET ${PROJECT_NAME})
set(SRC src/module_b1.cc src/module_b2.cc)
add_library(${TARGET} SHARED ${SRC})
target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(sub::a ALIAS ${TARGET})

set(TEST_TARGET ${PROJECT_NAME}_test)
set(TEST_SRC src/module_b_test.cc src/module_b1_test.cc src/module_b2_test.cc)
autorun_test(${TEST_TARGET} ${SRC} ${TEST_SRC})
generate_coverage(${TEST_TARGET})

set_target_properties(
  ${TARGET} ${TEST_TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                      ${CMAKE_INSTALL_PREFIX})
