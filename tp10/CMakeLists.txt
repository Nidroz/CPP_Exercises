cmake_minimum_required(VERSION 3.16)
project(TP10)

add_executable(mandelbrot
    lib/image_lib.cpp
    src/image.hpp
    src/pixels.hpp
    src/mandelbrot.cpp
)

target_compile_features(mandelbrot PRIVATE cxx_std_17)
target_compile_options(mandelbrot PRIVATE "-Wfatal-errors")