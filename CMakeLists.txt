
cmake_minimum_required(VERSION 3.10)

PROJECT(Rhealth)

# Typically you don't care so much for a third party library's tests to be
# run from your own project's code.
set(JSON_BuildTests OFF CACHE INTERNAL "")

#find_package(CURL REQUIRED) 

ADD_SUBDIRECTORY(lib/googletest)
ADD_SUBDIRECTORY(lib/json)
#ADD_SUBDIRECTORY(lib/curlpp)
ADD_SUBDIRECTORY(lib/vcpkg/toolsrc)


SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(Rhealth
    src/main.cpp
)

ADD_EXECUTABLE(test
    tests/unit_test.cpp
)


TARGET_LINK_LIBRARIES(Rhealth PRIVATE nlohmann_json::nlohmann_json)
#TARGET_LINK_LIBRARIES(Rhealth curlpp)
#TARGET_LINK_LIBRARIES(Rhealth vcpkg)
#TARGET_LINK_LIBRARIES(Rhealth PRIVATE CURL::libcurl)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)