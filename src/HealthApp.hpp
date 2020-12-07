#ifndef HEALTH_APP
#define HEALTH_APP

#include "ExercisePlan.hpp"
#include "Routine.hpp"
#include "MealPlan.hpp"
#include "WeightTracker.hpp"

class HealthApp 
{
private:
	std::vector<std::string> DaysOfWeek = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

public:
	HealthApp() {}
	HealthPlan* CreateExercisePlan(int age, std::string sex, double weight, double height);
	HealthPlan* CreateMealPlan(int age, std::string sex, double weight, double height);
	HealthPlan* CreateWeightTracker(int age, std::string sex, double weight, double height);
};

#endif // HEALTH_APP
