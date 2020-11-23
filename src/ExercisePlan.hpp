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
	void CreateWeeklyExercises(); 

protected:
	std::unordered_map<std::string, std::vector<ExercisePlan*>> WeeklyExercises;
	json ExerciseData; 

public:
	// BUG: RUNTIME IS SLOW BC FOR EVERY OBJECT ITS REQUESTING A PAYLOAD
	ExercisePlan() {}
	// TODO: make algorithm based off BMI to create and Exercise plan for each weight category ie normal, overweight, etc...
	ExercisePlan(int age, std::string sex, double weight, double height) {} 

	virtual void Add(ExercisePlan* e) {}
	virtual void Remove(ExercisePlan* e) {}
	virtual void Print();
	virtual std::string GetWorkoutName() {return "";}

	int size() { return WeeklyExercises.size(); }

	json GetExerciseData() { return this->ExerciseData; }
	std::unordered_map<std::string, std::vector<ExercisePlan*>>& GetWeeklyExercises() { return WeeklyExercises;}

	// Request payload body from exercise api and return a json object
	// this function parses the response and store it in exercise data
	void RequestAPI(); 
};


#endif // EXERCISE_PLAN
