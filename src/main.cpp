#include <iostream>
#include "HealthApp.hpp"
#include "ExercisePlan.hpp"
#include "Routine.hpp"
#include "Workout.hpp"

int main()
{	
	HealthApp rhealth;  
	HealthPlan* ExercisePlan = rhealth.CreateExercisePlan(20, "Male", 160, 180);

	ExercisePlan->Print(); 

	return 0;
}
