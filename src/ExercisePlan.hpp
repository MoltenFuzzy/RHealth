#ifndef EXERCISE_PLAN
#define EXERCISE_PLAN


#include "HealthPlan.hpp"

#include <map>
#include <vector>
#include <string>
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
	std::string API_url = "https://wger.de/api/v2/exercise/?language=2";
	std::string API_token = "4bcc206865aff5431894a6bd1fd5efd69134013d";

	std::unordered_map<std::string, std::vector<ExercisePlan*>> WeeklyExercises;
	json ExerciseData; 

public:
	ExercisePlan() {}
	ExercisePlan(int age, std::string sex, double weight, double height); 

	// Create an daily exercise plan from the exercise data
	std::vector<ExercisePlan*> CreateDailyExercises(); 
	// Request payload body from exercise api and return a json object
	// this function should parse the response before return json
	void RequestExerciseAPI(); 
};


#endif // EXERCISE_PLAN
