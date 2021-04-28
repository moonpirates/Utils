#pragma once
namespace Utils
{
	class BaseCondition
	{
	public:
		virtual bool IsValid() = 0;
	};
}