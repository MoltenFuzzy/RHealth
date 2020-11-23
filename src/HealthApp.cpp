#include "HealthApp.hpp"

HealthPlan* HealthApp::CreateExercisePlan(int age, std::string sex, double weight, double height) {
	// TODO: PUT IN CREATE WEEKLY EXERCISES FUNCTION

	DailyExercise* de = new DailyExercise(); 
	ExercisePlan* WeeklyExercisePlan = new ExercisePlan(age, sex, weight, height); 
	
	// Create daily exercises
	de->CreateDailyExercises();

	std::vector<std::string> DaysOfWeek = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

	// Assigning exercises to each day
	for(auto day : DaysOfWeek) {
		WeeklyExercisePlan->GetWeeklyExercises().insert(std::make_pair(day, de->GetDailyExercises()));
	} 

	return WeeklyExercisePlan; 
}