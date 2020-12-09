#ifndef PROJECT_WEIGHT_TRACKER
#define PROJECT_WEIGHT_TRACKER

#include "HealthPlan.hpp"

using namespace std;

class WeightTracker : public HealthPlan
{

private:
	/* data */
	double bmi;

public:
	/* Constructor */
	WeightTracker() {}

	/* functions */
	void WeightTracker(int age, string sex, double weight, double height);
	void BMICalculator(double weight, double height);
};

#endif //PROJECT_WEIGHT_TRACKER
