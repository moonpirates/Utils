#include "OnState.h"

OnState::OnState() : Utils::BaseState("On state")
{
	std::cout << "Created ON state" << std::endl;
}

OnState::~OnState()
{
	std::cout << "Destroyed ON state" << std::endl;
}

void OnState::Enter()
{
	std::cout << "Entering ON" << std::endl;
}

void OnState::Exit()
{
	std::cout << "Leaving ON" << std::endl;
}
