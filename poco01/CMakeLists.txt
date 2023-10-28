# CMakeList.txt : CMake project for training, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(Poco REQUIRED Foundation Data )



# Add source to this project's executable.
add_executable (poco01 "poco01.cpp" "poco01.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET poco01 PROPERTY CXX_STANDARD 20)
endif()



#set(POCO_PREFIX      "/usr/local") # the directory containing "include" and "lib"
#set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
#set(POCO_LIB_DIR     "${POCO_PREFIX}/lib")

# set the include path for the app
#target_include_directories(poco01 PUBLIC "${POCO_INCLUDE_DIR}")
# link the app against POCO
target_link_libraries(poco01 PRIVATE Poco::Data)
#target_link_directories(poco01 PUBLIC "/usr/local")