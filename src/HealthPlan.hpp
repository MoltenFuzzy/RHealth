#ifndef _HEALTHPLAN_HPP_
#define _HEALTHPLAN_HPP_

#include <string>

class HealthPlan {
	private:
		/* data */
		int age;
		string sex;
		double weight;
		double height;

	public:
		/* Constructor(s) */
		HealthPlan() { };
	
		/* Destructor */
		~HealthPlan();
};

#endif
