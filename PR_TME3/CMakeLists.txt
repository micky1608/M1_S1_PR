cmake_minimum_required(VERSION 3.12)
project(PR_TME3)

set(CMAKE_CXX_STANDARD 14)

add_executable(PR_TME3 main.cpp Thread.cpp Thread.h Compte.cpp Compte.h Banque.cpp Banque.h)
target_link_libraries(PR_TME3 pthread)