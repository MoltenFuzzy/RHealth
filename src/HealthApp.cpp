#include "HealthApp.hpp"

void HealthApp::Run()
{
	int age = 0;
	std::string sex;
	double height = 0.0;
	int feet = 0;
	char dummy;
	int inches = 0;

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

	std::cout << R"(
			______ _   _            _ _   _     
			| ___ \ | | |          | | | | |    
			| |_/ / |_| | ___  __ _| | |_| |__  
			|    /|  _  |/ _ \/ _` | | __| '_ \ 
			| |\ \| | | |  __/ (_| | | |_| | | |
			\_| \_\_| |_/\___|\__,_|_|\__|_| |_| )"
			  << "\n\n";

	std::cout << "Our goal is to create a tailored health plan based on your age, sex, weight and height.\n";
	std::cout << "Our plan will include a list of meals and workouts to help you reach your goal.\n";
	std::cout << "Let's get started!" << std::endl;

	std::cout << "Enter your age: ";
	std::cin >> age;

	while (age < 0 || isdigit(age))
	{
		std::cout << "The age you entered is invalid, please enter your age again" << endl;
		std::cin >> age;
	}

	std::cout << "Enter your sex (M/F): ";
	std::cin >> sex;

	while (!(sex != "M" || sex != "F"))
	{
		std::cout << "The sex you entered is invalid, please enter your sex again" << endl;
		std::cin >> sex;
	}

	std::cout << "Enter your height (ex. 5'7): ";
	std::cin >> feet >> dummy >> inches;

	while (feet < 0 || isdigit(feet) || dummy != '\'' || inches < 0 || isdigit(inches))
	{
		std::cout << "The height you entered is invalid, please enter your height again" << endl;
		std::cin >> feet >> dummy >> inches;
	}

	std::cout << "Enter your weight (ex. 120.5): ";
	std::cin >> weight;

	while (weight < 0.0)
	{
		std::cout << "The weight you entered is invalid, please enter your weight again" << endl;
		std::cin >> weight;
	}

	std::cout << "You entered the following..." << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Height: " << feet << dummy << inches << std::endl;
	std::cout << "Sex: " << sex << std::endl;
	std::cout << "Weight: " << weight << std::endl;

	// Convert all values to metric
	height = feet + (inches / 12.0);
	weight /= 2.205;

	std::cout << "If the information entered is incorrect please enter 'I'. If the information is correct please enter 'C'." << std::endl;
	std::cin >> answer;

	if (std::tolower(answer) == 'c')
	{
		std::cout << "The information you have entered is correct. Your health plan is now generating..." << std::endl;
	}
	else
	{
		std::cout << "The information you entered is incorrect. The program will now exit" << std::endl;
	}

	int option_num = 0;
	bool exit_flag = false;

	// TODO: ADD LOOP HERE
	while (!exit_flag)
	{
		std::cout << "Select One of The Options" << std::endl;
		std::cout << "1. Weight Tracker" << std::endl;
		std::cout << "2. Meal Plan" << std::endl;
		std::cout << "3. Exercise Plan" << std::endl;
		std::cout << "4. Exit" << std::endl;

		std::cout << "Option: ";
		std::cin >> option_num;
		std::cout << "\n";

		switch (option_num)
		{
		case 1:
		{
			//WeightTrackerInterface();
		}
		break;
		case 2:
		{
			//MealPlanInterface();
		}
		break;
		case 3:
		{
			// TODO: Create a function for this
			auto ExercisePlanInterface = [&]() {
				bool go_back_flag = true;
				HealthPlan *Exercise_Plan = nullptr;

				while (go_back_flag)
				{
					int input = 0;
					std::cout << "Select One of The Options" << std::endl;
					// Call create exercise plan function
					std::cout << "1. Create new exercise plan" << std::endl;
					// Print the current exercise plan
					std::cout << "2. View current exercise plan" << std::endl;
					// Get the details about an specific workout
					std::cout << "3. Get more info about an exercise" << std::endl;
					// Load an exercise plan if there was one saved
					std::cout << "4. Load exercise plan" << std::endl;
					// Save the exercise plan, not sure if we are caching user data
					std::cout << "5. Save exercise plan" << std::endl;
					// not sure how to go back lol
					std::cout << "6. Back" << std::endl;

					std::cout << "Option: ";
					std::cin >> input;
					std::cout << "\n";

					switch (input)
					{
					case 1:
					{
						std::cout << "Creating New Exercise Plan...\n";
						Exercise_Plan = CreateExercisePlan(age, sex, weight, height);
						// TODO: CHECK IF API CALL FAILS
						// IF IT FAILS RETURN AN ERROR TO USER
						std::cout << "Exercise Plan Successfully Created!\n";
					}
					break;
					case 2:
					{
						if (Exercise_Plan == nullptr)
						{
							std::cout << "Exercise Plan Does Not Exist\n";
						}
						else
						{
							Exercise_Plan->Print(std::cout);
						}
					}
					break;
					case 3:
					{
						if (Exercise_Plan != nullptr)
						{
							std::string input_workout;
							std::cout << "Enter a workout from your plan to get more details: ";
							std::cin.ignore();
							std::getline(std::cin, input_workout);
							ExercisePlan *wk = dynamic_cast<ExercisePlan *>(Exercise_Plan)->Search(input_workout);

							if (wk != nullptr)
							{
								std::cout << "Name: " << wk->GetName() << std::endl;
								std::cout << "Description:\n"
										  << wk->GetDesc() << std::endl;
							}
							else
							{
								std::cout << "Workout not found!" << std::endl;
							}
						}
						else
						{
							std::cout << "Exercise Plan Does Not Exist\n";
						}
					}
					break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						// Leave loop
						go_back_flag = false;
						break;
					}
					std::cout << std::endl;
				}
			};
			ExercisePlanInterface();
			break;
		}
		case 4:
			exit_flag = true;
			break;
		}
	}
}

HealthPlan *HealthApp::CreateWeightTracker(int age, std::string sex, double weight, double height)
{
	WeightTracker *tracker = new WeightTracker(age, sex, weight, height);

	return tracker;
}

HealthPlan *HealthApp::CreateExercisePlan(int age, std::string sex, double weight, double height)
{
	// might be more organized if i moved this to a function inside ExercisePlan

	// TODO: TURN POINTERS INTO SMART POINTERS
	ExercisePlan *WeeklyExercisePlan = new Routine();

	double BMI = WeeklyExercisePlan->CalcBMI(weight, height);

	// TODO: Create API interface class to handle API calls for different subclasses
	//WeeklyExercisePlan->SendAPIRequest();
	WeeklyExercisePlan->setAPIFunction(new APICaller());

	// Set url to each 2 different types of exercises
	// "https://wger.de/api/v2/exercise/?language=2&limit=" + result_limit + "&category=" + Abs;
	// then call API to get JSON and add it daily routine, then add daily routine to weekly

	WeeklyExercisePlan->InitCategories();
	json Categories = WeeklyExercisePlan->getCategories();

	auto CreatePlan = [](json Categories, std::vector<std::string> DaysOfWeek, ExercisePlan *WeeklyExercisePlan) {
		// Creates exercise plan
		int index{0};
		for (const auto &day : DaysOfWeek)
		{
			std::string rest_day = "sunday";
			// skipping rest day
			if (day == rest_day)
				continue;

			// testing
			// if(day == "monday") break;

			Routine *DailyRoutine = new Routine();

			auto firstCategory{Categories.begin() + index};
			auto secondCategory{Categories.begin() + index + 1};

			if (secondCategory == Categories.end())
			{
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
	if (WeeklyExercisePlan->IsUnderWeight(BMI))
	{
		CreatePlan(Categories, DaysOfWeek, WeeklyExercisePlan);
	}
	// normal
	// normal weights, normal cardio
	else if (WeeklyExercisePlan->IsNormalWeight(BMI))
	{
		CreatePlan(Categories, DaysOfWeek, WeeklyExercisePlan);
	}
	// overweight
	// normal weights, more cardio
	else if (WeeklyExercisePlan->IsOverWeight(BMI))
	{
		CreatePlan(Categories, DaysOfWeek, WeeklyExercisePlan);
	}
	// obese
	// less weights, more cardio
	else
	{
		CreatePlan(Categories, DaysOfWeek, WeeklyExercisePlan);
	}

	return WeeklyExercisePlan;
}
