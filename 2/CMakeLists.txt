cmake_minimum_required(VERSION 3.21)
project(2)

set(CMAKE_CXX_STANDARD 14)

add_executable(2 main.cpp IGraph.h ListGraph.cpp ListGraph.h MatrixGraph.cpp MatrixGraph.h)
