cmake_minimum_required(VERSION 3.7)
project(GTL)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14  -framework OpenGL")

set(SOURCE_FILES source/src/main.cpp source/headers/GsVector.h source/headers/GsArray.h source/headers/GsIterator.h source/headers/GsStack.h source/headers/IGsException.h source/src/IGsException.cpp)
add_executable(GTL ${SOURCE_FILES} source/headers/GsVector.h source/headers/GsArray.h source/headers/GsIterator.h source/headers/GsStack.h source/src/IGsException.cpp)
