cmake_minimum_required(VERSION 3.20)

project(weak_ptr-02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_BUILD_TYPE Debug)

add_executable(app
    src/main.cpp src/Cache.h
)

