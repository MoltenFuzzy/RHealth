#ifndef EXERCISE_PLAN
#define EXERCISE_PLAN


#include "HealthPlan.hpp"

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

class ExercisePlan : public HealthPlan
{
private:

protected:
	// TODO: change limit to 6 workouts + 2 cardio? per day of week (6+2 * 7) = 56, assign 6 different workouts (3 of one muscle group each) for a day then 2 cardio
	// TODO: add category to link to search for more specific exercises
	std::string result_limit = "10"; 

	// data payload
	json ExerciseData; 

public:
	ExercisePlan() {
		API_url = "https://wger.de/api/v2/exercise/?language=2&limit=" + result_limit;
		API_token = "4bcc206865aff5431894a6bd1fd5efd69134013d";
	}

	// TODO: make algorithm based off BMI to create and Exercise plan for each weight category ie normal, overweight, etc...
	ExercisePlan(int age, std::string sex, double weight, double height) {} 

	virtual size_t Size() { return 0; }
	virtual void Add(std::string key, ExercisePlan* value) {}
	virtual void Remove(std::string key, ExercisePlan* value) {}
	virtual void Print() = 0; 
	virtual std::string GetWorkoutName() { return ""; }

	json GetExerciseData() { return this->ExerciseData; }

	// ONLY CALL THIS ONCE
	// Calls API and parses json payload to json object
	void CallAPI() { 
		if(APIFunction == nullptr){
        	throw std::runtime_error("Invalid API");
        }
		this->ExerciseData = APIFunction->CallAPI(this); 
	}

	std::string getAPIurl() { return API_url; }
	std::string getAPItoken() { return API_token; }
};


#endif // EXERCISE_PLAN
