cmake_minimum_required(VERSION 3.12)
project(bst)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. SRC_DIR)

add_executable(bst main.cpp ${SRC_DIR})