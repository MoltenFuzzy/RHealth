#ifndef DAILYEXERCISES
#define DAILYEXERCISES

#include "ExercisePlan.hpp" 

class DailyExercise : public ExercisePlan{
private:
	std::vector<ExercisePlan*> daily_exercises; 
public: 
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

};

#endif // DAILYEXERCISES