#ifndef HEALTH_APP
#define HEALTH_APP

#include "ExercisePlan.hpp"
#include "DailyExercise.hpp"
#include "MealPlan.hpp"
#include "WeightTracker.hpp"

class HealthApp
{
private:
	
public:
	HealthApp() {}
	// TODO: add more methods
	// All these values should be metric
	HealthPlan* CreateExercisePlan(int age, std::string sex, double weight, double height);
	HealthPlan* CreateMealPlan(int age, std::string sex, double weight, double height);
	HealthPlan* CreateWeightTracker(int age, std::string sex, double weight, double height); 
};

#endif // HEALTH_APP
