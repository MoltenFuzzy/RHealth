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
	void initCardioWorkouts()
	{
		Cardio = json::array();
		Cardio.push_back(json::object({{"name", "Mountain Climbers"}, {"description", "Start from a high plank position with your hands stacked directly under your shoulders.\n Drive one knee forward toward your chest while engaging your abs.\n Return to your plank position, then drive the knee of your opposite foot in. Repeat the movement, alternating legs and speeding up your movements."}}));
		Cardio.push_back(json::object({{"name", "Jump Rope"}, {"description", "Hold the rope while keeping your hands at hip level.\n Rotate your wrists to swing the rope and jump.\n Jump with both feet at the same time, one foot at a time, alternating between feeting, etc.\n Repeat until the set is complete."}}));
		Cardio.push_back(json::object({{"name", "High Knees"}, {"description", "Start standing with feet hip-distance apart. Lift up right knee as high as it will go and raise the opposite arm, then switch quickly so left knee is up before right foot lands. Continue pulling knees up quirky for as long as desired."}}));
		Cardio.push_back(json::object({{"name", "Plank"}, {"description", "1. Plant hands directly under shoulders (slightly wider than shoulder width) like you’re about to do a push-up. 2. Ground toes into the floor and squeeze glutes to stabilize your body. Your legs should be working, too — be careful not to lock or hyperextend your knees. 3. Neutralize your neck and spine by looking at a spot on the floor about a foot beyond your hands. Your head should be in line with your back. 4. Hold the position for 20 seconds. As you get more comfortable with the move, hold your plank for as long as possible without compromising your form or breath."}}));
		Cardio.push_back(json::object({{"name", "Mile Run"}, {"description", "Maintain a constant pace while running 1 mile. You can run more if you want to."}}));
		Cardio.push_back(json::object({{"name", "Burpees"},
									   {"description", "Start in a squat position with your knees bent, back straight, and your feet about shoulder-width apart. Lower your hands to the floor in front of you so they’re just inside your feet.With your weight on your hands, kick your feet back so you’re on your hands and toes, and in a pushup position.Keeping your body straight from head to heels, do one pushup.Remember not to let your back sag or to stick your butt in the air.Do a frog kick by jumping your feet back to their starting position.Stand and reach your arms over your head.Jump quickly into the air so you land back where you started.As soon as you land with knees bent, get into a squat position and do another repetition."}}));
		Cardio.push_back(json::object({{"name", "Jumping Jacks"},
									   {"description", "Start standing up with your legs together, a slight bend in knees, and hands resting on thighs. Keeping the knees bent, open the arms and legs out to the sides.Arms come above the head and legs wider than shoulders.Close your arms and legs back to your sides, returning to your start."}}));
	}

protected:
	// TODO: change limit to 6 workouts + 2 cardio? per day of week (6+2 * 7) = 56, assign 6 different workouts (3 of one muscle group each) for a day then 2 cardio
	// TODO: add category to link to search for more specific exercises
	std::string category_url = "https://wger.de/api/v2/exercisecategory/";

	std::string result_limit = "3";
	std::string exercise_url = "https://wger.de/api/v2/exercise/?language=2&offset=1&limit=" + result_limit + "&category=";

	// std::string header1 = "Authorization: Token ";
	// header.push_back("Authorization: Token " + API_token);
	// header.push_back("Accept: application/json; indent=4");

	// data
	json ExerciseData;
	json Categories;
	json Cardio;

public:
	ExercisePlan()
	{
		API_token = "4bcc206865aff5431894a6bd1fd5efd69134013d";
		API_header.push_back("Authorization: Token " + API_token);
		API_header.push_back("Accept: application/json; indent=4");

		initCardioWorkouts();
	}

	ExercisePlan(int age, std::string sex, double weight, double height) {}

	~ExercisePlan()
	{
	}

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

	const json &GetCardioJSON() { return this->Cardio; }

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

	void AddToAPIheader(std::string hdr) { API_header.push_back(hdr); }
	std::list<std::string> getAPIheader() { return API_header; }

	std::string getExerciseUrl() { return this->exercise_url; }

	std::string getCategoryID(std::string key) { return Categories[key]; }

	const json &getCategories() { return this->Categories; }
};

#endif // EXERCISE_PLAN
