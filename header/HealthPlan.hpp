#ifndef HEALTH_PLAN
#define HEALTH_PLAN

#include <string>
#include <vector>

class HealthPlan
{
private:
protected: 
	std::vector<std::string> DaysOfWeek = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
public:
	HealthPlan() {}
	virtual void Add() {}
	virtual void Remove() {}
	virtual void Print() {}
};


#endif // HEALTH_PLAN
