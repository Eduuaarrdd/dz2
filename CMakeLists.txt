cmake_minimum_required(VERSION 3.0.0)
project(hw2 VERSION 0.1.0)

add_executable(hw2 src/main.cpp src/func.cpp src/class.cpp) 
target_include_directories(hw2 PUBLIC include)
