#include <iostream>
#include <cmath>

#include "WeightTracker.hpp"

using namespace std;

void WeightTracker::DisplayWeightStatus()
{
	if (IsUnderWeight(BMI))
	{
		cout << "Based on your BMI you are currently underweight." << endl;
		cout << "A calorie high diet will help increase you body mass index." << endl;
	}
	else if (IsNormalWeight(BMI))
	{
		cout << "Based on your BMI you are currently normal." << endl;
		cout << "Continue what you are doing and stay consistent." << endl;
	}
	else if (IsOverWeight(BMI))
	{
		cout << "Based on your BMI you are currently overweight." << endl;
		cout << "Healthier eating and fitness will help to improve your health." << endl;
	}
	else if (IsObese(BMI))
	{
		cout << "Based on your BMI you are currently obese." << endl;
		cout << "You are at an increased risk for many health problems. An immediate change in your lifestyle is strongly recommended." << endl;
	}
}

void WeightTracker::GiveHealthAdvice()
{
	double healthyWeight;
	double weightDiff;

	if (IsUnderWeight(BMI))
	{
		cout << "Since you are currently underweight, we recommend gaining enough weight to reach a healthy BMI." << endl;
		healthyWeight = (20 * pow(height, 2)) / 703;
		weightDiff = healthyWeight - weight;
		cout << "To reach a healthy BMI of 20, we recommend that you gain " << weightDiff << "pounds to reach a healthy weight of " << healthyWeight << "pounds. " << endl;
		/* create 3 month and 6 month weight loss goal. How many pounds to lose/gain each week */
	}
	else if (IsNormalWeight(BMI))
	{
		cout << "Since you are currently at a healthy weight, we recommend to maintain your current BMI. Fluctuation is normal, but as long as your BMI stays within the healthy range it is ok. " << endl;
	}
	else if (IsOverWeight(BMI))
	{
		cout << "Since you are currently overweight, we recommend losing enough weight to reach a healthy BMI." << endl;
		healthyWeight = (23 * pow(height, 2)) / 703;
		weightDiff = weight - healthyWeight;
		cout << "To reach a healthy BMI of 23, we recommend that you lose " << weightDiff << "pounds to reach a healthy weight of " << healthyWeight << "pounds. " << endl;
		/* create 3 month and 6 month weight loss goal. How many pounds to lose/gain each week */
	}
	else if (IsObese(BMI))
	{
		cout << "Since you are currently obese, we recommend losing enough weight to reach a healthy BMI. " << endl;
		cout << "Lsing enough weight o reach a healthy BMI might take awhile so we will break this plan up into two stages. Stage 1 will be to reach a BMI of 27 to be considered 'overweight'. Stage 2 will be to reach a healthy BMI of 23. " << endl;
		healthyWeight = (27 * pow(height, 2)) / 703;
		weightDiff = weight - healthyWeight;
		cout << "To reach an overweight BMI of 27, we recommend that you lose " << weightDiff << "pounds to reach a healthy weight of " << healthyWeight << "pounds. " << endl;
		/* create 3 month and 6 month weight loss goal. How many pounds to lose/gain each week */
		healthyWeight = (23 * pow(height, 2)) / 703;
		weightDiff = weight - healthyWeight;
		cout << "To reach a healthy BMI of 23, we recommend that you lose " << weightDiff << "pounds to reach a healthy weight of " << healthyWeight << "pounds. " << endl;
		/* create 3 month and 6 month weight loss goal. How many pounds to lose/gain each week */
	}
}
