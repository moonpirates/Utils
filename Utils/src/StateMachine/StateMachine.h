#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <optional>

#include "BaseCondition.h"
#include "BaseState.h"
#include "Systems/Updatable.h"
#include "Systems/CallbackService.h"
#include "Services/GlobalServiceLocator.h"

namespace Utils
{
	using StateLink = std::pair<BaseCondition*, BaseState*>;
	using LinkMap = std::map<BaseState*, std::vector<StateLink>>;

	class StateMachine : public Updatable
	{
	public:
		BaseState* CurrentState;

		StateMachine() : linkMap(LinkMap()), CurrentState(nullptr), callbackService(Utils::GlobalServiceLocator::Get<CallbackService>()), running(false)
		{
			std::cout << "Initialized base state machine" << std::endl;
		}
		
		virtual ~StateMachine()
		{
			if (running)
			{
				Stop();
			}

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
			
			std::cout << "State created at " << state << std::endl;
			
			return state;
		}
		
		template <typename ConditionType>
		ConditionType* AddLink(BaseState* fromState, BaseState* toState) // const fromState?
		{
			std::cout << "Finding state at " << fromState << std::endl;

			LinkMap::iterator pair = linkMap.find(fromState);
			if (pair == linkMap.end())
			{
				std::cerr << "Unknown state" << std::endl;
				return nullptr;
			}
			ConditionType* condition = new ConditionType();

			pair->second.push_back(std::make_pair(condition, toState));

			return condition;
		}
		
		void Start(BaseState* initialState)
		{
			if (running)
			{
				LOG_ERROR("State machine is already running.");
				return;
			}

			if (linkMap.size() == 0)
			{
				LOG_ERROR("Please add states.");
				return;
			}
			
			Transit(initialState);

			callbackService.AddUpdatable(*this);

			running = true;
		}

		void Stop()
		{
			if (!running)
			{
				LOG_ERROR("Tried to stop a non running state machine.");
				return;
			}

			callbackService.RemoveUpdatable(*this);
			running = false;
		}

		void Update()
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
		}

	protected:
		void Transit(BaseState* state)
		{
			if (linkMap.count(state) == 0)
			{
				std::cerr << "Unknown state" << std::endl;
				return;
			}
			
			if (CurrentState != nullptr)
			{
				for (auto stateLink : linkMap.at(CurrentState))
				{
					stateLink.first->OnDeactivate();
				}
				CurrentState->Exit();
			}
			
			CurrentState = state;
			CurrentState->Enter();
			for (auto stateLink : linkMap.at(CurrentState))
			{
				stateLink.first->OnActivate();
			}
		}

	private:
		LinkMap linkMap;
		Utils::CallbackService callbackService;
		bool running;
		
		std::optional<StateLink*> PollLinks()
		{
			std::vector<StateLink>& links = linkMap.at(CurrentState);
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
