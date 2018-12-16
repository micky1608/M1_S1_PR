cmake_minimum_required(VERSION 3.12)
project(tme5_micky1608)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(tme5_micky1608
        src/Battle.cpp
        src/Battle.h
        src/fork_exo.cpp.
        src/main.cpp
        src/rsleep.cpp
        src/rsleep.h src/Wait.cpp src/Wait.h)
