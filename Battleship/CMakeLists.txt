﻿# CMakeList.txt : CMake project for Battleship, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Battleship "main.cpp" "Battleship.h" "Battleship.cpp" "console.h" "console.cpp" "Ship.h" "Ship.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Battleship PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
