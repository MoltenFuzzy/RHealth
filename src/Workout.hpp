#ifndef WORKOUT
#define WORKOUT

#include "ExercisePlan.hpp"

class Workout : public ExercisePlan
{
	private:
		std::string name;
		std::string description;
	public:
		Workout(std::string n) : name{n} {}
		std::string GetName() { return name; }

		void Print() {
			std::cout << this->name; 
		}
};


#endif // WORKOUT