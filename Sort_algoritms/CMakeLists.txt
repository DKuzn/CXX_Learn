cmake_minimum_required(VERSION 3.16)
project(CXX_Learn)

set(CMAKE_CXX_STANDARD 14)

add_executable(bubble_sort ./bubble_sort.cpp)
add_executable(gnome_sort ./gnome_sort.cpp)
add_executable(insertion_sort ./insertion_sort.cpp)
add_executable(merge_sort ./merge_sort.cpp)
add_executable(opt_gnome_sort ./opt_gnome_sort.cpp)