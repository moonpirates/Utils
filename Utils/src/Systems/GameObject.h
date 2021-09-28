#pragma once

#include <iostream>
#include "Macros/Macros.h"
#include "Components/Components.h"
#include "Components/Transform.h"
#include "Services/GlobalServiceLocator.h"

namespace Utils
{
	class GameObject
	{
	public:
		std::string Name;
		GameObject* Parent;

		GameObject(const std::string name) : 
			transform(components.AddComponent<Utils::Transform>()), Name(name), Parent(nullptr)
		{
		}

		~GameObject()
		{
		}

		template <typename T>
		T* AddComponent()
		{
			T* component = components.AddComponent<T>();
			component->GameObject = this;
			component->Transform = transform;
			return component;
		}

		template <typename T>
		T* GetComponent()
		{
			return components.GetComponent<T>();
		}

		GameObject* AddChild(const std::string& name)
		{
			GameObject* child = children.emplace_back(new GameObject(name));
			child->Parent = this;

			return child;
		}

		void RemoveChild(GameObject* child)
		{
			bool foundAndRemoved = std::remove(children.begin(), children.end(), child) != children.end();

			if (foundAndRemoved)
			{
				delete child;
			}
		}

		GameObject* GetChildAtIndex(const size_t index)
		{
			if (index < children.size())
			{
				return children[index];
			}
			
			return nullptr;
		}

		size_t GetNumChildren()
		{
			return children.size();
		}

		const std::vector<Utils::Component*> GetAllComponents()
		{
			return components.GetComponents<Utils::Component>(true);
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
		std::vector<GameObject*> children;
	};
}