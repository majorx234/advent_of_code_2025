cmake_minimum_required(VERSION 3.16)
project(day02)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOLUTION_2_1_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/solution2.1.c
)
add_executable(solution2.1)
target_sources(solution2.1
 PRIVATE
  ${SOLUTION_2_1_SOURCES}
)
target_include_directories(solution2.1
 PRIVATE
  include
)
target_link_libraries(solution2.1
 PRIVATE
  m
)

set(SOLUTION_2_2_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/solution2.2.c
)
add_executable(solution2.2)
target_sources(solution2.2
 PRIVATE
  ${SOLUTION_2_2_SOURCES}
)
target_include_directories(solution2.2
 PRIVATE
  include
)
target_link_libraries(solution2.2
 PRIVATE
  m
)
