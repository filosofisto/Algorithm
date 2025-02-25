cmake_minimum_required(VERSION 3.20)  # CMake version must support C++20
project(Comparison LANGUAGES CXX)     # Project name and language

# Set C++20 as the standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the executable
add_executable(Comparison main.cpp)

# Include header files (optional, but good practice to list them)
target_sources(Comparison
    PRIVATE
				printarray.h
        insertionsort.h
        mergesort.h
        heapsort.h
        quicksort.h
)

# Optional: Add include directories if headers are in a subdirectory
# target_include_directories(Comparison PRIVATE include)

# Optional: Enable warnings
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(Comparison PRIVATE -Wall -Wextra -pedantic)
endif()

