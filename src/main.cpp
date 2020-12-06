#include <iostream>
#include "HealthApp.hpp"
#include "ExercisePlan.hpp"

int main()
{	
	/*
	DISCLAIMER: 
	BMI is not used for muscle builders, long distance athletes, pregnant women, the elderly or young children. 
	This is because BMI does not take into account whether the weight is carried as muscle or fat, just the number. 
	Those with a higher muscle mass, such as athletes, may have a high BMI but not be at greater health risk. 
	Those with a lower muscle mass, such as children who have not completed their growth or the elderly who may be losing some muscle mass may have a lower BMI. 
	During pregnancy and lactation, a woman's body composition changes, so using BMI is not appropriate.
	*/

	HealthApp rhealth;  

	// NOTE: Enter as standard, convert to metric
	HealthPlan* ExercisePlan = rhealth.CreateExercisePlan(20, "Male", 80, 180);

	ExercisePlan->Print(); 

	return 0;
}
