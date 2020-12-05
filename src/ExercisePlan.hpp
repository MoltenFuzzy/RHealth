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
	std::string base_url = "https://wger.de/api/v2/exercise/?language=2"; 

	std::string result_limit = "3";  
	std::unordered_map<std::string, std::string> exercise_categories;

	void InitCategories() { 
		exercise_categories["Abs"] = "10"; 
		exercise_categories["Arms"] = "8"; 
		exercise_categories["Back"] = "12"; 
		exercise_categories["Calves"] = "14"; 
		exercise_categories["Chest"] = "11"; 
		exercise_categories["Legs"] = "9"; 
		exercise_categories["Shoulders"] = "13"; 
	}



protected:
	// TODO: change limit to 6 workouts + 2 cardio? per day of week (6+2 * 7) = 56, assign 6 different workouts (3 of one muscle group each) for a day then 2 cardio
	// TODO: add category to link to search for more specific exercises

	// data payload
	json ExerciseData; 

public:
	ExercisePlan() {

	}

	// TODO: make algorithm based off BMI to create and Exercise plan for each weight category ie normal, overweight, etc...
	ExercisePlan(int age, std::string sex, double weight, double height) {} 

	virtual size_t Size() { return 0; }
	virtual void Add(std::string key, ExercisePlan* value) {}
	virtual void Remove(std::string key, ExercisePlan* value) {}
	virtual void Print() = 0; 
	virtual std::string GetWorkoutName() { return ""; }

	json GetExerciseData() { return this->ExerciseData; }


	void BuildUrl() { 
		API_url = base_url + "&limit=" + result_limit + "&category="; 
		API_token = "4bcc206865aff5431894a6bd1fd5efd69134013d";
	}


	// ONLY CALL THIS ONCE
	// Calls API and parses json payload to json object
	void CallAPI() { 
		if(APIFunction == nullptr){
        	throw std::runtime_error("Invalid API");
        }
		this->ExerciseData = APIFunction->CallAPI(this); 
	}

	std::unordered_map<std::string, std::string> getCategoryMap() { return exercise_categories; }
	std::string getCategory(std::string key) { return exercise_categories[key]; }
	std::string getBaseUrl() { return base_url; }
	std::string getAPIurl() { return API_url; }
	std::string getAPItoken() { return API_token; }
	void setAPIurl(std::string new_url) { this->API_url = new_url; }
};


#endif // EXERCISE_PLAN
