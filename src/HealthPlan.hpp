#ifndef HEALTH_PLAN
#define HEALTH_PLAN

#include <string>
#include <vector>
#include <stdexcept>

#include "APIHandler.hpp"

class APIHandler;

class HealthPlan
{
private:
protected:
	int age = 0;
	std::string sex;
	double height = 0;
	double weight = 0;

	double BMI = 0;

	APIHandler *APIFunction = nullptr;
	std::vector<std::string> DaysOfWeek = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

	std::string API_url = "";
	std::string API_token = "";

public:
	HealthPlan() {}
	HealthPlan(int age, std::string sex, double weight, double height) : age{age}, sex{sex}, weight{weight}, height{height} {}
	virtual void Add() {}
	virtual void Remove() {}
	virtual void Print(std::ostream &outs) {}
	virtual std::string getAPIurl() = 0;
	virtual std::string getAPItoken() = 0;

	double getBMI() { return this->BMI; }

	void setAPIFunction(APIHandler *function) { this->APIFunction = function; }

	double CalcBMI(double weight, double height)
	{
		BMI = weight / pow(height / 100, 2);
		return BMI;
	}

	bool IsUnderWeight(double BMI) { return BMI <= 18.5; }
	bool IsNormalWeight(double BMI) { return 18.5 < BMI && BMI < 24.9; }
	bool IsOverWeight(double BMI) { return 25.0 < BMI && BMI < 29.9; }
	bool IsObese(double BMI) { return BMI >= 30.0; }
};

#endif // HEALTH_PLAN
