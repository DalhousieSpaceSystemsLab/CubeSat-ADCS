cmake_minimum_required(VERSION 3.0)

set(This Main_loop)

set(Sources main_loop.cpp)

add_executable(${This} ${Sources})

target_include_directories(SunVector PUBLIC /usr/include/eigen3)