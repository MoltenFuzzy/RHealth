#ifndef MEAL_PLAN
#define MEAL_PLAN

#include "HealthPlan.hpp"

using json = nlohmann::json;
using namespace curlpp::options;


class MealPlan:virtual public HealthPlan{
	protected:
		json MealData;
		std::string meal_url="https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/search?query=healthy&diet=vegetarian&excludeIngredients=coconut&intolerances=egg%2C%20gluten&number=21&offset=0&type=main%20course";
		
	public:
		MealPlan(int age, std::string sex, double weight, double height){}

		void MealPlan(){
			setAPItoken("x-rapidapi-key: 9db5831fb1mshc6cc5560f899fadp151893jsn29ec635b5745");
			AddToAPIheader("x-rapidapi-key: 9db5831fb1mshc6cc5560f899fadp151893jsn29ec635b5745");
			AddToAPIheader("x-rapidapi-host: spoonacular-recipe-food-nutrition-v1.p.rapidapi.com");
		}
		
		virtual void Add(std::string MealName,MealPlan * MealLink){}

		virtual void Remove(std::string MealName,MealPlan * MealLink){}

		//MealPlan GetChild(){}

		//SetAPI(APIHandler* AnAPI) {}

		virtual void PrintMeal(std::ostream &outs)=0;

		virtual std::string GetMealName(){}

		virtual std::string GetMealLink(){}

		void SetMealData(json m){this->MealData=m;}

		json GetMealData(){return this->MealData;}

		const json &CallAPI(){
			if(APIFunction==nullptr){
				throw std::runtime_error("Invalid API");
			}
			else{
				this->payload=APIFunction->CallAPI(this)["results"];
			}
			return this->payload;
		} 

};

#endif // MEAL_PLAN

