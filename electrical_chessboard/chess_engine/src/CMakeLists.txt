# CMakeLists.txt
cmake_minimum_required(VERSION 3.14)
project(ChessEngine VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add compiler warnings
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Add the executable
add_executable(chess_engine
    main.cpp
    board.cpp
)

# Set include directories
target_include_directories(chess_engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})