cmake_minimum_required(VERSION 3.20)

project(vigenere LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(app
    src/main.cpp src/vigenere.cpp
)

