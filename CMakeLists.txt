cmake_minimum_required(VERSION 3.3)
project(MyConsole)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static-libgcc -static-libstdc++")

set(SOURCE_FILES main.cpp sales_data.h screen.h console.h)
add_executable(C___Primer ${SOURCE_FILES} sales_data.h screen.h console.h)