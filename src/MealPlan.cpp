#include "MealPlan.hpp"
#include "HealthPlan.hpp"

MealPlan::MealPlan(double weight, double height){

	double BMI = CalcBMI(this->weight, this->height);

	if(IsUnderWeight(this->BMI)) {
		UnderWeightMealPlan();
	}
	else if(IsNormalWeight(this->BMI)) {
		NormalWeightMealPlan();
	}
	else if(IsOverWeight(this->BMI)) {
		OverWeightMealPlan();
	}
	else if (IsObese(this->BMI)) {
		ObeseWeightMealPlan();
	}
}

void MealPlan::UnderWeightMealPlan() {

	for(int i = 0; i != 3; i++) {

		vector<string>DaysMeals;

                for(int j = 0; j != 7; j++) {

                        std::string MealsOneTwoThree = "Breakfast: 3 Scrambled Eggs, 3 Slices Wheat Buttered Toast, Cup of Orange Juice\n
							Lunch: 100g Cooked Chicken Breast, 2 Pita Breads, Green Salad with 1 Tbsp of Dressing\n
							Dinner: 200g Roast Beef, 200g Mashed Potatoes, 80g Peas and Carrots\n\n ";
                        DaysMeals.push_back(MealsOneTwoThree);
                
		}
                
		WeeklyMeals.push_back(DaysMeals);
        
	}
}


void MealPlan::NormalWeightMealPlan() {

        for(int i = 0; i != 3; i++) {

                vector<string>DaysMeals;

                for(int j = 0; j != 7; j++) {

			std::string MealsOneTwoThree = "Breakfast: 1 Cup Oatmeal Cooked in 1 Cup Almond Milk, 1 Cup Blueberries, 32g PeanutButter\n
							Lunch: 40g Spinch, 112g Grilled Chicken, 120g Chickpeas, 28g Feta Cheese, Vinaigrette\n
							Dinner: 120g Baked Chicken, 200g Roasted Butternut Squash, 1808 Roasted Broccoli\n\n ";
                        DaysMeals.push_back(MealsOneTwoThree);

                }

                WeeklyMeals.push_back(DaysMeals);

        }
}


void MealPlan::OverWeightMealPlan() {

        for(int i = 0; i != 3; i++) {

                vector<string>DaysMeals;

                for(int j = 0; j != 7; j++) {

                        std::string MealsOneTwoThree = "Breakfast: 1/3 Cup of Muesli, 1 Cup Raspberries, 3/4 Cup of Low Fat Milk\n
							Lunch: 1 Mini Wheat Pita, 3oz Turkey Breast, 1/2 Roasted Pepper, 1 Teaspoon Mayo, Lettuce, 2 Kiwis\n
							Dinner: 4oz Broiled Flounder, 1 Cup Cooked Couscous, 1 Cup Steamed Broccoli\n\n ";
                        DaysMeals.push_back(MealsOneTwoThree);

                }

                WeeklyMeals.push_back(DaysMeals);

        }
}

void MealPlan::ObeseWeightMealPlan() {

        for(int i = 0; i != 3; i++) {

                vector<string>DaysMeals;

                for(int j = 0; j != 7; j++) {

                        std::string MealsOneTwoThree = "Breakfast: 3 Buckwheat Pancaked, 1/2 Cup Strawberries, 3/4 Cup Melon, 1/2 Cup Fat Free Milk\n
							Lunch: 2 Slices Wheat Bread, 3Tbsp Hummus, 1/4 Avocado, 1/4 Bell Pepper, 1/4 Cup Sliced Cucumber\n
							Dinner: 5oz Grilled Steak, 3/4 Cup Mashed Potatoes, 1/2 Steamed Carrots, 1 Wheat Dinner Roll\n\n ";
                        DaysMeals.push_back(MealsOneTwoThree)
                }

                WeeklyMeals.push_back(DaysMeals);

        }
}
		
