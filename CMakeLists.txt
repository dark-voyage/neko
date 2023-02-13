cmake_minimum_required(VERSION 3.24)
project(neko C)

set(CMAKE_C_STANDARD 23)

add_executable(neko main.c http.h http.c route.c route.h file.c file.h)
