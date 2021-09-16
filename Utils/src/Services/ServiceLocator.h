#pragma once

#include <iostream>
#include <unordered_map>
#include <typeinfo>
#include "BaseService.h"

namespace Utils
{
	using ServiceMap = std::unordered_map<std::size_t, BaseService*>;

	class ServiceLocator final
	{
	public:
		ServiceLocator() : services(ServiceMap())
		{
		}
		
		~ServiceLocator()
		{
			for (auto pair : services)
			{
				delete pair.second;
			}
		}
		
		template <typename T>
		T& Get()
		{
			std::size_t key = typeid(T).hash_code();
			ServiceMap::iterator it = services.find(key);
			
			if (it != services.end())
			{
				return *(T*)(it->second);
			}
			
			T* service = new T();
			services.insert(std::pair<std::size_t, BaseService*>(key, service));
			
			return *service;
		}
		
	private:
		ServiceMap services;
	};
}
