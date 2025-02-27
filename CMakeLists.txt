
cmake_minimum_required(VERSION 3.10)

# Project name
project(TerraEmu)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories("terra/")

# Source files
file(GLOB SOURCES "emu/*.cpp")

# Add executable
add_executable(TerraEmu ${SOURCES})