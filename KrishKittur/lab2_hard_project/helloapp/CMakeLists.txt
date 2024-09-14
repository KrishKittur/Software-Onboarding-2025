cmake_minimum_required(VERSION 3.10)
project(helloapp)

find_package(hellolib REQUIRED)

add_executable(helloapp main.cpp)

target_link_libraries(helloapp PRIVATE hellolib::hellolib)

install(TARGETS helloapp
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)