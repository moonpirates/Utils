#pragma once

#include <iostream>
#include "../BaseCondition.h"

class ToggleSwitchCondition : public Utils::BaseCondition
{
public:
	ToggleSwitchCondition();
	~ToggleSwitchCondition() override;
	bool IsValid() override;
};
