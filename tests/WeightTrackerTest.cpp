#include "gtest/gtest.h"

#include "../src/WeightTracker.hpp"

TEST(CalcBMI, RegularValues)
{
	double weight = 58.95;
	double height = 160.02;
	HealthPlan* bmi = new HealthPlan();

	EXPECT_EQ(bmi->CalcBMI(weight, height), 23.02158799);
}

TEST(CalcBMI, SmallValues)
{
        double weight = 40.82;
        double height = 137.16;
        HealthPlan* bmi = new HealthPlan();

        EXPECT_EQ(bmi->CalcBMI(weight, height), 21.6979172);
}

TEST(CalcBMI, ObeseValues)
{
        double weight = 81.63;
        double height = 157.48;
        HealthPlan* bmi = new HealthPlan();

        EXPECT_EQ(bmi->CalcBMI(weight, height), 32.91538841);
}

TEST(CalcBMI, OverWeightValues)
{
        double weight = 81.63;
        double height = 175.26;
        HealthPlan* bmi = new HealthPlan();

        EXPECT_EQ(bmi->CalcBMI(weight, height), 26.57566752);
}


