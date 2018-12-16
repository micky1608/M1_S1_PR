cmake_minimum_required(VERSION 3.12)
project(PR_TME6)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(PR_TME6
        src/chat_common.h
        src/prod_cons.cpp
        src/Stack.h src/Shell.cpp)

target_link_libraries(PR_TME6 pthread rt)