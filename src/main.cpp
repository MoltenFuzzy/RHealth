#include <iostream>
#include "ExercisePlan.hpp"
#include "DailyExercise.hpp"
#include "Workout.hpp"

int main()
{	
	ExercisePlan de;

	// TODO: get string from key
	for(auto exercise : de.GetExerciseData()) {
		de.Add(new Workout(exercise["name"].get<std::string>())); 
	}

	//std::cout << de.GetExerciseData()[1].value(); 
	// for (json::iterator it = de.GetExerciseData().begin(); it != de.GetExerciseData().end(); ++it) {
	// 	std::cout << it.key() << " : " << it.value() << "\n";
	// }

	//de.Print(); 

	return 0;
}
