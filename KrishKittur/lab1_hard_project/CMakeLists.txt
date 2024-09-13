cmake_minimum_required(VERSION 3.10)
project(Lab1_Hard_Project)

add_executable(Lab1_Hard src/main.cpp)
add_library(Lab1_Hard_Lib src/hello_world.cpp include/hello_world.hpp)
target_include_directories(Lab1_Hard_Lib PUBLIC include)

target_link_libraries(Lab1_Hard PUBLIC Lab1_Hard_Lib)
