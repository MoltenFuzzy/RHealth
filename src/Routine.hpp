#ifndef ROUTINE
#define ROUTINE

#include "ExercisePlan.hpp"
#include "Workout.hpp"

class Routine : public ExercisePlan
{
private:
	typedef std::vector<std::pair<std::string, ExercisePlan *>> PairVector;
	// Using vector of pairs to keep insertion order, but still have key, value pairs
	PairVector routines;

public:
	Routine() {}
	Routine(int age, std::string sex, double weight, double height) : HealthPlan(age, sex, weight, height) {}
	Routine(PairVector r) : routines{r} {}

	void AddWorkoutsFromJSON(const json &workouts)
	{
		// ExerciseData = workouts;

		for (auto workout : workouts)
		{
			std::string exercise_name = workout["name"].get<std::string>();
			std::string exercise_desc = workout["description"].get<std::string>();
			Add(exercise_name, new Workout(exercise_name, exercise_desc));

			// std::cout << exercise["name"].get<std::string>() << std::endl;
			// WORKS
			//Workout* test = new Workout(exercise["name"].get<std::string>());
			//std::cout << test->GetWorkoutName() << std::endl;
		}
	}

	void Add(std::string key, ExercisePlan *value)
	{
		routines.push_back(std::make_pair(key, value));
	}

	void Remove(std::string key, ExercisePlan *value)
	{
		PairVector::iterator it = std::find(routines.begin(), routines.end(), std::make_pair(key, value));
		bool found_it = it != routines.end();
		if (found_it)
		{
			routines.erase(it);
		}
	}

	void Print()
	{
		for (auto routine : routines)
		{
			// Only print if the key is a day of the week
			if (std::find(DaysOfWeek.begin(), DaysOfWeek.end(), routine.first) != DaysOfWeek.end())
			{
				std::cout << routine.first << std::endl;
			}

			routine.second->Print();
			std::cout << std::endl;
		}
	}

	size_t Size() { return routines.size(); }

	PairVector GetRoutines() { return this->routines; }
};

#endif // ROUTINE