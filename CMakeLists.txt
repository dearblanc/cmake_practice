cmake_minimum_required(VERSION 3.2)
project(ex1)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/output/)

add_subdirectory(opensource)

function(autorun_test target)
  add_executable(${target} ${ARGN})
  target_include_directories(${target}
                             PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
  target_link_libraries(${target} PRIVATE gtest)

  add_custom_command(
    TARGET ${target}
    POST_BUILD
    COMMAND ${target}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running ${target}"
    VERBATIM)
endfunction(autorun_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
function(generate_coverage target)
  add_custom_command(
    TARGET ${target}
    POST_BUILD
    COMMAND echo "=================== LCOV ===================="
    COMMAND echo "-- Passing lcov tool under code coverage"
    COMMAND lcov --capture --directory ../ --output-file main_coverage.info
    COMMAND echo "-- Generating HTML output files"
    COMMAND genhtml main_coverage.info --output-directory lcoverage
    COMMENT "lcov for ${target}..."
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    VERBATIM)
endfunction(generate_coverage)

add_subdirectory(module_a)
add_subdirectory(module_b)
add_subdirectory(main)
