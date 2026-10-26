cmake_minimum_required(VERSION 3.13)
project(MyProgram CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main main.cpp)

target_compile_options(main PRIVATE
  -Wall -Wextra -g
  -fsanitize=address,undefined
)
target_link_options(main PRIVATE
  -fsanitize=address,undefined
)
