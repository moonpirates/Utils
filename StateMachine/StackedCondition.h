#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include "BaseCondition.h"
#include "../Macros/Macros.h"


namespace Utils
{
	class StackedCondition : public BaseCondition
	{
	public:
		StackedCondition() = delete;
		StackedCondition(std::vector<std::unique_ptr<BaseCondition>>&& conditions);
		~StackedCondition();

		bool IsValid();

	private:
		std::vector<std::unique_ptr<BaseCondition>> conditions;
	};
}

