cmake_minimum_required(VERSION 3.24)
project(MPI_Sorting)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_HEADERS numberGenerator.h sortingAlgorithms.h)
set(PROJECT_SOURCES main.cpp numberGenerator.cpp sortingAlgorithms.cpp)
add_executable(MPI_Sorting ${PROJECT_HEADERS} ${PROJECT_SOURCES})
