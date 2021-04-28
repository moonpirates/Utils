#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include <Utils/Macros/Macros.h>
#include "BaseCondition.h"

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

