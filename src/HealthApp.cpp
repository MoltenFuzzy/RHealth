#include "HealthApp.hpp"

HealthPlan *HealthApp::CreateWeightTracker(int age, std::string sex, double weight, double height)
{
	WeightTracker *tracker = new WeightTracker();

	tracker->BMICalculator(weight, height);

	tracker->WeightTracker(age, sex, weight, height);

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

			// std::cout << "(" << *firstCategory << "," << *secondCategory << ")" << std::endl;
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
