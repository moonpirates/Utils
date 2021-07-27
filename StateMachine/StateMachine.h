#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "BaseCondition.h"
#include "BaseState.h"

namespace Utils
{
	using StateLink = std::pair<BaseCondition*, BaseState*>;
	using LinkMap = std::map<BaseState*, std::vector<StateLink>>;

	class StateMachine
	{
	public:
		StateMachine() : linkMap(LinkMap())
		{
			std::cout << "Initialized base statemachine" << std::endl;
		}
		
		~StateMachine()
		{
			for (auto stateEntry : linkMap)
			{
				delete stateEntry.first;
				for (auto stateLink : stateEntry.second)
				{
					delete stateLink.first;
				}
			}
		}
		
		template <typename StateType>
		StateType* CreateState()
		{
			StateType* state = new StateType();
			linkMap.insert(std::make_pair(state, std::vector<StateLink>()));
			
			return state;
		}
		
		template <typename ConditionType>
		void AddLink(BaseState* fromState, BaseState* toState) // const fromState?
		{
			LinkMap::iterator pair = linkMap.find(fromState);
			if (pair == linkMap.end())
			{
				std::cerr << "Unknown state" << std::endl;
				return;
			}
			
			pair->second.push_back(std::make_pair(new ConditionType(), toState));
		}
		
		void Start()
		{
			if (linkMap.size() == 0)
			{
				std::cerr << "Please add states." << std::endl;
				return;
			}
			
			Transit(linkMap.begin()->first);
			
			while (true)
			{
				std::optional<StateLink*> activeLink = PollLinks();
				
				if (activeLink.has_value())
				{
					BaseState* nextState = activeLink.value()->second;
					
					if (nextState != nullptr)
					{
						Transit(nextState);
					}
				}
				
				char c;
				std::cout << "Quit? y/n" << std::endl;
				std::cin >> c;
				if (c == 'y')
				{
					break;
				}
			}
		}

	protected:
		void Transit(BaseState* state)
		{
			if (linkMap.count(state) == 0)
			{
				std::cerr << "Unknown state" << std::endl;
				return;
			}
			
			if (currentState != nullptr)
			{
				for (auto stateLink : linkMap.at(currentState))
				{
					stateLink.first->OnDeactivate();
				}
				currentState->Exit();
			}
			
			currentState = state;
			currentState->Enter();
			for (auto stateLink : linkMap.at(currentState))
			{
				stateLink.first->OnActivate();
			}
		}

	private:
		LinkMap linkMap;
		BaseState* currentState;
		
		std::optional<StateLink*> PollLinks()
		{
			std::vector<StateLink>& links = linkMap.at(currentState);
			std::vector<StateLink>::iterator it = std::find_if(links.begin(),
															   links.end(),
															   [] (const StateLink& s) { return s.first->IsValid(); });
			
			if (it != links.end())
			{
				return std::addressof(*it);
			}
			
			return std::nullopt;
		}
	};
}
