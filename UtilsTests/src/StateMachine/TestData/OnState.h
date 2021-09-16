#pragma once

#include <iostream>
#include <StateMachine/BaseState.h>

class OnState : public Utils::BaseState
{
public:
	OnState();
	~OnState() override;
	void Enter() override;
	void Exit() override;
};
