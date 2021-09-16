#pragma once

#include <iostream>
#include <StateMachine/BaseCondition.h>

class ToggleSwitchCondition : public Utils::BaseCondition
{
public:
	ToggleSwitchCondition();
	~ToggleSwitchCondition() override;
	bool IsValid() override;
	void SetValid();
private:
	bool valid;
};
