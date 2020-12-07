#ifndef MEALPLAN_HPP
#define MEALPLAN_HPP

#include "HealthPlan.hpp"
#include <vector>
#include <string>

class MealPlan : public HealthPlan {
	
	private:
		vector<vector<string>>WeeklyMeals;	
	public:
		MealPlan(double weight, double height);
		void UnderWeightMealPlan();
		void NormalWeightMealPlan();
		void OverWeightMealPlan();
		void ObeseWeightMealPlan();
};

#endif // MEALPLAN_HPP
