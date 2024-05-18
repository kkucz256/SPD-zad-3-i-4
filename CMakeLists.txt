cmake_minimum_required(VERSION 3.27)
project(SPD_zad_3_i_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SPD_zad_3_i_4
        main.cpp
        Problem.h
        Result.h
        Task.h
        Task.cpp
        Result.cpp
        Problem.cpp)
