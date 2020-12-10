#ifndef MEAL_HPP
#define MEAL_HPP

#include "MealPlan.hpp"

class Meal:public MealPlan{
	
	private:
		std::string MealName;
		
	public:
		Meal(std::string mn):MealName{mn} {}
		std::string PrintMealName(){return MealName;}
};

#endif // MEAL_HPP
