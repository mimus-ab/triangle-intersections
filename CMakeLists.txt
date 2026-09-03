cmake_minimum_required(VERSION 3.10)
project(triangle_intersections)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(triangle_intersections
    main.cpp
    polygon.cpp
    SVG.cpp
)
