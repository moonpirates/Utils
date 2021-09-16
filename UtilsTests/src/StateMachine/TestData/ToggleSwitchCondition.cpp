#include "ToggleSwitchCondition.h"

ToggleSwitchCondition::ToggleSwitchCondition() : valid(false)
{
	std::cout << "Created ToggleSwitchCondition" << std::endl;
}

ToggleSwitchCondition::~ToggleSwitchCondition()
{
	std::cout << "Destroyed ToggleSwitchCondition" << std::endl;
}

bool ToggleSwitchCondition::IsValid()
{
	return valid;
}

void ToggleSwitchCondition::SetValid()
{
	valid = true;
}
