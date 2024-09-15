cmake_minimum_required(VERSION 3.12)

project(Lab2_Part3_Project)

find_package(hellolib REQUIRED)

add_executable(helloapp main.cpp)

target_link_libraries(helloapp PUBLIC hellolib::hellolib)

install(TARGETS helloapp
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)