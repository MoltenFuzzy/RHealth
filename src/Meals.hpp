#ifndef MEALS_HPP
#define MEALS_HPP

#include "MealPlan.hpp"
#include "Meal.hpp"

class Meals:public MealPlan{
	
	private:
		typedef std:: vector<std::pair<std::string, MealPlan *>> PairVector;
		PairVector meals;		
	public:
		MealPlan(int age, std::string sex, double weight, double height){
			double BMI = CalcBMI(this->weight, this->height);

        		if(IsUnderWeight(this->BMI)) {
                		//UnderWeightMealPlan();
                		bool under=true;
        		}
       			 else if(IsNormalWeight(this->BMI)) {
                		//NormalWeightMealPlan();
        			bool normal=true;
			}
        		else if(IsOverWeight(this->BMI)) {
                		//OverWeightMealPlan();
        			bool over=true;
			}
        		else if (IsObese(this->BMI)) {
                		//ObeseWeightMealPlan();
        			bool obese=true;
			}
		}

		void MealPlan(){
			if(under){
				std::string RecipeName="Roast Beef";
				MealPlan * Recipe="200g Roast Beef, 200g Mashed Potatoes, 80g Peas and Carrots\n\n ";
				Add(RecipeName, Recipe);
			}
			else if(normal){
				
			}
			else if(over){
				
			}
			else if(obese){
				
			}
		}

		void Add(std::string RecipeName, MealPlan * Recipe){
			meals.push_back(std::make_pair(RecipeName,Recipe));
		}

		void Remove(std::string RecipeName, MealPlan * Recipe){
			PairVector::iterator itr=std::find(meals.begin(), meals.end(), std::make_pair(RecipeName,Recipe));
		}

		MealPlan GetChild(){}
};

#endif // MEALS_HPP

