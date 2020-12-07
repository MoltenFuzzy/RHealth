#include "HealthApp.hpp"

void HealthApp::Run() {
	int age = 0;
	std::string sex;
	double height = 0.0;
	double weight = 0.0;
	char answer;

	/*
	DISCLAIMER: 
	BMI is not used for muscle builders, long distance athletes, pregnant women, the elderly or young children. 
	This is because BMI does not take into account whether the weight is carried as muscle or fat, just the number. 
	Those with a higher muscle mass, such as athletes, may have a high BMI but not be at greater health risk. 
	Those with a lower muscle mass, such as children who have not completed their growth or the elderly who may be losing some muscle mass may have a lower BMI. 
	During pregnancy and lactation, a woman's body composition changes, so using BMI is not appropriate.
	*/

	
	std::cout << R"(        	______ _   _            _ _   _     
		| ___ \ | | |          | | | | |    
		| |_/ / |_| | ___  __ _| | |_| |__  
		|    /|  _  |/ _ \/ _` | | __| '_ \ 
		| |\ \| | | |  __/ (_| | | |_| | | |
		\_| \_\_| |_/\___|\__,_|_|\__|_| |_| )" << "\n\n";

	std::cout << "Our goal is to create a tailored health plan based on your age, sex, weight and height.\n";
	std::cout << "Our plan will include a list of meals and workouts to help you reach your goal.\n";
	std::cout << "Let's get started!" << std::endl;

	// TODO: Input validation
	std::cout << "Enter your age: ";
	std::cin >> age;

	std::cout << "Enter your sex (M/F): "; 
	std::cin >> sex;

    std::cout << "Enter your height (ex. 5'7): ";
	std::cin >> height;

	std::cout << "Enter your weight (ex. 120.5): ";
	std::cin >> weight;


	std::cout << "You entered the following..." << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Height: " << height << std::endl;
	std::cout << "Sex: " << sex << std::endl;
	std::cout << "Weight: " << weight << std::endl;

	std::cout << "If the information entered is incorrect please enter 'I'. If the information is correct please enter 'C'." << std::endl;
	std::cin >> answer;

	if (answer == 'c' || answer == 'C') {
		std::cout << "The information you have entered is correct. Your health plan is now generating..." << std::endl;
	}
	if (answer != 'c' || answer != 'C') {
		std::cout << "The information you entered is incorrect. The program will now exit" << std::endl;
	}

	int option_num = 0; 

	std::cout << "Select One of The Options" << std::endl;
	std::cout << "1. Weight Tracker" <<  std::endl;
	std::cout << "2. Meal Plan" << std::endl;
	std::cout << "3. Exercise Plan" << std::endl;

	std::cin >> option_num; 

	switch(option_num) {
		case 1: //WeightTrackerInterface(); 
		case 2:	//MealPlanInterface(); 
		case 3: 
				// TODO: Create a function for this
				std::cout << "Select One of The Options" << std::endl;
				// Call create exercise plan function
				std::cout << "1. Create new exercise plan" <<  std::endl;
				// Print the current exercise plan
				std::cout << "2. View current exercise plan" << std::endl;
				// TODO: add search function for composite tree
				std::cout << "3. Search for an exercise" << std::endl;
				// Load an exercise plan if there was one saved
				std::cout << "4. Load exercise plan" << std::endl;
				// Save the exercise plan, not sure if we are caching user data 
				std::cout << "5. Save exercise plan" << std::endl;
				// not sure how to go back lol
				std::cout << "6. Back" << std::endl;
	}

	// NOTE: Enter as standard, convert to metric
	// HealthPlan* ExercisePlan = CreateExercisePlan(20, "Male", 80, 180);

	// ExercisePlan->Print(); 
}

HealthPlan* HealthApp::CreateExercisePlan(int age, std::string sex, double weight, double height) {
	// might be more organized if i moved this to a function inside ExercisePlan

	// TODO: TURN POINTERS INTO SMART POINTERS	
	ExercisePlan* WeeklyExercisePlan = new Routine();

	double BMI = WeeklyExercisePlan->CalcBMI(weight, height); 

	// TODO: Create API interface class to handle API calls for different subclasses
	//WeeklyExercisePlan->SendAPIRequest();
	WeeklyExercisePlan->setAPIFunction(new APICaller());

	// Set url to each 2 different types of exercises
	// "https://wger.de/api/v2/exercise/?language=2&limit=" + result_limit + "&category=" + Abs; 
	// then call API to get JSON and add it daily routine, then add daily routine to weekly

	WeeklyExercisePlan->InitCategories(); 
	json Categories = WeeklyExercisePlan->getCategories(); 


	auto CreatePlan = [](json Categories, std::vector<std::string> DaysOfWeek, ExercisePlan* WeeklyExercisePlan) { 
		// Creates exercise plan
		int index {0};
		for (const auto& day : DaysOfWeek) {
				std::string rest_day = "sunday"; 
				// skipping rest day
				if(day == rest_day) continue; 

				// testing
				// if(day == "monday") break; 

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

				WeeklyExercisePlan->setAPIurl(WeeklyExercisePlan->getExerciseUrl() + first_category_id); 

				// CallAPI takes forever... 
				// TODO: Optimize so that maybe only 1 or 2 calls are needed opposed to 2 * 7 = 14
				// probably not possible to condense into 1-2 calls since we need to call the api for each category
				WeeklyExercisePlan->SetExerciseData(WeeklyExercisePlan->CallAPI());
				DailyRoutine->AddWorkoutsFromJSON(WeeklyExercisePlan->GetExerciseData());


				WeeklyExercisePlan->setAPIurl(WeeklyExercisePlan->getExerciseUrl() + second_category_id); 
				WeeklyExercisePlan->SetExerciseData(WeeklyExercisePlan->CallAPI());
				DailyRoutine->AddWorkoutsFromJSON(WeeklyExercisePlan->GetExerciseData());

				WeeklyExercisePlan->Add(day, DailyRoutine);

				// std::std::cout << "(" << *firstCategory << "," << *secondCategory << ")" << std::std::endl;
		}
	};


	// TODO: ADD STRING PARAMETER TO CREATE PLAN TO INDENTIFY WEIGHT STATUS TO CREATE THE CORRECT PLAN
	// Weight Status

	// underweight
	// More weights, less cardio
	if(WeeklyExercisePlan->IsUnderWeight(BMI)) {
		CreatePlan(Categories, DaysOfWeek, WeeklyExercisePlan);
	}
	// normal 
	// normal weights, normal cardio
	else if(WeeklyExercisePlan->IsNormalWeight(BMI)) {
		CreatePlan(Categories, DaysOfWeek, WeeklyExercisePlan);
	}
	// overweight
	// normal weights, more cardio
	else if(WeeklyExercisePlan->IsOverWeight(BMI)) {
		CreatePlan(Categories, DaysOfWeek, WeeklyExercisePlan);
	}
	// obese
	// less weights, more cardio
	else {
		CreatePlan(Categories, DaysOfWeek, WeeklyExercisePlan);
	}

	return WeeklyExercisePlan; 
}