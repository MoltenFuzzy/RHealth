#include "gtest/gtest.h"

#include "../src/MealPlan.hpp"
#include "../src/Meal.hpp"
#include "../src/Meals.hpp"
#include "../src/HealthApp.hpp"


TEST(MealPlanTests, TenObeseWeightMeals){
	HealthPlan *meal_test=new HealthPlan();
	test->setAPIFunction(new APICaller());
	test->setAPIurl("https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/search?query=healthy&diet=vegetarian&excludeIngredients=coconut&intolerances=egg%2C%20gluten&number=21&offset=0&type=main%20course");
	test->AddToAPIheader("x-rapidapi-key: 9db5831fb1mshc6cc5560f899fadp151893jsn29ec635b5745");
	test->AddToAPIheader("x-rapidapi-host: spoonacular-recipe-food-nutrition-v1.p.rapidapi.com");
	json test_food_data=(test->CallAPI())["results"];

	json expected_meal_data;
	expected_meal_data[0]["title"]="Eggs and Toast";
	expected_meal_data[1]["title"]="Chicken Pita Sandwhich";
	expected_meal_data[2]["title"]="Roast Beef";
	expected_meal_data[3]["title"]="Healthy Oatmeal";
	expected_meal_data[4]["title"]="Grilled Chicken Salad";
	expected_meal_data[5]["title"]="ButternutSquash Baked Chicken";
	expected_meal_data[6]["title"]="Healthy Muesli";
	expected_meal_data[7]["title"]="Pita Turkey Sandwhich";
	expected_meal_data[8]["title"]="Couscous and Flounder";
	expected_meal_data[9]["title"]="Grilled Steak";

	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(test_food_data[i]["title"], expected_meal_data[i]["title"]);
	}
	
	
}

TEST(MealPlanTests, TenOverWeightMeals){
        HealthPlan *meal_test=new HealthPlan();
        test->setAPIFunction(new APICaller());
        test->setAPIurl("https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/search?query=healthy&diet=vegetarian&excludeIngredients=coconut&intolerances=egg%2C%20gluten&number=21&offset=0&type=main%20course");
        test->AddToAPIheader("x-rapidapi-key: 9db5831fb1mshc6cc5560f899fadp151893jsn29ec635b5745");
        test->AddToAPIheader("x-rapidapi-host: spoonacular-recipe-food-nutrition-v1.p.rapidapi.com");
        json test_food_data=(test->CallAPI())["results"];

        json expected_meal_data;
        expected_meal_data[0]["title"]="Buckwheat Pancakes and Fruit";
        expected_meal_data[1]["title"]="Healthy Hummus Sandwhich";
        expected_meal_data[2]["title"]="Grilled Steak and Sides";
        expected_meal_data[3]["title"]="Spinash and Quinoa Salad";
        expected_meal_data[4]["title"]="Nodle Bowl with Grilled Chicken";
        expected_meal_data[5]["title"]="Healthy Talapia Tacos";
        expected_meal_data[6]["title"]="Garbanzo Salad";
        expected_meal_data[7]["title"]="Butternut Squash Noodles w/ Spinah and Mushroom";
        expected_meal_data[8]["title"]="Lentil Soup with Pita";
        expected_meal_data[9]["title"]="Vegan Breakfast Burrito";

        for (int i = 0; i < 10; i++)
        {
                EXPECT_EQ(test_food_data[i]["title"], expected_meal_data[i]["title"]);
        }


}

TEST(MealPlanTests, TenNormalWeightMeals){
        HealthPlan *meal_test=new HealthPlan();
        test->setAPIFunction(new APICaller());
        test->setAPIurl("https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/search?query=healthy&diet=vegetarian&excludeIngredients=coconut&intolerances=egg%2C%20gluten&number=21&offset=0&type=main%20course");
        test->AddToAPIheader("x-rapidapi-key: 9db5831fb1mshc6cc5560f899fadp151893jsn29ec635b5745");
        test->AddToAPIheader("x-rapidapi-host: spoonacular-recipe-food-nutrition-v1.p.rapidapi.com");
        json test_food_data=(test->CallAPI())["results"];

        json expected_meal_data;
        expected_meal_data[0]["title"]="Tuna and Veggies Pasat Salad";
        expected_meal_data[1]["title"]="Pork Chops w/ Carrots and Rice";
        expected_meal_data[2]["title"]="Mango and Berries Smoothie Bowl";
        expected_meal_data[3]["title"]="Philly Cheese Steak Sandwiches";
        expected_meal_data[4]["title"]="Granola Cereal with Fruits and Nuts";
        expected_meal_data[5]["title"]="Creamy Pasta w/ Chicken and Mushroom";
        expected_meal_data[6]["title"]="Fried Chicken and Potatoe Salad";
        expected_meal_data[7]["title"]="Hard Boiled Egg Salad";
        expected_meal_data[8]["title"]="Green Slada w/ Chicken";
        expected_meal_data[9]["title"]="Veggies and Avocado Spread Wraps";

        for (int i = 0; i < 10; i++)
        {
                EXPECT_EQ(test_food_data[i]["title"], expected_meal_data[i]["title"]);
        }


}

TEST(MealPlanTests, TenUnderWeightMeals){
        HealthPlan *meal_test=new HealthPlan();
        test->setAPIFunction(new APICaller());
        test->setAPIurl("https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/search?query=healthy&diet=vegetarian&excludeIngredients=coconut&intolerances=egg%2C%20gluten&number=21&offset=0&type=main%20course");
        test->AddToAPIheader("x-rapidapi-key: 9db5831fb1mshc6cc5560f899fadp151893jsn29ec635b5745");
        test->AddToAPIheader("x-rapidapi-host: spoonacular-recipe-food-nutrition-v1.p.rapidapi.com");
        json test_food_data=(test->CallAPI())["results"];

        json expected_meal_data;
        expected_meal_data[0]["title"]="Tortills Chips with Bean Salad";
        expected_meal_data[1]["title"]="Spinach Stuffed Salmon w/ Rice";
        expected_meal_data[2]["title"]="Banana Chocolate Shake";
        expected_meal_data[3]["title"]="Vegetarian Soup w/ Muffin";
        expected_meal_data[4]["title"]="Barbecue Turkey Burger";
        expected_meal_data[5]["title"]="Grilled Salmon w/ Quinoa";
        expected_meal_data[6]["title"]="Tomato Soup w/ Pita";
        expected_meal_data[7]["title"]="Greek Apple Chicken Salad";
        expected_meal_data[8]["title"]="Whole Oats with Whole Milk and Fruits";
        expected_meal_data[9]["title"]="Barbecue Chicken w/ Spinach";

        for (int i = 0; i < 10; i++)
        {
                EXPECT_EQ(test_food_data[i]["title"], expected_meal_data[i]["title"]);
        }


}
