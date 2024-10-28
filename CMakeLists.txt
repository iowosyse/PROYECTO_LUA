cmake_minimum_required(VERSION 3.29)
project(PROYECTO_LUA C)

set(CMAKE_C_STANDARD 23)

add_executable(PROYECTO_LUA main.c
               utilidades/myList.h
               utilidades/myList.c)
