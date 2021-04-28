#pragma once

#include <iostream>
#include <vector>

#include "BaseCondition.h"
#include "BaseState.h"

namespace Utils
{
	class StateMachine
	{
	public:
		StateMachine();

	protected:
		std::vector<BaseState> states;

		virtual void AddState(BaseState& state);
		//virtual void RemoveState(BaseState& state);
		//virtual void AddCondition(BaseState& fromState, BaseState& toState, BaseCondition& condition);
		//virtual void RemoveCondition(BaseCondition& condition);
	};
}
