#pragma once

#include <iostream>
#include "Macros/Macros.h"
#include "Components/Components.h"
#include "Components/Transform.h"

namespace Utils
{
	class GameObject
	{
	public:
		GameObject() : 
			transform(components.AddComponent<Utils::Transform>())
		{
		}

		~GameObject()
		{
		}

		template <typename T>
		T* AddComponent()
		{
			return components.AddComponent<T>();
		}

		template <typename T>
		T* GetComponent()
		{
			return components.GetComponent<T>();
		}

		template <typename T>
		std::vector<T*> GetComponents(bool includeDerived = true)
		{
			return components.GetComponents<T>(includeDerived);
		}

		void RemoveComponent(Component* component)
		{
			components.RemoveComponent(component);
		}

	private:
		Components components;
		Transform* transform;
	};
}