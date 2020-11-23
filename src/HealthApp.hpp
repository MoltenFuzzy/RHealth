#ifndef HEALTH_APP
#define HEALTH_APP

#include "HealthPlan.hpp"

class HealthApp
{
private:
	
public:
	HealthApp();
	// TODO: add more to 
	HealthPlan CreateExercisePlan(int age, std::string sex, double weight, double height);
	HealthPlan CreateMealPlan(int age, std::string sex, double weight, double height);
	HealthPlan CreateWeightTracker(int age, std::string sex, double weight, double height); 
	~HealthApp();
};

#endif // HEALTH_APP
