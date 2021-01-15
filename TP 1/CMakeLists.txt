cmake_minimum_required(VERSION 3.17)
project(01_type)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(01_type
        .idea/01-type.iml
        .idea/modules.xml
        .idea/workspace.xml
        exo1.cpp
        exo2.cpp
        exo3.cpp
        exo4.cpp)
