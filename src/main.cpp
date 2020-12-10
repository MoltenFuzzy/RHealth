#include <iostream>
#include <string>

#include "HealthApp.hpp"

int main()
{

	HealthApp RHealth;

	// Testing stuff
	HealthPlan *Exercise_Plan = RHealth.CreateExercisePlan(20, "Male", 80, 180);

	ExercisePlan *test = dynamic_cast<ExercisePlan *>(Exercise_Plan);

	test->Print(std::cout);
	test->Search("Calf Raises");
	std::cout << test->GetDesc();

	// RHealth.Run();

	return 0;
}
