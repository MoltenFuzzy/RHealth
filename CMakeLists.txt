
cmake_minimum_required(VERSION 3.10)

set(JSON_BuildTests OFF CACHE INTERNAL "")

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")


PROJECT(Rhealth)

find_package(CURL CONFIG REQUIRED)
find_package(unofficial-curlpp CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
    

#ADD_SUBDIRECTORY(lib/googletest)
ADD_SUBDIRECTORY(lib/json)
#ADD_SUBDIRECTORY(lib/curlpp)


SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main
    src/main.cpp
    src/WeightTracker.hpp
    src/HealthPlan.hpp
    src/ExercisePlan.cpp
    src/HealthPlan.hpp
)

ADD_EXECUTABLE(test
    tests/unit_test.cpp
    src/WeightTracker.hpp
    src/HealthPlan.hpp
    src/ExercisePlan.cpp
    src/HealthApp.cpp
)


TARGET_LINK_LIBRARIES(Rhealth PRIVATE nlohmann_json::nlohmann_json)
TARGET_LINK_LIBRARIES(Rhealth PRIVATE unofficial::curlpp::curlpp)
TARGET_LINK_LIBRARIES(Rhealth PRIVATE CURL::libcurl)

TARGET_LINK_LIBRARIES(test PRIVATE nlohmann_json::nlohmann_json)
TARGET_LINK_LIBRARIES(test PRIVATE unofficial::curlpp::curlpp)
TARGET_LINK_LIBRARIES(test PRIVATE CURL::libcurl)
    
target_link_libraries(test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

