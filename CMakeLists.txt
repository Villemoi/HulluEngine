cmake_minimum_required(VERSION 3.16)
project(HulluEngine)

add_definitions(-DGLEW_STATIC)

set(CMAKE_CXX_STANDARD 17)

# Finds the SDL3 config files installed by pacman or brew
find_package(SDL3 REQUIRED CONFIG)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_executable(HulluEngine 
    main.cpp 
    Code/loop.cpp 
    Code/start.cpp 
    Code/render.cpp 
    Code/calculations.cpp 
    Code/inputs.cpp 
    Code/shutdown.cpp
    Code/Shader.cpp
    Code/Sprite.cpp
    Code/cleanup.cpp
)

# Link the library
target_link_libraries(HulluEngine 
    PRIVATE 
    SDL3::SDL3
    OpenGL::GL
    GLEW::GLEW
)