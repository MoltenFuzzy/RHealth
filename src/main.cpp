#include <iostream>
#include <string>

#include "HealthApp.hpp"
#include "ExercisePlan.hpp"
#include "WeightTracker.hpp"

using namespace std;

int main()
{
	/*
	DISCLAIMER: 
	BMI is not used for muscle builders, long distance athletes, pregnant women, the elderly or young children. 
	This is because BMI does not take into account whether the weight is carried as muscle or fat, just the number. 
	Those with a higher muscle mass, such as athletes, may have a high BMI but not be at greater health risk. 
	Those with a lower muscle mass, such as children who have not completed their growth or the elderly who may be losing some muscle mass may have a lower BMI. 
	During pregnancy and lactation, a woman's body composition changes, so using BMI is not appropriate.
	*/

	// int age = 0;
	// string sex;
	// double height = 0.0;
	// double weight = 0.0;
	// char answer;

	// cout << "Welcome to Rhealth!" << endl;
	// cout << "Our goal is to create a tailored health plan based on your age, sex, weight and height. Our plan will include a list of meals and workouts to help you reach your goal." << endl;
	// cout << "Let's get started!" << endl;

	// cout << "Enter your age: " << endl;
	// cin >> age;
	// cout << "Enter your height (ex. 5.3): " << endl;
	// cin >> height;
	// cout << "Enter your sex: " << endl;
	// cin >> sex;
	// cout << "Enter your weight (ex. 120.5): " << endl;
	// cin >> weight;

	// cout << "You entered the following..." << endl;
	// cout << "Age: " << age << endl;
	// cout << "Height: " << height << endl;
	// cout << "Sex: " << sex << endl;
	// cout << "Weight: " << weight << endl;

	// cout << "If the information entered is incorrect please enter 'I'. If the information is correct please enter 'C'." << endl;
	// cin >> answer;

	// if (answer == 'c' || answer == 'C')
	// {
	// 	cout << "The information you have entered is correct. Your health plan is now generating..." << endl;
	// }
	// else if (answer != 'c' || answer != 'C')
	// {
	// 	cout << "The information you entered is incorrect. The program will now exit." << endl;
	// 	return 0;
	// }

	// cout << "Welcome to your RHealth Plan!" << endl;
	//call functions
	HealthApp rhealth;

	// NOTE: Enter as standard, convert to metric
	// HealthPlan *ExercisePlan = rhealth.CreateExercisePlan(20, "Male", 80, 180);

	// ExercisePlan->Print();

	HealthPlan *WeightTracker = rhealth.CreateWeightTracker(20, "Male", 80, 180);

	// WeightTracker->Print();

	return 0;
}
