cmake_minimum_required(VERSION 3.20)

project(object_oriention_03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(app
    src/main.cpp src/MyArray.cpp
)

