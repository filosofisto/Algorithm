cmake_minimum_required(VERSION 3.20)

project(thread10 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(app
    src/main.cpp
)

# Link pthread (only needed if you're using threads)
find_package(Threads REQUIRED)
target_link_libraries(app PRIVATE Threads::Threads)
