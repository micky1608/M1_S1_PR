cmake_minimum_required(VERSION 3.12)
project(PR_TME9)

set(CMAKE_CXX_STANDARD 14)

add_executable(PR_TME9_EX1 pr_tme9_ex1.cpp)
add_executable(PR_TME9_EX2 pr_tme9_ex2.cpp)

target_link_libraries(PR_TME9_EX1 pthread)
target_link_libraries(PR_TME9_EX2 pthread)