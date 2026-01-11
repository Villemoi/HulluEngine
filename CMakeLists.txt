cmake_minimum_required(VERSION 3.16)
project(MySDL3App)

set(CMAKE_CXX_STANDARD 17)

# Finds the SDL3 config files installed by pacman or brew
find_package(SDL3 REQUIRED CONFIG)

add_executable(MySDLApp main.cpp)

# Link the library
target_link_libraries(MySDLApp PRIVATE SDL3::SDL3)