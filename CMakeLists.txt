cmake_minimum_required(VERSION 3.17)
project(competitive_programming)

set(CMAKE_CXX_STANDARD 17)

add_executable(competitive_programming main.cpp)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,undefined")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address,undefined")
add_definitions(-DLOCAL -Wall -ggdb3)
add_executable(ATask solves/tasks/ATask/ATask.cpp)
set_target_properties(ATask PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/solves/tasks/ATask/")