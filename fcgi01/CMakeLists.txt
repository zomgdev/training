# CMakeList.txt : CMake project for training, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_path(FCGI_INCLUDE_DIR NAMES fastcgi.h)
find_library(FCGI_LIBRARY NAMES fcgi)

# Handle the QUIETLY and REQUIRED arguments and set FCGI_FOUND to TRUE if all listed variables are TRUE.
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FCGI DEFAULT_MSG FCGI_LIBRARY FCGI_INCLUDE_DIR)
# Copy the results to the output variables.
if(FCGI_FOUND)
    set(FCGI_LIBRARIES ${FCGI_LIBRARY})
    set(FCGI_INCLUDE_DIRS ${FCGI_INCLUDE_DIR})
else()
    set(FCGI_LIBRARIES)
    set(FCGI_INCLUDE_DIRS)
endif()
mark_as_advanced(FCGI_INCLUDE_DIR FCGI_LIBRARY)

target_include_directories(Tutorial PUBLIC FCGI_INCLUDE_DIR)
target_link_libraries

# Add source to this project's executable.
add_executable (fcgi01 "fcgi01.cpp" "fcgi01.hh")

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET fcgi01 PROPERTY CXX_STANDARD 20)
endif()




