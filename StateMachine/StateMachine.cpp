#include "StateMachine.h"

using namespace Utils;

StateMachine::StateMachine() : states(std::vector<BaseState>())
{
}

void StateMachine::AddState(BaseState& state)
{
	//states.emplace_back(state);
}
