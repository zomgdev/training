# CMakeList.txt : CMake project for training, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (socket_client01 "socket_client01.cpp" "socket_client01.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET socket_client01 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
