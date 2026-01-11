cmake_minimum_required(VERSION 3.16)
project(HulluEngine)

set(CMAKE_CXX_STANDARD 17)

# Finds the SDL3 config files installed by pacman or brew
find_package(SDL3 REQUIRED CONFIG)

add_executable(HulluEngine 
    main.cpp 
    Code/loop.cpp 
    Code/start.cpp 
    Code/render.cpp 
    Code/calculations.cpp 
    Code/inputs.cpp 
    Code/shutdown.cpp
)

# Link the library
target_link_libraries(HulluEngine PRIVATE SDL3::SDL3)