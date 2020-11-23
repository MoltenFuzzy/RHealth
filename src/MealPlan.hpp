#ifndef _MEALPLAN_HPP_
#define _MEALPLAN_HPP_

#include "HealthPlan.hpp"

#include "string"

class MealPlan : public HealthPlan {
	
	private:
        	/* data */
		unordered_map<string, vector<MealPlan>>WeeklyMeals;

	public:
		/* Constructor */
        	MealPlan(int age, string sex, double weight, double height){
			
			if (sex == "female") {
				if(height > 147 && height < 167){
					if (weight < 91 ){ // underweight
 						std::string MealPlan = "dairy,meats,carbohydrates";
						WeeklyMeals->add(Week1, mealplan);
					}else if (weight > 148 ){ // overweight
						std::string MealPlan = "vegetables,leanmeats,fiber";
						WeeklyMeals->add(Week1, mealplan);
					}
				}else if(height > 167 && height < 190){
					if (weight < 121 ){
						std::string MealPlan = "dairy,meats,carbohydrates";
                                        	WeeklyMeals->add(Week1, mealplan);
					}else if (weight > 192 ){
						std::string MealPlan = "vegetables,leanmeats,fiber";
                                        	WeeklyMeals->add(Week1, mealplan);
					}	
				}
			}else if(sex == "male") {
                                if(height > 147  && height < 167){
                                        if (weight < 103){
						std::string MealPlan = "dairy,meats,carbohydrates";
                                        	WeeklyMeals->add(Week1, mealplan);
					}else if (weight > 156 ){
						std::string MealPlan = "vegetables,leanmeats,fiber";
                                        	WeeklyMeals->add(Week1, mealplan);
					}
                                }
                                else if(height > 167 && height < 190){
                                        if (weight < 163 ){
						std::string MealPlan = "dairy,meats,carbohydrates";
                                        	WeeklyMeals->add(Week1, mealplan);
					}else if (weight > 222){
						std::string MealPlan = "vegetables,leanmeats,fiber";
                                        	WeeklyMeals->add(Week1, mealplan);
					}
                                }
			}
		}
		
		/* Destructor */
        	~MealPlan();

		/* Functions */
		void MealPlan(){
		}
		
		void Add(string WeekNumber, string mealplan){
			 WeeklyMeals[WeekNumber] = mealplan;
		}
	
		void Remove(string meanlplan){
			WeeklyMeals->delete(MealPlan);
		}
		
		MealPlan GetChild(string WeekNumber. string mealplan){
			return WeeklyMeals.find(WeekNumber, mealplan);
		}
};

#endif
