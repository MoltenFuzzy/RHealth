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
	APIHandler* APIFunction = nullptr; 
	std::vector<std::string> DaysOfWeek = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

	std::string API_url = "";
	std::string API_token = "";

public:
	HealthPlan() {}
	virtual void Add() {}
	virtual void Remove() {}
	virtual void Print() {}
	virtual std::string getAPIurl() = 0; 
	virtual std::string getAPItoken() = 0; 

	void setAPIFunction(APIHandler* function) { this->APIFunction = function; }
};


#endif // HEALTH_PLAN
