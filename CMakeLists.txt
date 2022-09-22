# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("learning")

# Include sub-projects.
add_subdirectory ("training")
add_subdirectory ("struct01")
add_subdirectory ("fstream01")
