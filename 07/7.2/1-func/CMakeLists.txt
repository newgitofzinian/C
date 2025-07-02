cmake_minimum_required(VERSION 3.31)
project(1_func C)

set(CMAKE_C_STANDARD 99)

add_executable(1_func main.c
        func.c
        func.h)
