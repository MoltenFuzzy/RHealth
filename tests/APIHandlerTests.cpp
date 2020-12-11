#include "gtest/gtest.h"

#include "../src/APIHandler.hpp"
#include "../src/APICaller.hpp"
#include "../src/ExercisePlan.hpp"
#include "../src/Workout.hpp"
#include "../src/Routine.hpp"

TEST(APIHandlerTest, CallAPITest)
{
	HealthPlan *test = new HealthPlan();
	test->setAPIFunction(new APICaller());
	test->setAPIurl("https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/search?query=healthy&diet=vegetarian&excludeIngredients=coconut&intolerances=egg%2C%20gluten&number=10&offset=0&type=main%20course");
	test->AddToAPIheader("x-rapidapi-key: f6bcf37fdbmsh1c2a258eab8c8a6p1e59ddjsn1d8341acc7f8");
	test->AddToAPIheader("x-rapidapi-host: spoonacular-recipe-food-nutrition-v1.p.rapidapi.com");
	json test_food_data = (test->CallAPI())["results"];

	json expected_data;
	expected_data[0]["title"] = "Brussel Sprouts, Potatoes And Cranberries";
	expected_data[1]["title"] = "Spiced Lentils with Mushrooms and Greens";
	expected_data[2]["title"] = "Lentil Stew with Winter Vegetables";
	expected_data[3]["title"] = "Oven-Dried Tomatoes";
	expected_data[4]["title"] = "Broccoli With Spicy Gremolata";
	expected_data[5]["title"] = "Curried Lentil and Chickpea Stew";
	expected_data[6]["title"] = "South Indian Lentil Cakes With Raita";
	expected_data[7]["title"] = "Lentils and Rice";
	expected_data[8]["title"] = "Lentil And Sausage Soup For A Cold Winter's Night";
	expected_data[9]["title"] = "Dinner Tonight: Green Lentil Salad with Baby Spinach and Goat Cheese";

	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(test_food_data[i]["title"], expected_data[i]["title"]);
	}
}

<<<<<<< HEAD
TEST(APIHandlerTest, CallExerciseAPITest)
{
	HealthPlan *test = new HealthPlan();
	test->setAPIFunction(new APICaller());
	test->setAPIurl("https://wger.de/api/v2/exercisecategory/");
	test->AddToAPIheader("Authorization: Token 4bcc206865aff5431894a6bd1fd5efd69134013d");
	test->AddToAPIheader("Accept: application/json; indent=4");
	json test_food_data = (test->CallAPI())["results"];

	json expected_data;
	expected_data[0]["id"] = 10;
	expected_data[1]["id"] = 8;

	for (int i = 0; i < 2; i++)
	{
		EXPECT_EQ(test_food_data[i]["id"], expected_data[i]["id"]);
	}
}

TEST(APIHandlerTest, CallInvalidAPITest)
{
	HealthPlan *test = new HealthPlan();
	test->setAPIFunction(new APICaller());
	test->setAPIurl("");
	test->AddToAPIheader("");
	test->AddToAPIheader("");

	// expect an empty json
	EXPECT_EQ(test->CallAPI(), json());
}

=======
>>>>>>> master
// here we are testing for an exception thrown
TEST(APIHandlerTest, APICallerIsNull)
{
	HealthPlan *test = new HealthPlan();
	test->setAPIFunction(nullptr);

	EXPECT_THROW(test->CallAPI(), std::runtime_error);
}