cmake_minimum_required(VERSION 3.12)
project(PR_TME4)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(PR_TME4
        src/Color.cpp
        src/Color.h
        src/main.cpp
        src/Makefile.am
        src/Rayon.h
        src/Scene.h
        src/Sphere.h
        src/Vec3D.cpp
        src/Vec3D.h
        configure.ac
        LICENSE
        Makefile.am
        README.md
        tme4.sln
        tme4.vcxproj
        tme4.vcxproj.filters
        tme4.vcxproj.user src/Queue.h src/Test.cpp src/Thread.cpp src/Thread.h src/Test.h src/Job.cpp src/Job.h src/Pool.cpp src/Pool.h src/Barrier.cpp src/Barrier.h)

target_link_libraries(PR_TME4 pthread)