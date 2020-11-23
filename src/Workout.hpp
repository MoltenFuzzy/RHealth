#ifndef WORKOUT
#define WORKOUT

#include "ExercisePlan.hpp"

class Workout : public ExercisePlan
{
	private:
		std::string workout_name;
	public:
		Workout(std::string name) : workout_name{name} {}
		std::string GetWorkoutName() { return workout_name; }

		void Print() {
			std::cout << workout_name; 
		}
};


#endif // WORKOUT