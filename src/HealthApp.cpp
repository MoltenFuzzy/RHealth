#include "HealthApp.hpp"

HealthPlan* HealthApp::CreateExercisePlan(int age, std::string sex, double weight, double height) {
	// TODO: TURN POINTERS INTO SMART POINTERS

	ExercisePlan* WeeklyExercisePlan = new Routine();

	WeeklyExercisePlan->setAPIFunction(new APICaller());

	// GET EACH EXERCISE CATEGORY
	// SET URL 
	// CALL API
	// REPEAT
	std::string base_url = WeeklyExercisePlan->getBaseUrl();

	// Input the category

	//std::vector<std::string> keys = {"Abs", "Arms", "Back", "Calves", "Chest", "Legs", "Shoulders"};

	// for(auto category : WeeklyExercisePlan->getCategoryMap()) {
	// 	// getting different exercises per call
	// 	WeeklyExercisePlan->setAPIurl(base_url + category.second);
	// 	WeeklyExercisePlan->CallAPI(); 	
	// }

	
	// Increment this by 2 and then go back to front of map after it reaches end
	int indx = 0; 

	// Assigning exercises to each day
	for(auto day : DaysOfWeek) {
		Routine* DailyRoutine = new Routine();
		// load exercise data twice for each category of exercise
		// set api url then call api to set exercise data variable
		// if(it_indx == WeeklyExercisePlan->getCategoryMap().end()) 
		// 	it_indx = WeeklyExercisePlan->getCategoryMap().begin();


		// TODO: loop over the workouts from each category and add them to the DailyRoutine
		// This should be only 6 workouts from 2 parts of the body
		// TODO: add cardio later, can be just a json of 10ish cardio workouts
		// Right now i am trying to add 3 workouts from each category to 1 daily routine
		for(int i = 0; i < 2; indx++, i++) {
			WeeklyExercisePlan->setAPIurl(base_url + WeeklyExercisePlan->getCategoryMap().at(indx));
			WeeklyExercisePlan->CallAPI(); 
			DailyRoutine->AddWorkoutsFromJSON(WeeklyExercisePlan->GetExerciseData());
		}

		WeeklyExercisePlan->Add(day, DailyRoutine); 
	} 

	return WeeklyExercisePlan; 
}