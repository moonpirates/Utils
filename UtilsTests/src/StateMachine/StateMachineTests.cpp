#include <gtest/gtest.h>
#include "StateMachine/StateMachine.h"
#include "TestData/SwitchStateMachine.h"

TEST(StateMachine, StartsAtGivenState)
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

	EXPECT_EQ(switchStateMachine.CurrentState, switchStateMachine.StateOff);

	switchStateMachine.Stop();
}

TEST(StateMachine, ValidatingWrongConditionDoesntTransition)
{
	SwitchStateMachine switchStateMachine;
	switchStateMachine.Start(switchStateMachine.StateOn);
	switchStateMachine.FromOffToOnCondition->SetValid();
	switchStateMachine.Update();

	EXPECT_EQ(switchStateMachine.CurrentState, switchStateMachine.StateOn);

	switchStateMachine.Stop();
}