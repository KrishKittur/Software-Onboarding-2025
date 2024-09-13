cmake_minimum_required(VERSION 3.10)
project(learnnix)

add_library(hello_lib STATIC src/hellolip.cpp)

target_include_directories(hello_lib PUBLIC include)

add_executable(hello_exe src/main.cpp)

target_link_libraries(hello_exe PRIVATE hello_lib)
install(TARGETS hello_exe DESTINATION ${CMAKE_INSTALL_BINDIR})