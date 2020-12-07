#ifndef WORKOUT
#define WORKOUT

#include "ExercisePlan.hpp"

class Workout : public ExercisePlan
{
	private:
		std::string name;
		std::string description;
	public:
		Workout(std::string n, std::string desc) : name{n}, description{desc} {}
		std::string GetName() { return name; }
		std::string GetDesc() { return description; }

		void Print() {
			std::cout << this->name; 
		}
};


#endif // WORKOUT