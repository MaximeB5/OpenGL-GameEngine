# Minimum version of CMake required to use it
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# Project name
PROJECT(GameEngine)


# Settings :
# C++ version
SET(CMAKE_CXX_STANDARD 14)

# Tell to CMake to move the .exe into the Bin folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Bin)

# Tell to CMake to link our libraries to the project
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/Lib)

# Tell to CMake where our includes are
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/ThirdParty)

# Subdirectories : Tell to CMake where our sources are
ADD_SUBDIRECTORY(GameEngine/Sources)