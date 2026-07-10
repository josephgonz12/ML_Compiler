cmake_minimum_required(VERSION 3.10)
project(ML-Compiler)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory so the compiler can find matrix.h
include_directories(include)

# Create a test executable
add_executable(test_matrix src/matrix.cpp tests/test_matrix.cpp)