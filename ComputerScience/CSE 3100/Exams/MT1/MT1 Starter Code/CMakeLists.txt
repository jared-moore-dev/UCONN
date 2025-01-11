cmake_minimum_required(VERSION 3.20)
project(MT1 C)

set(CMAKE_C_STANDARD 11)

add_executable(hamming hamming.c hammingCode.c hamming.h) #finished