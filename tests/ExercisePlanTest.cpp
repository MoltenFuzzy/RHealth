#include "gtest/gtest.h"

#include "../src/ExercisePlan.hpp"
#include "../src/Workout.hpp"
#include "../src/Routine.hpp"
#include "../src/HealthApp.hpp"

//TODO: create more unit tests

TEST(ExercisePlanTest, AddElementLeafTest)
{
	std::string workout1 = "Push Ups";
	std::string workout2 = "Sit Ups";
	std::string workout3 = "10k Run";

	Workout *PushUps = new Workout(workout1, "");
	Workout *SitUps = new Workout(workout2, "");
	Workout *TenK_run = new Workout(workout3, "");

	Routine *test_plan = new Routine();

	test_plan->Add(workout1, PushUps);
	ASSERT_EQ(test_plan->Size(), 1);
	test_plan->Add(workout2, SitUps);
	test_plan->Add(workout3, TenK_run);
	EXPECT_EQ(test_plan->GetRoutines().at(0).first, workout1);
	EXPECT_EQ(test_plan->GetRoutines().at(1).first, workout2);
	EXPECT_EQ(test_plan->GetRoutines().at(2).first, workout3);
}

TEST(ExercisePlanTest, AddTreeTest)
{
	std::string workout1 = "Push Ups";
	std::string workout2 = "Sit Ups";
	std::string workout3 = "10k Run";

	Workout *PushUps = new Workout(workout1, "");
	Workout *SitUps = new Workout(workout2, "");
	Workout *TenK_run = new Workout(workout3, "");

	Routine *MondayPlan = new Routine();
	Routine *TuesdayPlan = new Routine();

	Routine *WeeklyPlanTest = new Routine();

	MondayPlan->Add(workout1, PushUps);
	ASSERT_EQ(MondayPlan->Size(), 1);
	MondayPlan->Add(workout2, SitUps);
	MondayPlan->Add(workout3, TenK_run);

	TuesdayPlan->Add(workout1, PushUps);
	ASSERT_EQ(TuesdayPlan->Size(), 1);
	TuesdayPlan->Add(workout2, SitUps);
	TuesdayPlan->Add(workout3, TenK_run);

	std::string day1 = "monday";
	std::string day2 = "tuesday";

	WeeklyPlanTest->Add(day1, MondayPlan);
	ASSERT_EQ(WeeklyPlanTest->Size(), 1);
	WeeklyPlanTest->Add(day2, TuesdayPlan);

	EXPECT_EQ(WeeklyPlanTest->GetRoutines().at(0).first, day1);
	EXPECT_EQ(WeeklyPlanTest->GetRoutines().at(1).first, day2);

	EXPECT_EQ(WeeklyPlanTest->GetRoutines().at(0).second, MondayPlan);
	EXPECT_EQ(WeeklyPlanTest->GetRoutines().at(1).second, TuesdayPlan);
}

TEST(ExercisePlanTest, RemoveElementTest)
{
	std::string workout1 = "Push Ups";
	std::string workout2 = "Sit Ups";
	std::string workout3 = "10k Run";

	Workout *PushUps = new Workout(workout1, "");
	Workout *SitUps = new Workout(workout2, "");
	Workout *TenK_run = new Workout(workout3, "");

	Routine *test_plan = new Routine();

	// Adding
	test_plan->Add(workout1, PushUps);
	ASSERT_EQ(test_plan->Size(), 1);
	test_plan->Add(workout2, SitUps);
	test_plan->Add(workout3, TenK_run);
	EXPECT_EQ(test_plan->GetRoutines().at(0).first, workout1);
	EXPECT_EQ(test_plan->GetRoutines().at(1).first, workout2);
	EXPECT_EQ(test_plan->GetRoutines().at(2).first, workout3);

	// Removing
	test_plan->Remove(workout1, PushUps);
	test_plan->Remove(workout2, SitUps);
	test_plan->Remove(workout3, TenK_run);

	EXPECT_EQ(test_plan->Size(), 0);
}

TEST(ExercisePlanTest, RemoveTreeTest)
{
	std::string workout1 = "Push Ups";
	std::string workout2 = "Sit Ups";
	std::string workout3 = "10k Run";

	Workout *PushUps = new Workout(workout1, "");
	Workout *SitUps = new Workout(workout2, "");
	Workout *TenK_run = new Workout(workout3, "");

	Routine *MondayPlan = new Routine();
	Routine *TuesdayPlan = new Routine();

	Routine *WeeklyPlanTest = new Routine();

	// Adding
	MondayPlan->Add(workout1, PushUps);
	ASSERT_EQ(MondayPlan->Size(), 1);
	MondayPlan->Add(workout2, SitUps);
	MondayPlan->Add(workout3, TenK_run);

	TuesdayPlan->Add(workout1, PushUps);
	ASSERT_EQ(TuesdayPlan->Size(), 1);
	TuesdayPlan->Add(workout2, SitUps);
	TuesdayPlan->Add(workout3, TenK_run);

	std::string day1 = "monday";
	std::string day2 = "tuesday";

	WeeklyPlanTest->Add(day1, MondayPlan);
	ASSERT_EQ(WeeklyPlanTest->Size(), 1);
	WeeklyPlanTest->Add(day2, TuesdayPlan);

	EXPECT_EQ(WeeklyPlanTest->GetRoutines().at(0).first, day1);
	EXPECT_EQ(WeeklyPlanTest->GetRoutines().at(1).first, day2);

	EXPECT_EQ(WeeklyPlanTest->GetRoutines().at(0).second, MondayPlan);
	EXPECT_EQ(WeeklyPlanTest->GetRoutines().at(1).second, TuesdayPlan);

	// Removing
	WeeklyPlanTest->Remove(day1, MondayPlan);
	WeeklyPlanTest->Remove(day2, TuesdayPlan);

	EXPECT_EQ(WeeklyPlanTest->Size(), 0);
}

TEST(ExercisePlanTest, SearchTreeTest)
{
	std::string workout1 = "Push Ups";
	std::string workout2 = "Sit Ups";
	std::string workout3 = "10k Run";

	Workout *PushUps = new Workout(workout1, "");
	Workout *SitUps = new Workout(workout2, "");
	Workout *TenK_run = new Workout(workout3, "");

	Routine *MondayPlan = new Routine();
	Routine *TuesdayPlan = new Routine();

	Routine *WeeklyPlanTest = new Routine();

	// Adding
	MondayPlan->Add(workout1, PushUps);
	ASSERT_EQ(MondayPlan->Size(), 1);
	MondayPlan->Add(workout2, SitUps);
	MondayPlan->Add(workout3, TenK_run);

	TuesdayPlan->Add(workout1, PushUps);
	ASSERT_EQ(TuesdayPlan->Size(), 1);
	TuesdayPlan->Add(workout2, SitUps);
	TuesdayPlan->Add(workout3, TenK_run);

	std::string day1 = "monday";
	std::string day2 = "tuesday";

	WeeklyPlanTest->Add(day1, MondayPlan);
	ASSERT_EQ(WeeklyPlanTest->Size(), 1);
	WeeklyPlanTest->Add(day2, TuesdayPlan);

	// Should return ptr to a workout
	EXPECT_EQ(WeeklyPlanTest->Search("Push Ups"), PushUps);
	EXPECT_EQ(WeeklyPlanTest->Search("Sit Ups"), SitUps);
}