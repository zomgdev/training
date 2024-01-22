# CMakeList.txt : CMake project for training, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


add_executable (server03 "server03.c" "server03.h")


if (CMAKE_VERSION VERSION_GREATER 3.12)
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)

endif()

# Add source to this project's executable.

# TODO: Add tests and install targets if needed.
