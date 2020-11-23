#ifndef PROJECT_TESTS_HPP
#define PROJECT_TESTS_HPP

#include "gtest/gtest.h"
#include "../src/WeightTracker.hpp"
#include "../src/HealthPlan.hpp"

TEST(bmi, normalTest) {
        double height = 5.3;
        double weight = 129.0;
        WeightTracker *bmi = new WeightTracker();
	bmi->set_height(height);
	bmi->set_weight(weight);

        EXPECT_EQ(bmi->BmiCalculator(height, weight), 23);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#endif //PROJECT_TESTS_HPP
