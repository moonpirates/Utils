#pragma once

namespace Utils
{
	class BaseCondition
	{
	public:
		virtual ~BaseCondition() {};
		virtual bool IsValid() = 0;
		virtual void OnActivate() {}
		virtual void OnDeactivate() {}
	};
}
