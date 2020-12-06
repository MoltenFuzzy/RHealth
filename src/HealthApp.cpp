#include "HealthApp.hpp"

HealthPlan* HealthApp::CreateExercisePlan(int age, std::string sex, double weight, double height) {
	// TODO: PUT IN CREATE WEEKLY EXERCISES FUNCTION
	// TODO: TURN POINTERS INTO SMART POINTERS

	ExercisePlan* WeeklyExercisePlan = new Routine();

	// TODO: Create API interface class to handle API calls for different subclasses
	//WeeklyExercisePlan->SendAPIRequest();
	WeeklyExercisePlan->setAPIFunction(new APICaller());

	// Set url to each 2 different types of exercises
	// "https://wger.de/api/v2/exercise/?language=2&limit=" + result_limit + "&category=" + Abs; 
	// then call API to get JSON and add it daily routine, then add daily routine to weekly

	json Categories = WeeklyExercisePlan->getCategories(); 

	int index {0};
	for (const auto& day : DaysOfWeek) {
			std::string rest_day = "sunday"; 
			// skipping rest day
			if(day == rest_day) continue; 

			Routine* DailyRoutine = new Routine();

			auto firstCategory { Categories.begin() + index };
			auto secondCategory { Categories.begin() + index + 1 };

			if (secondCategory == Categories.end()) {
				secondCategory = Categories.begin();
			}
			index = (index + 2) % Categories.size();

			// converting the int(id) to string
			std::string first_category_id = to_string((*firstCategory)["id"]); 
			std::string second_category_id = to_string((*secondCategory)["id"]); 

			// These functions take a long time to call
			// TODO: Optimize so that maybe only 1 or 2 calls are needed opposed to 2 * 7 = 14
			WeeklyExercisePlan->setAPIurl(WeeklyExercisePlan->getExerciseUrl() + first_category_id); 
			WeeklyExercisePlan->SetExerciseData(WeeklyExercisePlan->CallAPI());
			DailyRoutine->AddWorkoutsFromJSON(WeeklyExercisePlan->GetExerciseData());

			WeeklyExercisePlan->setAPIurl(WeeklyExercisePlan->getExerciseUrl() + second_category_id); 
			WeeklyExercisePlan->SetExerciseData(WeeklyExercisePlan->CallAPI());
			DailyRoutine->AddWorkoutsFromJSON(WeeklyExercisePlan->GetExerciseData());

			WeeklyExercisePlan->Add(day, DailyRoutine);

			// std::cout << "(" << *firstCategory << "," << *secondCategory << ")" << std::endl;
	}

	// WeeklyExercisePlan->SetExerciseData(WeeklyExercisePlan->CallAPI());

	// // Assigning exercises to each day
	// for(auto day : DaysOfWeek) {
	// 	Routine* DailyRoutine = new Routine();
	// 	DailyRoutine->AddWorkoutsFromJSON(WeeklyExercisePlan->GetExerciseData());
	// 	// DailyRoutine->AddWorkoutsFromJSON(WeeklyExercisePlan->GetExerciseData());
	// 	WeeklyExercisePlan->Add(day, DailyRoutine); 
	// } 

	return WeeklyExercisePlan; 
}