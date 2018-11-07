#cmake_minimum_required(VERSION 3.12)
project(Trojuhelniky1 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -pedantic")

add_executable(Trojuhelniky1 main.c)