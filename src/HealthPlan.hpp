#ifndef HEALTH_PLAN
#define HEALTH_PLAN

#include <string>

class HealthPlan
{
private:
public:
	HealthPlan() {}
	virtual void Add() {}
	virtual void Remove() {}
	virtual void Print() {}
};


#endif // HEALTH_PLAN
