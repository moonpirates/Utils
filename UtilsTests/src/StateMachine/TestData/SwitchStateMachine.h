#pragma once

#include <iostream>
#include "StateMachine/StateMachine.h"
#include "OnState.h"
#include "OffState.h"
#include "ToggleSwitchCondition.h"

class SwitchStateMachine : public Utils::StateMachine
{
public:
	OnState* StateOn = CreateState<OnState>();
	OffState* StateOff = CreateState<OffState>();
	ToggleSwitchCondition* FomOnToOffCondition = AddLink<ToggleSwitchCondition>(StateOn, StateOff);
	ToggleSwitchCondition* FromOffToOnCondition = AddLink<ToggleSwitchCondition>(StateOff, StateOn);
};
