cmake_minimum_required(VERSION 3.31)
project(DynamicSeqenceList)

set(CMAKE_CXX_STANDARD 20)

add_executable(DynamicSeqenceList main.cpp
        dynamic_seq_list.cpp
        dynamic_seq_list.h)
