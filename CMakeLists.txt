cmake_minimum_required(VERSION 3.20)
project(5e C)

set(CMAKE_C_STANDARD 11)

add_executable(5e main.c string/string_/string_.c string/string_/string_.h)

add_subdirectory(string)
target_link_libraries(5e string_)