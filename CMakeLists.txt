cmake_minimum_required(VERSION 3.28)                                   # Minimum version required for CMake

project(Project01 LANGUAGES CXX)                                       # Give name to the project and indicates that it's in C++ (CXX = C++ for CMake)

set(CMAKE_CXX_STANDARD 20)                                             # We want C++ 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)                                    # If the compiler doesn't support C++ 20, CMake will use an old version
set(CMAKE_CXX_EXTENSIONS OFF)                                          # g++ has his own extensions non-standard, so we deactivate them so we write pure C++

add_executable(Project01 src/main.cpp)                                 # "Create a program named Project01 with these files" they are called "target" in CMake

target_compile_options(Project01 PRIVATE -Wall -Wextra -Wpedantic)     # Activate the compiler's warnings