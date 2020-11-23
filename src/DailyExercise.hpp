#ifndef DAILYEXERCISES
#define DAILYEXERCISES

#include "ExercisePlan.hpp" 
#include "Workout.hpp"

class DailyExercise : public ExercisePlan{
private:
	std::vector<ExercisePlan*> daily_exercises; 
public: 
	void CreateDailyExercises() {
		// TODO: CREATE STRATEGY CLASS FOR API
		// SO ONLY CALL ONCE
		RequestAPI();

		for(auto exercise : GetExerciseData()) {
			Add(new Workout(exercise["name"].get<std::string>())); 
			// std::cout << exercise["name"].get<std::string>() << std::endl;

			// WORKS
			//Workout* test = new Workout(exercise["name"].get<std::string>());
			//std::cout << test->GetWorkoutName() << std::endl;
		}

	}

	std::vector<ExercisePlan*> GetDailyExercises() { return this->daily_exercises; }

	void Add(ExercisePlan* e) {
		daily_exercises.push_back(e); 
	} 

	void Remove(ExercisePlan* e) {
		
	} 

	void Print() {
		for(auto e : daily_exercises) {
			e->Print();
			std::cout << std::endl;
		}
	} 

	int size() { return daily_exercises.size(); }

};

#endif // DAILYEXERCISES