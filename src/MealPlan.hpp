#ifndef MEALPLAN_HPP
#define MEALPLAN_HPP

// Files
#include "HealthPlan.hpp"
#include "APICaller.hpp"
#include "Meals.hpp"
// User Libraries
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
// API Libraries
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace curlpp::options;

class MealPlan:virtual public HealthPlan{
	protected:
		json MealData;
		std::string meal_url="http://www.melskitchencafe.com/the-best-fudgy-brownies/";
		
	public:
		MealPlan(int age, std::string sex, double weight, double height){}

		void MealPlan(){
			setAPItoken("f6bcf37fdbmsh1c2a258eab8c8a6p1e59ddjsn1d8341acc7f8");
			AddToAPIheader("f6bcf37fdbmsh1c2a258eab8c8a6p1e59ddjsn1d8341acc7f8");
			AddToAPIheader("spoonacular-recipe-food-nutrition-v1.p.rapidapi.com")
		}
		
		virtual void Add(MealPlan * recipe){}

		virtual void Remove(MealPlan * recipe){}

		MealPlan GetChild(){}

		SetAPI(APIHandler* AnAPI) {}

		const json &CallAPI(){
			if(APIFunction==nullptr){
				throw std::runtime_error("Invalid API");
			}
			else{
				this->payload=APIFunction->CallAPI(this)["RecipeResults"];
			}
			return this->payload;
		} 
};

#endif // MEAL_HPP
