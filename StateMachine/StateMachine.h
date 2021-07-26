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
		std::vector<BaseState*> states;
		BaseState* currentState;

		virtual void AddState(BaseState* state);
		
		//virtual void RemoveState(const BaseState& state);
		//virtual void RemoveCondition(BaseCondition& condition);
		
		void Transit(BaseState* state);
//		void AddTransition(TransitionInfo transitionInfo);
	};
}
