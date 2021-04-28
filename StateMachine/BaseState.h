#pragma once

#include <iostream>

namespace Utils
{
	class BaseState
	{
	public:
		virtual void Enter() = 0;
		virtual void Exit() = 0;
	private:
		std::string name;
	};
}
