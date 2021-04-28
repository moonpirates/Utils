#pragma once

#include <iostream>
#include <any>
#include <map>
#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>
#include <typeinfo>
#include <typeindex>

#include "Event.h"
#include "../Macros/Macros.h"

namespace Utils
{
	class Dispatcher
	{
		typedef std::pair<std::function<void(std::any)>, void*> CallbackInfo;
		typedef std::vector<CallbackInfo> CallbackPairs;
		typedef std::unordered_map<std::type_index, CallbackPairs*> SubscriptionMap;

	public:
		Dispatcher() : subscriptionMap(std::make_unique<SubscriptionMap>()) {}

		template<typename T>
		void Subscribe(const std::function<void(T)> callback, void* context);
		template<typename T>
		void Unsubscribe(void* context);

		template<typename T>
		void Invoke(T e);
	
	private:
		std::unique_ptr<SubscriptionMap> subscriptionMap;

		CallbackPairs* TryGetCallbackPairs(const std::type_info& typeInfo)
		{
			return TryGetCallbackPairs(std::type_index(typeInfo));
		}

		CallbackPairs* TryGetCallbackPairs(const std::type_index typeIndex)
		{
			SubscriptionMap::iterator it = subscriptionMap->find(typeIndex);
			return it != subscriptionMap->end() ? it->second : nullptr;
		}
	};

	template<typename T>
	void Dispatcher::Subscribe(const std::function<void(T)> callback, void* context)
	{
		static_assert(std::is_base_of<Utils::Event, T>::value, "Type is restricted to event types only");

		const std::type_index typeIndex = std::type_index(typeid(T));
		CallbackPairs* callbackPairs = TryGetCallbackPairs(typeIndex);

		if (callbackPairs == nullptr)
		{
			std::cout << "Event is new!" << std::endl;
			callbackPairs = new CallbackPairs();
			subscriptionMap->emplace(typeIndex, callbackPairs);
		}

		std::function<void(std::any)> function = [callback](std::any e)
		{ 
			T t = std::any_cast<T>(e);
			callback(t); 
		};

		callbackPairs->push_back(CallbackInfo(function, context));

		std::cout << "[Sub] Size is now: " << subscriptionMap->size() << ", this info size: " << callbackPairs->size() << std::endl;
	}

	template<typename T>
	void Dispatcher::Unsubscribe(void* context)
	{
		static_assert(std::is_base_of<Utils::Event, T>::value, "Type is restricted to event types only");

		std::cout << "[Un BEFORE] Size is now: " << subscriptionMap->size() << std::endl;
		
		CallbackPairs* callbackPairs = TryGetCallbackPairs(typeid(T));

		if (callbackPairs == nullptr)
		{
			std::cout << "Was unable to unsubscribe, could not find subscription for '" << typeid(T).name() << "' with context: '" << context << std::endl;
			return;
		}

		// Remove all callback pairs which share the same context
		for (CallbackPairs::iterator it = callbackPairs->begin(); it != callbackPairs->end();)
		{
			if (it->second == context)
			{
				std::cout << "\tRemoving" << std::endl;
				CallbackInfo* info = &*it;
				it = callbackPairs->erase(it);
			}
			else
			{
				it++;
			}
		}

		// If there are no callbackpairs, we can remove the entire event type, and free memory.
		if (callbackPairs->size() == 0)
		{
			std::cout << "Clearing " << typeid(T).name() << " as it's no longer used" << std::endl;

			SubscriptionMap::iterator it = subscriptionMap->find(typeid(T));
			subscriptionMap->erase(it);
			delete(callbackPairs);
		}

		std::cout << "[Un AFTER] Size is now: " << (*subscriptionMap).size() << std::endl;
	}

	template<typename T>
	void Dispatcher::Invoke(T e)
	{
		static_assert(std::is_base_of<Utils::Event, T>::value, "Type is restricted to event types only");

		//LOG("Calling callback for event: ");
		//Utils::Logger::Log(LOG_LEVEL_DEFAULT, [auto &out]() { out << "type: " << "honk" }, "fileblah", 123);

		LOG("sup goobers");

		// Find whether the event is already registered in the map
		CallbackPairs* callbackPairs = TryGetCallbackPairs(typeid(e));

		if (callbackPairs == nullptr)
		{
			return;
		}

		for (CallbackPairs::iterator infoIterator = callbackPairs->begin(); infoIterator != callbackPairs->end(); infoIterator++)
		{
			std::function<void(std::any)> callback = infoIterator->first;
			callback(e);
		}
	}
}
