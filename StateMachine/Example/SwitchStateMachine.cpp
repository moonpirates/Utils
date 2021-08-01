#include "SwitchStateMachine.h"

SwitchStateMachine::SwitchStateMachine() : Utils::StateMachine()
{
	OnState& onState = CreateState<OnState>();
	OffState& offState = CreateState<OffState>();
	
	AddLink<ToggleSwitchCondition>(onState, offState);
	AddLink<ToggleSwitchCondition>(offState, onState);
	
	Start();
}
