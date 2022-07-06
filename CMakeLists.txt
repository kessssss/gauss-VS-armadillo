cmake_minimum_required(VERSION 3.17)
project(GAUSS)

set(CMAKE_CXX_STANDARD 14)

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)
find_package(Armadillo REQUIRED)
include(local.cmake OPTIONAL)

add_executable(untitled main.cpp print.h gauss_func.h print.cpp gauss_func.cpp fill.cpp fill.h)