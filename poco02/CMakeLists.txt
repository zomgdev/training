cmake_minimum_required (VERSION 3.8)

find_package(Poco REQUIRED Data Foundation DataPostgreSQL)



# Add source to this project's executable.
add_executable (poco02 "poco02.cpp" "poco02.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET poco02 PROPERTY CXX_STANDARD 20)
endif()


set(POCO_PREFIX      "/usr/local") # the directory containing "include" and "lib"
set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
set(POCO_LIB_DIR     "${POCO_PREFIX}/lib")
#set(POCO_LIBS
#        "${POCO_LIB_DIR}/libPocoData.dylib"
#        "${POCO_LIB_DIR}/libPocoFoundation.dylib")


target_include_directories(poco02 PRIVATE "${POCO_INCLUDE_DIR}")
#target_link_libraries(poco01 ${POCO_LIBS})

target_link_libraries(poco02 Poco::Foundation Poco::Data Poco::DataPostgreSQL)
