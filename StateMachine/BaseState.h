#pragma once

#include <iostream>
#include <vector>
#include "BaseCondition.h"

namespace Utils
{
	class BaseState
	{
	public:
		BaseState() : name("Unnamed state") {}
		BaseState(const std::string name) : name(name) {}
		virtual ~BaseState() {}
		virtual void Enter() = 0;
		virtual void Exit() = 0;
	private:
		std::string name;
	};
}
