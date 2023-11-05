cmake_minimum_required(VERSION 3.14)
project(aoc2015 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(add_day day)
  add_executable(day${day}_p1 day${day}/main.cpp)
  add_executable(day${day}_p2 day${day}/main.cpp)
  target_compile_definitions(day${day}_p1 PRIVATE PART1)
  target_compile_definitions(day${day}_p2 PRIVATE PART2)
endfunction()

add_day(01)
add_day(02)