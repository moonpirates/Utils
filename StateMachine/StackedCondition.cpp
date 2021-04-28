#include "StackedCondition.h"

using namespace Utils;

StackedCondition::StackedCondition(std::vector<std::unique_ptr<BaseCondition>>&& conditions) : conditions(std::move(conditions))
{
	//LOG("Size constructor: " << this->conditions.size());
}

StackedCondition::~StackedCondition()
{
	//LOG("Size destructor: " << conditions.size());
}

bool StackedCondition::IsValid()
{
	//for (std::unique_ptr<BaseCondition>& condition : conditions)
	//{
	//	if (!condition->IsValid())
	//	{
	//		return false;
	//	}
	//}

	return true;
}
