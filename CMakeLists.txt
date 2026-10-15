cmake_minimum_required(VERSION 3.28)                                   # Minimum version required for CMake

project(Project01 LANGUAGES CXX)                                       # Give name to the project and indicates that it's in C++ (CXX = C++ for CMake)

set(CMAKE_CXX_STANDARD 20)                                             # We want C++ 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)                                    # If the compiler doesn't support C++ 20, CMake will use an old version
set(CMAKE_CXX_EXTENSIONS OFF)                                          # g++ has his own extensions non-standard, so we deactivate them so we write pure C++

include(FetchContent)                                                  # Activate the module FetchContent, which is not by default

FetchContent_Declare(SFML                                              # Fetch.._Declare(...) : Describe where to find SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0                                                      # version (MUST FIX A VERSION or the project could break)
    GIT_SHALLOW ON                                                     # only download this version (way faster)
    EXCLUDE_FROM_ALL                                                   # compiles only the parts that is being used in the project
    SYSTEM                                                             # display only warnings from the code of SFML
)
FetchContent_MakeAvailable(SFML)                                       # download and prepare SFML

add_executable(Project01 src/main.cpp)                                 # "Create a program named Project01 with these files" they are called "target" in CMake

target_compile_options(Project01 PRIVATE -Wall -Wextra -Wpedantic)     # Activate the compiler's warnings
target_link_libraries(Project01 PRIVATE SFML::Graphics)                # tells the linker to include the graphic module of SFML in the program
