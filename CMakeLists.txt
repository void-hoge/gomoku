cmake_minimum_required(VERSION 3.10)
project(gomoku CXX)
set(CMAKE_CXX_FLAGS "-std=c++14 -O3 -mtune=native -march=native")
add_executable(a.out main.cpp board.cpp)
