cmake_minimum_required(VERSION 3.24)

project(lab3 LANGUAGES CXX)

find_package(Protobuf REQUIRED)

add_library(udp_socket STATIC src/udp_socket.cpp)
target_include_directories(udp_socket PUBLIC include)

add_library(message STATIC src/message.pb.cc)
target_include_directories(message PUBLIC include)

target_link_libraries(message PUBLIC protobuf::libprotobuf)
target_link_libraries(udp_socket PUBLIC message)

add_executable(server src/server.cpp)
target_link_libraries(server PUBLIC udp_socket)
target_link_libraries(server PUBLIC message) 

add_executable(client src/client.cpp)
target_link_libraries(client PUBLIC udp_socket)
target_link_libraries(client PUBLIC message)

install(TARGETS client server RUNTIME DESTINATION bin)