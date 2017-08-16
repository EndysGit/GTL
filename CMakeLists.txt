cmake_minimum_required(VERSION 3.7)
project(GTL)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp GsVector.h GsArray.h GsIterator.h GsStack.h)
add_executable(GTL ${SOURCE_FILES} GsVector.h GsArray.h GsIterator.h GsStack.h)