cmake_minimum_required(VERSION 3.0)

set(This Main_loop)

set(Sources main_loop.cpp)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC cpptimer)