cmake_minimum_required(VERSION 3.14)
project(aoc2015 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

include(GoogleTest)
include(dependencies.cmake)

function(add_day day)
  add_custom_target(day${day})

  add_executable(day${day}_p1 day${day}/main.cpp)
  add_executable(day${day}_p2 day${day}/main.cpp)
  target_compile_definitions(day${day}_p1 PRIVATE PART1)
  target_compile_definitions(day${day}_p2 PRIVATE PART2)
  target_link_libraries(day${day}_p1 PRIVATE utils)
  target_link_libraries(day${day}_p2 PRIVATE utils)

  add_dependencies(day${day} day${day}_p1 day${day}_p2)

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/day${day}/test.cpp)
    add_executable(day${day}_p1_test day${day}/test.cpp)
    add_executable(day${day}_p2_test day${day}/test.cpp)
    target_compile_definitions(day${day}_p1_test PRIVATE PART1 TEST)
    target_compile_definitions(day${day}_p2_test PRIVATE PART2 TEST)
    target_link_libraries(day${day}_p1_test PRIVATE utils GTest::gtest_main)
    target_link_libraries(day${day}_p2_test PRIVATE utils GTest::gtest_main)

    gtest_discover_tests(day${day}_p1_test)
    gtest_discover_tests(day${day}_p2_test)

    add_dependencies(day${day} day${day}_p1_test day${day}_p2_test)
  endif()
endfunction()

function(link_additional_libs day libs)
  target_link_libraries(day${day}_p1 PRIVATE ${libs})
  target_link_libraries(day${day}_p2 PRIVATE ${libs})
  target_link_libraries(day${day}_p1_test PRIVATE ${libs})
  target_link_libraries(day${day}_p2_test PRIVATE ${libs})
endfunction()

add_day(01)
add_day(02)
add_day(03)
add_day(04)
link_additional_libs(04 md5)

if(OpenMP_CXX_FOUND)
  link_additional_libs(04 OpenMP::OpenMP_CXX)
endif()

add_day(05)
add_day(06)
add_day(07)
add_day(08)
add_day(10)
add_day(11)
add_day(12)
