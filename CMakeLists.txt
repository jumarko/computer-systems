cmake_minimum_required(VERSION 3.14)
project(computer_systems C)

set(CMAKE_C_STANDARD 11)

add_executable(computer_systems
        ch01-tour/hello.c
        ch01-tour/hello.i
        jazyk-c/format.c
        jazyk-c/scanf.c)
