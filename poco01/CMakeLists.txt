# CMakeList.txt : CMake project for training, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(Poco REQUIRED Data Foundation DataSQLite )



# Add source to this project's executable.
add_executable (poco01 "poco01.cpp" "poco01.h")

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#    set_property(TARGET poco01 PROPERTY CXX_STANDARD 20)
#endif()

#add_subdirectory(Poco)



#set(POCO_PREFIX      "/usr/local") # the directory containing "include" and "lib"
#set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
#set(POCO_LIB_DIR     "${POCO_PREFIX}/lib")
#set(POCO_LIBS
#        "${POCO_LIB_DIR}/libPocoData.dylib"
#        "${POCO_LIB_DIR}/libPocoFoundation.dylib")

#target_include_directories(poco01 PRIVATE "${POCO_INCLUDE_DIR}")
#target_link_libraries(poco01 ${POCO_LIBS})

target_link_libraries(poco01 Poco::Foundation Poco::Data Poco::DataSQLite)
