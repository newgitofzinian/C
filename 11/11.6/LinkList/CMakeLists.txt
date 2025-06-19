cmake_minimum_required(VERSION 3.31)
project(LinkList)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug) # 启用调试模式

add_executable(LinkList main.cpp
        ListFunc.cpp
        ListFunc.h)
