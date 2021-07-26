#include "StateMachine.h"

using namespace Utils;

StateMachine::StateMachine() : states(std::vector<BaseState*>())
{
	std::cout << "Initialized base statemachine" << std::endl;
}

void StateMachine::AddState(BaseState* state)
{
	states.emplace_back(state);
}

void StateMachine::Transit(BaseState* state)
{
	if (currentState != nullptr)
	{
		currentState->Exit();
	}
	
	currentState = state;
	currentState->Enter();
	BaseState* nextState = currentState->PollLinks();
	
	if (nextState != nullptr)
	{
		Transit(nextState);
	}
}
