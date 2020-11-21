
cmake_minimum_required(VERSION 3.10)

PROJECT(Rhealth)

ADD_SUBDIRECTORY(lib/googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(Rhealth
    src/main.cpp
)

ADD_EXECUTABLE(test
    tests/unit_test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)