#ifndef MEALS_HPP
#define MEALS_HPP

#include "MealPlan.hpp"
#include "Meal.hpp"

class Meals : public MealPlan
{

private:
	typedef std::vector<std::pair<std::string, MealPlan *>> PairVector;
	PairVector meals;

public:
	Meals(int age, std::string sex, double weight, double height) : HealthPlan(age, sex, weight, height) {}

	Meals() {}

	void Add(std::string MealName, MealPlan *MealLink)
	{
		meals.push_back(std::make_pair(MealName, MealLink));
	}

	void Remove(std::string MealName, MealPlan *MealLink)
	{
		PairVector::iterator itr = std::find(meals.begin(), meals.end(), std::make_pair(MealName, MealLink));
		if (itr != meals.end())
		{
			meals.erase(itr);
		}
	}

	void ExtractMealsFromJson(const json &meals)
	{
		for (auto meal : meals)
		{
			std::string mealName = meal["title"].get<std::string>();
			std::string mealLink = meal["sourceUrl"].get<std::string>();
			Add(mealName, new Meal(mealName, mealLink));
		}
	}

	//MealPlan GetChild(){}

	void Print(std::ostream &outs)
	{
		for (auto meal : meals)
		{
			// Only print if the key is a day of the week
			if (std::find(DaysOfWeek.begin(), DaysOfWeek.end(), meal.first) != DaysOfWeek.end())
			{
				outs << meal.first << std::endl;
			}

			meal.second->Print(outs);
			outs << std::endl;
		}
	}
};

#endif // MEALS_HPP