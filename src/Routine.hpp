#ifndef ROUTINE
#define ROUTINE

#include "ExercisePlan.hpp" 
#include "Workout.hpp"

class Routine : public ExercisePlan{
private:
	typedef std::vector<std::pair<std::string, ExercisePlan*>> PairVector;
	// Using vector of pairs to keep insertion order, but still have key, value pairs
	PairVector routines; 

public: 
	void AddWorkoutsFromJSON(json workouts) {
		// TODO: CREATE STRATEGY CLASS FOR API
		// SO ONLY CALL ONCE

		ExerciseData = workouts; 

		for(auto exercise : ExerciseData) {
			std::string exercise_name = exercise["name"].get<std::string>();
			Add(exercise_name, new Workout(exercise_name)); 

			// std::cout << exercise["name"].get<std::string>() << std::endl;
			// WORKS
			//Workout* test = new Workout(exercise["name"].get<std::string>());
			//std::cout << test->GetWorkoutName() << std::endl;
		}

	}

	void Add(std::string key, ExercisePlan* value) {
		routines.push_back(std::make_pair(key, value)); 
	} 

	void Remove(std::string key, ExercisePlan* value) {
		//routines.erase(routines.begin() + index);
	} 

	void Print() {
		int counter = 0; 
		for(auto routine : routines) {
			// Only print if the key is a day of the week
			if (std::find(DaysOfWeek.begin(), DaysOfWeek.end(), routine.first) != DaysOfWeek.end()) {
				std::cout << routine.first << std::endl; 
			}

			routine.second->Print();
			std::cout << std::endl;
			counter++;
		}
	} 

	size_t Size() { return routines.size(); }

	PairVector GetRoutines() { return this->routines; } 

};

#endif // ROUTINE