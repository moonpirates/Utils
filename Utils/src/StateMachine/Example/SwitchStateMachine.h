#pragma once

#include <iostream>
#include "../StateMachine.h"
#include "OnState.h"
#include "OffState.h"
#include "ToggleSwitchCondition.h"

class SwitchStateMachine : public Utils::StateMachine
{
public:
	SwitchStateMachine();
};
