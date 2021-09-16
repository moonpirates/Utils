#pragma once

#include <iostream>
#include <vector>
#include "BaseCondition.h"

namespace Utils
{
	class BaseState
	{
	public:
		BaseState() : Name("Unnamed state") {}
		BaseState(const std::string name) : Name(name) {}
		virtual ~BaseState() {}
		virtual void Enter() = 0;
		virtual void Exit() = 0;
		std::string Name;
	};
}
