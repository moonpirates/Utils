#pragma once

#include "ServiceLocator.h"

namespace Utils
{
	class GlobalServiceLocator
	{
	public:
		// Prevent copies
		GlobalServiceLocator(const GlobalServiceLocator&) = delete;
		void operator=(const GlobalServiceLocator&) = delete;
		
		template <typename T>
		static T& Get()
		{
			return GetInstance().Get<T>();
		}
		
	private:
		GlobalServiceLocator() {};
		
		static Utils::ServiceLocator& GetInstance()
		{
			static ServiceLocator instance;
			return instance;
		}
	};
}
