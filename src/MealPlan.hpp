#ifndef MEALPLAN_HPP
#define MEALPLAN_HPP

#include "HealthPlan.hpp"
#include "APICaller.hpp"

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


class MealPlan : virtual public HealthPlan {
	
	private:
		
	protected:
		std::string weeks_url = "";

		std::string result_limit = "3"; 
		std::string meal_url = "";
		
		json payload; 
		json MealData; 
		json Weeks;

	public:
		MealPlan() {
			API_token = "";
		}
		
		MealPlan(int age, std::string, double weight, double height) {}

		virtual size_t Size() { return 0; }
		virtual void Add(std::string key, MealPlan* value) {}
		virtual void Remove(std::string key, MealPlan* value) {}
		virtual void Print() = 0; 
		virtual std::string GetDailyMeal() { return ""; }
			
		void SetMealData(json e) { this->MealData = e; }
		json GetMealData() { return this->MealData; }

		const json& CallAPI() { 
			if(APIFunction == nullptr){
        			throw std::runtime_error("Invalid API");
        		}
			this->payload = APIFunction->CallAPI(this)["results"];
			return this->payload; 
		}

		void InitCategories() {
			setAPIFunction(new APICaller());
			this->API_url = this->weeks_url;
			this->Weeks = CallAPI();
		}

		void setAPIurl(std::string url) { this->API_url = url; }
		std::string getAPIurl() { return API_url; }

		void setAPItoken(std::string token) { this->API_token = token; }
		std::string getAPItoken() { return API_token; }

		std::string getMealUrl() { return this->meal_url; }
	
		std::string getWeeksID(std::string key) { return Weeks[key]; }
	
		const json& getWeeks() { return this->Weeks; }
};


#endif // MEALPLAN_HPP

