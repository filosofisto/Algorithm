cmake_minimum_required(VERSION 3.20)

project(barrier01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(app
    src/main.cpp
)

# Always include debug symbols
target_compile_options(app PRIVATE -g)

# Link pthread (only needed if you're using threads)
find_package(Threads REQUIRED)
target_link_libraries(app PRIVATE Threads::Threads)
