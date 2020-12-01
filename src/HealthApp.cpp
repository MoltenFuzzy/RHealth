#include "HealthApp.hpp"

HealthPlan* HealthApp::CreateExercisePlan(int age, std::string sex, double weight, double height) {
	// TODO: PUT IN CREATE WEEKLY EXERCISES FUNCTION
	// TODO: TURN POINTERS INTO SMART POINTERS

	ExercisePlan* WeeklyExercisePlan = new Routine();

	// TODO: Create API interface class to handle API calls for different subclasses
	//WeeklyExercisePlan->SendAPIRequest();
	WeeklyExercisePlan->setAPIFunction(new APICaller());
	WeeklyExercisePlan->CallAPI(); 

	// Assigning exercises to each day
	for(auto day : DaysOfWeek) {
		Routine* DailyRoutine = new Routine();
		DailyRoutine->AddWorkoutsFromJSON(WeeklyExercisePlan->GetExerciseData());
		WeeklyExercisePlan->Add(day, DailyRoutine); 
	} 

	return WeeklyExercisePlan; 
}