#include <iostream>
#include <string>

#include "HealthApp.hpp"

int main()
{

	HealthApp RHealth;

	// Testing stuff
	// HealthPlan *Exercise_Plan = RHealth.CreateExercisePlan(20, "Male", 180, 180);

	// Exercise_Plan->Print(std::cout);

	// std::cout << dynamic_cast<ExercisePlan *>(Exercise_Plan)->Search("Mile Run")->GetDesc();
	// HealthPlan *Exercise_Plan = RHealth.CreateExercisePlan(20, "Male", 80, 180);

	// ExercisePlan *test = dynamic_cast<ExercisePlan *>(Exercise_Plan)->Search("Back Squat");

	// test->Print(std::cout);

	// std::cout << test->GetDesc();

	RHealth.Run();

	return 0;
}
