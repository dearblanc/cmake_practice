cmake_minimum_required(VERSION 3.2)
project(ex1)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/output/)
set(INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/outputs/)

add_subdirectory(opensource)
add_subdirectory(module_a)
add_subdirectory(module_b)
add_subdirectory(main)

install(
  TARGETS main module_a module_b
  RUNTIME DESTINATION ${INSTALL_PREFIX}/bin
  LIBRARY DESTINATION ${INSTALL_PREFIX}/lib
  LIBRARY DESTINATION ${INSTALL_PREFIX}/lib)
