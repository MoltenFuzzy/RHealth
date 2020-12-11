#ifndef PROJECT_TESTS_HPP
#define PROJECT_TESTS_HPP

#include "gtest/gtest.h"
#include "ExercisePlanTest.cpp"
#include "WeightTrackerTest.cpp"
#include "APIHandlerTests.cpp"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#endif //PROJECT_TESTS_HPP
