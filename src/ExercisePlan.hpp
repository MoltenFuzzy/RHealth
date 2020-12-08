#ifndef EXERCISE_PLAN
#define EXERCISE_PLAN

#include "HealthPlan.hpp"
#include "APICaller.hpp"
// #include "Workout.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace curlpp::options;

// forward declaring workout bc we need to return it
// class Workout;

// virtual inheritence ensures only one copy of a base class's member variables are inherited by grandchild derived classes
class ExercisePlan : virtual public HealthPlan
{
private:
protected:
	// TODO: change limit to 6 workouts + 2 cardio? per day of week (6+2 * 7) = 56, assign 6 different workouts (3 of one muscle group each) for a day then 2 cardio
	// TODO: add category to link to search for more specific exercises
	std::string category_url = "https://wger.de/api/v2/exercisecategory/";

	std::string result_limit = "3";
	std::string exercise_url = "https://wger.de/api/v2/exercise/?language=2&limit=" + result_limit + "&category=";

	// data payload
	json payload;
	json ExerciseData;
	json Categories;

public:
	ExercisePlan()
	{
		API_token = "4bcc206865aff5431894a6bd1fd5efd69134013d";
	}

	// TODO: make algorithm based off BMI to create and Exercise plan for each weight category ie normal, overweight, etc...
	ExercisePlan(int age, std::string sex, double weight, double height) {}

	virtual size_t Size() { return 0; }
	virtual void Add(std::string key, ExercisePlan *value) {}
	virtual void Remove(std::string key, ExercisePlan *value) {}
	// searches for the name of the workout
	virtual ExercisePlan *Search(std::string key) { return nullptr; }
	virtual void Print(std::ostream &outs) = 0;

	virtual std::string GetName() { return ""; }
	virtual std::string GetDesc() { return ""; }

	void SetExerciseData(json e) { this->ExerciseData = e; }
	json GetExerciseData() { return this->ExerciseData; }

	// ONLY CALL THIS ONCE
	// Calls API and parses json payload to json object
	// Returns json payload
	const json &CallAPI()
	{
		if (APIFunction == nullptr)
		{
			throw std::runtime_error("Invalid API");
		}
		// for this specific api , we just need the results
		this->payload = APIFunction->CallAPI(this)["results"];
		// this->payload = this->payload["results"];

		return this->payload;
	}

	// Function will init the exercise categories using an API call
	void InitCategories()
	{
		setAPIFunction(new APICaller());
		// Set the url
		this->API_url = this->category_url;
		this->Categories = CallAPI();
	}

	void setAPIurl(std::string url) { this->API_url = url; }
	std::string getAPIurl() { return API_url; }

	void setAPItoken(std::string token) { this->API_token = token; }
	std::string getAPItoken() { return API_token; }

	std::string getExerciseUrl() { return this->exercise_url; }

	std::string getCategoryID(std::string key) { return Categories[key]; }

	const json &getCategories() { return this->Categories; }
};

#endif // EXERCISE_PLAN
