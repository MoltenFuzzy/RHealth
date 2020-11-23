#ifndef PROJECT_WEIGHT_TRACKER
#define PROJECT_WEIGHT_TRACKER

#include "HealthPlan.hpp"


class WeightTracker : public HealthPlan {

private:
	/* data */
	double bmi;
public:
	/* Constructor */
	WeightTracker() : HealthPlan() { };

	double BmiCalculator(HealthPlan* height, HealthPlan* weight);
	void BmiLevel(double bmi);
	
	
};


