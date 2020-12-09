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

			// Remove paragraph tags <p> </p>
			while (exercise_desc.find("<") != std::string::npos)
			{
				auto startpos = exercise_desc.find("<");
				auto endpos = exercise_desc.find(">") + 1;

				if (endpos != std::string::npos)
				{
					exercise_desc.erase(startpos, endpos - startpos);
				}
			}

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
		// bool found_it = it != routines.end();
		if (it != routines.end())
		{
			routines.erase(it);
		}
	}

	// RETURNS NULLPTR IF NONE FOUND
	ExercisePlan *Search(std::string key)
	{
		for (const auto &x : routines)
		{
			PairVector daily_routines = static_cast<Routine *>(x.second)->GetRoutines();
			for (const auto &y : daily_routines)
			{
				if (y.first == key)
				{
					return y.second;
				}
			}
		}
		return nullptr;
	}

	void Print(std::ostream &outs)
	{
		for (auto routine : routines)
		{
			// Only print if the key is a day of the week
			if (std::find(DaysOfWeek.begin(), DaysOfWeek.end(), routine.first) != DaysOfWeek.end())
			{
				outs << routine.first << std::endl;
			}

			routine.second->Print(outs);
			outs << std::endl;
		}
	}

	size_t Size()
	{
		return routines.size();
	}

	PairVector GetRoutines()
	{
		return this->routines;
	}
};

#endif // ROUTINE