cmake_minimum_required(VERSION 3.12)
project(PR_TME7)

set(CMAKE_CXX_STANDARD 14)

add_executable(PR_TME7 main.cpp Socket.h ServerSocket.h server.cpp server.h Socket.cpp client.cpp client.h)