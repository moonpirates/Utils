#include "BaseState.h"

Utils::BaseState::BaseState() :
	links(std::vector<std::pair<BaseCondition*, BaseState*>>()), name("Unnamed")
{
}

void Utils::BaseState::AddLink(BaseCondition* condition, BaseState* toState)
{
	links.push_back(std::pair<BaseCondition*, BaseState*>(condition, toState));
}

Utils::BaseState* Utils::BaseState::PollLinks()
{
	for (auto link : links)
	{
		if (link.first->IsValid())
		{
			return link.second;
		}
	}
	
	return nullptr;
}
