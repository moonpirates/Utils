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

	private:
		GameObject* rootGameObject;
	};
}