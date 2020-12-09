#ifndef PROJECT_WEIGHT_TRACKER
#define PROJECT_WEIGHT_TRACKER

#include "HealthPlan.hpp"

using namespace std;

class WeightTracker : public HealthPlan
{
private:
public:
	/* Constructor */
	WeightTracker() {}
	WeightTracker(int age, string sex, double weight, double height) : HealthPlan(age, sex, weight, height) {}

	void DisplayWeightStatus();
	void GiveHealthAdvice();
};

#endif //PROJECT_WEIGHT_TRACKER
