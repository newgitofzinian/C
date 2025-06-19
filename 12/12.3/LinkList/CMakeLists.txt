cmake_minimum_required(VERSION 3.31)
project(LinkList)

set(CMAKE_CXX_STANDARD 20)
# Debug 配置
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -DDEBUG")

# Release 配置
#set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -DNDEBUG")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")


add_executable(LinkList main.cpp
            ListFunc.cpp
            ListFunc.h
)
