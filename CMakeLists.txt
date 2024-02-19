cmake_minimum_required(VERSION 3.27)
project(Projects)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projects main.cpp
        degree.h
        Student.h
        Student.cpp
        Roster.cpp
        Roster.h)
