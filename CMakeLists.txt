
add_subdirectory(Matrix_Operations)


cmake_minimum_required(VERSION 3.25)
project(Matrix VERSION 1.0)

set(CMAKE_C_STANDARD 23)

add_executable(Matrix main.c)



INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/Matrix_Operations")
TARGET_LINK_LIBRARIES(Matrix PUBLIC Matrix_Operations)