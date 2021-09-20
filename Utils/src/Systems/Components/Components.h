#pragma once

#include <iostream>
#include <vector>
#include "Macros/Macros.h"
#include "Component.h"

namespace Utils
{
	class Components
	{
	public:
		using ComponentPair = std::pair<size_t, Utils::Component*>;
		using ComponentMap = std::vector<ComponentPair>;

		Components()
		{
		}

		~Components()
		{
			for (ComponentPair componentPair : components)
			{
				delete componentPair.second;
			}
		}

		template <typename T>
		T* AddComponent()
		{
			T* t = new T();
			components.emplace_back(ComponentPair(GetTypeHash<T>(), t));
			
			return t;
		}

		template <typename T>
		T* GetComponent()
		{
			std::size_t typeHash = GetTypeHash<T>();

			for (ComponentPair& componentPair : components)
			{
				if (componentPair.first == typeHash)
				{
					T* c = dynamic_cast<T*>(componentPair.second);
					return c;
				}
			}

			return nullptr;
		}

		template <typename T>
		std::vector<T*> GetComponents(bool includeDerived = true)
		{
			std::vector<T*> componentsOfType;
			std::size_t typeHash = GetTypeHash<T>();

			for (const ComponentPair& componentPair : components)
			{
				if (componentPair.first == typeHash || includeDerived)
				{
					T* castComponent = dynamic_cast<T*>(componentPair.second);

					if (castComponent != nullptr)
					{
						componentsOfType.push_back(castComponent);
					}
				}
			}

			return componentsOfType;
		}

		void RemoveComponent(Component* component)
		{
			ComponentMap::iterator it = std::find_if(components.begin(), 
				components.end(), 
				[component](const ComponentPair& pair) { return pair.second == component; });
			
			if (it != components.end())
			{
				components.erase(it);
			}
		}

	private:
		ComponentMap components;
	};
}