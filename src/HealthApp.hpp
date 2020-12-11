#ifndef HEALTH_APP
#define HEALTH_APP

#include "ExercisePlan.hpp"
#include "Routine.hpp"
#include "MealPlan.hpp"
#include "Meals.hpp"
#include "WeightTracker.hpp"
#include "APICaller.hpp"

class HealthApp
{
private:
	std::vector<std::string> DaysOfWeek = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
	void PrintInterface();
	void MealPlanInterface(int age, std::string sex, double weight, double height);

public:
	HealthApp() {}

	void Run();

	// TODO: add more methods
	// All these values should be metric
	HealthPlan *CreateExercisePlan(int age, std::string sex, double weight, double height);
	HealthPlan *CreateMealPlan(int age, std::string sex, double weight, double height);
	HealthPlan *CreateWeightTracker(int age, std::string sex, double weight, double height);
};

#endif // HEALTH_APP
