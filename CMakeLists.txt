cmake_minimum_required(VERSION 3.20)

project(Game_of_Life VERSION 1.0 LANGUAGES CXX)

# Use C++20, and fail rather than silently falling back to an older standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)   # use -std=c++20, not -std=gnu++20

add_executable(game_of_life
    src/main.cpp
    src/grid.cpp
)

target_include_directories(game_of_life PRIVATE include)

# Warnings are worth turning on while learning
if(MSVC)
    target_compile_options(game_of_life PRIVATE /W4)
else()
    target_compile_options(game_of_life PRIVATE -Wall -Wextra -Wpedantic)
endif()