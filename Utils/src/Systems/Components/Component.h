#pragma once

#include <iostream>
#include "Macros/Macros.h"

namespace Utils
{
	// Forward declaration to prevent circular dependency
	class GameObject; 
	class Transform; 

	class Component
	{
	public:
		GameObject* GameObject;
		Transform* Transform;
		
		Component() :
			GameObject(nullptr), Transform(nullptr)
		{

		}

		virtual ~Component() {};
	};

}