cmake_minimum_required(VERSION 3.10)
project(learnnix)

add_library(hello_lib STATIC src/hellolib.cpp)

target_include_directories(hello_lib PUBLIC include)

add_executable(learn_nix src/main.cpp)

target_link_libraries(learn_nix PRIVATE hello_lib)
install(TARGETS learn_nix DESTINATION ${CMAKE_INSTALL_BINDIR})