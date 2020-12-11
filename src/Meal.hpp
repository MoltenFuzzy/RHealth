#ifndef MEAL_HPP
#define MEAL_HPP

#include "MealPlan.hpp"

class Meal : public MealPlan
{

private:
	std::string MealName;
	std::string MealLink;

public:
	Meal() {}
	Meal(std::string MealName, std::string MealLink) : MealName{MealName}, MealLink{MealName} {}

	void Print(std::ostream &outs)
	{
		outs << this->MealName;
	}

	std::string GetMealName() { return MealName; }

	std::string GetMealLink() { return MealLink; }
};

#endif // MEAL_HPP