#include "HealthApp.hpp"

HealthPlan* HealthApp::CreateWeightTracker(int age, std::string sex, double weight, double height) {
	WeightTracker* tracker = new WeightTracker();

	tracker->BMICalculator(weight, height);

	tracker->WeightTracker(age, sex, weight, height);
	//want it to output the cout's from each function
}
