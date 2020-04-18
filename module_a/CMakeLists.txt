cmake_minimum_required(VERSION 3.2)
project(module_a)

set(TARGET ${PROJECT_NAME})
set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})

add_library(${TARGET} SHARED module_a.hpp)
set_target_properties(${TARGET} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_library(sub::b ALIAS ${TARGET})

set(TEST_TARGET ${PROJECT_NAME}_test)
add_executable(${TEST_TARGET} module_a_test.cc)
target_include_directories(${TEST_TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${TEST_TARGET} PRIVATE sub::test sub::test_main)

set_target_properties(
  ${TARGET} ${TEST_TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                      ${CMAKE_INSTALL_PREFIX})
