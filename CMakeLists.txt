cmake_minimum_required(VERSION 3.0)

project(dsanda)

add_subdirectory(lib)
set(SOURCE_EXE test.c)

add_executable(test ${SOURCE_EXE})
target_link_libraries(test algorithms)
target_include_directories(test PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )
