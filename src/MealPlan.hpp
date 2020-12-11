#ifndef MEALPLAN_HPP
#define MEALPLAN_HPP

// Files
#include "HealthPlan.hpp"
#include "APICaller.hpp"
// User Libraries
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
// API Libraries
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace curlpp::options;

class MealPlan : virtual public HealthPlan
{
protected:
	json MealData;
	std::string meal_url = "https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/search?query=healthy&diet=vegetarian&excludeIngredients=coconut&intolerances=egg%2C%20gluten&number=21&offset=0&type=main%20course";

public:
	MealPlan(int age, std::string sex, double weight, double height) {}

	MealPlan()
	{
		setAPItoken("9db5831fb1mshc6cc5560f899fadp151893jsn29ec635b5745");
		AddToAPIheader("x-rapidapi-key: 9db5831fb1mshc6cc5560f899fadp151893jsn29ec635b5745");
		AddToAPIheader("x-rapidapi-host: spoonacular-recipe-food-nutrition-v1.p.rapidapi.com");
	}

	virtual void Add(std::string MealName, MealPlan *MealLink) {}

	virtual void Remove(std::string MealName, MealPlan *MealLink) {}

	//MealPlan GetChild(){}

	//SetAPI(APIHandler* AnAPI) {}

	virtual void Print(std::ostream &outs) = 0;

	virtual std::string GetMealName() { return ""; }

	virtual std::string GetMealLink() { return ""; }

	void SetMealData(json m) { this->MealData = m; }

	json GetMealData() { return this->MealData; }

	const json &CallAPI()
	{
		if (APIFunction == nullptr)
		{
			throw std::runtime_error("Invalid API");
		}
		else
		{
			this->payload = APIFunction->CallAPI(this)["results"];
		}
		return this->payload;
	}

	void setAPIurl(std::string url) { this->API_url = url; }
	std::string getAPIurl() { return API_url; }

	std::string getMealUrl() { return meal_url; }
};

#endif // MEAL_HPP
