cmake_minimum_required(VERSION 3.16)
project(study_c C)

set(CMAKE_C_STANDARD 11)

add_executable(algorithm main.c)

add_executable(
        heap
        data_structures/heap/max_heap.c
)

add_executable(
        sort
        sort/main.c
        sort/sort.h
        sort/sort.c
        sort/selection.c
        sort/insertion.c
        sort/bubble.c)