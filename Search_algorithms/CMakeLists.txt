cmake_minimum_required(VERSION 3.16)
project(CXX_Learn)

set(CMAKE_CXX_STANDARD 14)

add_executable(linear_search ./linear_search.cpp)
add_executable(binary_search ./binary_search.cpp)
add_executable(interpolation_search ./interpolation_search.cpp)
add_executable(fibonaccian_search ./fibonaccian_search.cpp)