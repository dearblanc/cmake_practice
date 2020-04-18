cmake_minimum_required(VERSION 3.2)
project(main)

set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})

set(TARGET ${PROJECT_NAME})
set(SRC src/echo.cc src/main.cpp)
add_executable(${TARGET} ${SRC})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                           ${CMAKE_INSTALL_PREFIX})
target_link_libraries(
  ${TARGET}
  PRIVATE sub::a
  PRIVATE sub::b
  PRIVATE sub::test)

