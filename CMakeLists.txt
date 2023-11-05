cmake_minimum_required(VERSION 3.14)
project(aoc2015 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

include(GoogleTest)
include(dependencies.cmake)

function(add_day day)
  add_executable(day${day}_p1 day${day}/main.cpp)
  add_executable(day${day}_p2 day${day}/main.cpp)
  target_compile_definitions(day${day}_p1 PRIVATE PART1)
  target_compile_definitions(day${day}_p2 PRIVATE PART2)

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/day${day}/test.cpp)
    add_executable(day${day}_p1_test day${day}/test.cpp)
    add_executable(day${day}_p2_test day${day}/test.cpp)
    target_compile_definitions(day${day}_p1_test PRIVATE PART1 TEST)
    target_compile_definitions(day${day}_p2_test PRIVATE PART2 TEST)
    target_link_libraries(day${day}_p1_test PRIVATE GTest::gtest_main)
    target_link_libraries(day${day}_p2_test PRIVATE GTest::gtest_main)

    gtest_discover_tests(day${day}_p1_test)
    gtest_discover_tests(day${day}_p2_test)
  endif()
endfunction()

add_day(01)
add_day(02)
add_day(03)