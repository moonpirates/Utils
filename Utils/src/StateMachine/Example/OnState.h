#pragma once

#include <iostream>
#include "../BaseState.h"

class OnState : public Utils::BaseState
{
public:
	OnState();
	~OnState() override;
	void Enter() override;
	void Exit() override;
};
