#include "OffState.h"

OffState::OffState() : Utils::BaseState()
{
	std::cout << "Created OFF state" << std::endl;
}

OffState::~OffState()
{
	std::cout << "Destroyed OFF state" << std::endl;
}

void OffState::Enter()
{
	std::cout << "Entering OFF" << std::endl;
}

void OffState::Exit()
{
	std::cout << "Leaving OFF" << std::endl;
}
