#pragma once

#include <iostream>
#include "../GameObject.h"

namespace Utils
{
	class Scene
	{
	public:
		Scene();
		GameObject* AddGameObject(const std::string& name);
		void RemoveGameObject(GameObject* gameObject);
		GameObject* GetRoot();
		void PrintHierarchy();

	private:
		GameObject* rootGameObject;
		void PrintHierarchy(GameObject* gameObject, size_t depth);
	};
}