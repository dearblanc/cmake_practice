cmake_minimum_required(VERSION 3.2)
project(ex1)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/output/)
set(INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/outputs/)

add_subdirectory(opensource)

function(autorun_test target)
  add_executable(${target} ${ARGN})
  target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
  target_link_libraries(${target} PRIVATE gtest)

  add_custom_command(
    TARGET ${target}
    POST_BUILD
    COMMAND ${target}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running ${target}"
    VERBATIM)
endfunction()

add_subdirectory(module_a)
add_subdirectory(module_b)
add_subdirectory(main)

install(
  TARGETS main module_a module_b
  RUNTIME DESTINATION ${INSTALL_PREFIX}/bin
  LIBRARY DESTINATION ${INSTALL_PREFIX}/lib
  LIBRARY DESTINATION ${INSTALL_PREFIX}/lib)
