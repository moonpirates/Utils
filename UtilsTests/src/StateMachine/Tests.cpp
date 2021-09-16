#include <gtest/gtest.h>
#include "StateMachine/StateMachine.h"
#include "TestData/SwitchStateMachine.h"


TEST(StateMachine, StartsWithFirstAddedState)
{
	SwitchStateMachine switchStateMachine;
	switchStateMachine.Start(switchStateMachine.StateOn);

	EXPECT_EQ(switchStateMachine.CurrentState, switchStateMachine.StateOn);

	switchStateMachine.Stop();
}


TEST(StateMachine, ValidConditionTransitionsCorrectly)
{
	SwitchStateMachine switchStateMachine;
	switchStateMachine.Start(switchStateMachine.StateOn);

	switchStateMachine.FomOnToOffCondition->SetValid();

	switchStateMachine.Update();
	std::cout << "SLEEP" << std::endl;

	EXPECT_EQ(switchStateMachine.CurrentState, switchStateMachine.StateOff);

	switchStateMachine.Stop();
}