﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("learning")

# Include sub-projects.
add_subdirectory ("training")
add_subdirectory ("struct01")
add_subdirectory ("fstream01")
add_subdirectory ("daemon01")
add_subdirectory ("socket_server01")
add_subdirectory ("server01")
#add_subdirectory ("server02")
add_subdirectory ("scratches")
#add_subdirectory ("poco01")
#add_subdirectory ("poco02")
add_subdirectory ("server03")