cmake_minimum_required(VERSION 3.19)
project(histogram)

set(CMAKE_CXX_STANDARD 20)

add_executable(histogram main.cpp Histogram.cpp Histogram.h Logger.cpp Logger.h)