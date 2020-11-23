#ifndef FINAL_PROJECTTESTS_HPP
#define FINAL_PROJECTTESTS_HPP

#include "gtest/gtest.h"
#include "WeightTracker.hpp"

Test(bmi, normalTest) {
	std::double height = 5.3;
	std::double weight = 129.0;
	WeightTracker *bmi = new WeightTracker();
	
	EXPECT_EQ(bmi->BmiCalculator(height, weight), 23);
}


#endif //FINAL_PROJECTTESTS_HPP
