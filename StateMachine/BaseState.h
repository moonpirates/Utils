#pragma once

#include <iostream>
#include <vector>
#include "BaseCondition.h"

namespace Utils
{
//class BaseState;
//typedef std::pair<BaseCondition*, BaseState*> StateLink;

	class BaseState
	{
	public:
		BaseState();
		virtual void Enter() = 0;
		virtual void Exit() = 0;
		void AddLink(BaseCondition* condition, BaseState* toState);
		BaseState* PollLinks();
	private:
		std::string name;
		std::vector<std::pair<BaseCondition*, BaseState*>> links;
	};
}
