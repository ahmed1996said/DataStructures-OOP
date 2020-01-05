cmake_minimum_required(VERSION 3.12)
project(ece309-spr19)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Werror")

add_subdirectory(gtest)
add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(app)
