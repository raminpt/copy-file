cmake_minimum_required(VERSION 3.28)
project(file_copy C)

set(CMAKE_C_STANDARD 11)

add_executable(file_copy main.c
        file_operations.c)
