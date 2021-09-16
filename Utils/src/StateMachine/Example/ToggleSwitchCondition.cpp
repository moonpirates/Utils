#include "ToggleSwitchCondition.h"

ToggleSwitchCondition::ToggleSwitchCondition()
{
	std::cout << "Created ToggleSwitchCondition" << std::endl;
}

ToggleSwitchCondition::~ToggleSwitchCondition()
{
	std::cout << "Destroyed ToggleSwitchCondition" << std::endl;
}

bool ToggleSwitchCondition::IsValid()
{
	std::cout << "Type 's' to switch: ";
	std::string input;
	std::cin >> input;
	
	return input == "s";
}
