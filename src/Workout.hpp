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
		std::string GetWorkoutName() { return name; }

		void Print() {
			std::cout << this->name << std::endl;
		}
};


#endif // WORKOUT