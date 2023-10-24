# CMakeList.txt : CMake project for training, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


add_executable (server02 "server02.cpp" "server02.h" ../scratches/scratches.cpp ../scratches/scratches.h)

add_executable (server02cli "server02cli.cpp" "server02cli.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)

    set_property(TARGET server02 PROPERTY CXX_STANDARD 20)
    target_link_libraries(server02 PRIVATE Threads::Threads)

    set_property(TARGET server02cli PROPERTY CXX_STANDARD 20)
    target_link_libraries(server02cli PRIVATE Threads::Threads)
endif()

# Add source to this project's executable.

# TODO: Add tests and install targets if needed.
