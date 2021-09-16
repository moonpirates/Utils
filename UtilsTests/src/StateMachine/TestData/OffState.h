#pragma once

#include <iostream>
#include <StateMachine/BaseState.h>

class OffState : public Utils::BaseState
{
public:
	OffState();
	~OffState() override;
	void Enter() override;
	void Exit() override;
};
