#include <iostream>
#include <string>

#include "HealthApp.hpp"

int main()
{

	HealthApp RHealth;

	// Testing stuff
	HealthPlan *ExercisePlan = RHealth.CreateExercisePlan(20, "Male", 80, 180);

	ExercisePlan->Print(std::cout);

	// RHealth.Run();

	return 0;
}