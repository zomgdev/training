# CMakeList.txt : CMake project for training, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)





# Add source to this project's executable.
add_executable (poco01 "poco01.cpp" "poco01.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET poco01 PROPERTY CXX_STANDARD 20)
endif()


find_package(Poco CONFIG REQUIRED Data)
include_directories("/usr/local/include")
#target_link_libraries(poco01 "/usr/local/lib")

# TODO: Add tests and install targets if needed.
