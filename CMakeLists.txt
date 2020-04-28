cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled src/main.cpp src/Ocean.cpp include/Ocean.h src/Objects.cpp include/Objects.h include/common.h include/params.h)