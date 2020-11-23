#include <iostream>
#include <cmath>

#include "WeightTracker.hpp"

using namespace std;

void WeightTracker::set_height(double height) {
        _height = height;
}

void WeightTracker::set_weight(double weight) {
        _weight = weight;
}

double WeightTracker::BmiCalculator(double _height, double _weight) {
	bmi = _weight / (pow(_height,2.0));
}

void WeightTracker::BmiLevel(double bmi) {
	if (bmi < 18.5) {
                cout << "Based on your BMI you are currently underweight." << endl;
                cout << "A calorie high diet will help increase you body mass index." << endl;
        }
        else if (bmi > 18.5 && bmi < 24.9) {
                cout << "Based on your BMI you are currently normal." << endl;
                cout << "Continue what you are doing and stay consistent." << endl;
        }
        else if (bmi > 25 && bmi < 29.9) {
                cout << "Based on your BMI you are currently overweight." << endl;
                cout << "Healthier eating and fitness will help to improve your health." << endl;
        }
        else if (bmi > 30) {
                cout << "Based on your BMI you are currently obese." << endl;
                cout << "You are at an increased risk for many health problems. An immediate change in your lifestyle is strongly recommended." << endl;
        }
}



