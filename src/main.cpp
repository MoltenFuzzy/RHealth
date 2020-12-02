#include <iostream>
#include "HealthApp.hpp"
#include "ExercisePlan.hpp"
#include "Routine.hpp"
#include "Workout.hpp"

using namespace std;

int main() {
	int age = 0;
	string sex;
	double height = 0.0;
	double weight = 0.0;
	char answer;
	
	cout << "Welcome to Rhealth!" << endl;
	cout << "Our goal is to create a tailored health plan based on your age, sex, weight and height. Our plan will include a list of meals and workouts to help you reach your goal." << endl;
	cout << "Let's get started!" << endl;

	cout << "Enter your age: " << endl;
	cin >> age;
        cout << "Enter your height (ex. 5.3): " << endl;
	cin >> height;
	cout << "Enter your sex: " << endl;
	cin >> sex;
	cout << "Enter your weight (ex. 120.5): " << endl;
	cin >> weight;

	cout << "You entered the following..." << endl;
	cout << "Age: " << age << endl;
	cout << "Height: " << height << endl;
	cout << "Sex: " << sex << endl;
	cout << "Weight: " << weight << endl;

	cout << "If the information entered is incorrect please enter 'I'. If the information is correct please enter 'C'." << endl;
	cin >> answer;

	if (answer == 'c' || answer == 'C') {
		cout << "The information you have entered is correct. Your health plan is now generating..." << endl;
	}
	if (answer != 'c' || answer != 'C') {
		cout << "The information you entered is incorrect. The program will now exit" << endl;
	}

	cout << "Welcome to your RHealth Plan!" << endl;
	//call functions			
	HealthApp rhealth;  
	HealthPlan* ExercisePlan = rhealth.CreateExercisePlan(20, "Male", 160, 180);

	ExercisePlan->Print(); 

	return 0;
}
