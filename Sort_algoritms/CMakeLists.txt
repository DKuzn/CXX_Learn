cmake_minimum_required(VERSION 3.16)
project(CXX_Learn)

set(CMAKE_CXX_STANDARD 14)

add_executable(bubble_sort ./bubble_sort.cpp)
add_executable(gnome_sort ./gnome_sort.cpp)
add_executable(insertion_sort ./insertion_sort.cpp)
add_executable(merge_sort ./merge_sort.cpp)
add_executable(opt_gnome_sort ./opt_gnome_sort.cpp)
add_executable(quick_sort ./quick_sort.cpp)
add_executable(selection_sort ./selection_sort.cpp)
add_executable(shaker_sort ./shaker_sort.cpp)
add_executable(shell_sort ./shell_sort.cpp)