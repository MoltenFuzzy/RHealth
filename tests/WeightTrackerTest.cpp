#include "gtest/gtest.h"

#include "../src/WeightTracker.hpp"

TEST(CalcBMI, RegularValues)
{
	double weight = 58.95;
	double height = 5.25;
	HealthPlan* bmi = new HealthPlan();

	EXPECT_EQ(bmi->CalcBMI(height, weight), 23);
}




