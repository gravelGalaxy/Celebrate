cmake_minimum_required(VERSION 3.26)
project(Celebrate)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Celebrate
        ascii_image_generator.cpp
        ascii_image_generator.h
        main.cpp
        image.cpp
        image.h
        lodepng.h
        lodepng.cpp)
