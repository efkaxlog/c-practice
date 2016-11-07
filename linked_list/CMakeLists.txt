cmake_minimum_required(VERSION 3.5)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

project(linked_list)

set(SOURCE_FILES main.c test.c linked_list.c)
add_executable(linked_list ${SOURCE_FILES})
