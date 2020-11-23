#ifndef PROJECT_WEIGHT_TRACKER
#define PROJECT_WEIGHT_TRACKER

#include "HealthPlan.hpp"


class WeightTracker : public HealthPlan {

private:
	/* data */
	double bmi;
	double _height;
	double _weight;
public:
	/* Constructor */
	WeightTracker() : HealthPlan() { };

	/* functions */
	void set_height(double height);
	void set_weight(double weight);
	double BmiCalculator(double height, double weight);
	void BmiLevel(double bmi);
	
	
};

#endif //PROJECT_WEIGHT_TRACKER 
