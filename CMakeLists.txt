cmake_minimum_required(VERSION 3.0)

project(dsanda)

set(SOURCE_EXE test.c)
set(SOURCE_LIB algorithms.c
               linked_list.c
               queue.c
               stack.c
               graph.c
               binary_heap.c)

add_library(mainlib STATIC ${SOURCE_LIB})

add_executable(test ${SOURCE_EXE})
target_link_libraries(test mainlib)
