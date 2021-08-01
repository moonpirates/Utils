#pragma once

#include <iostream>
#include <unordered_map>
#include <typeinfo>
#include "BaseService.h"

namespace Utils
{
	using ServiceMap = std::unordered_map<std::size_t, BaseService*>;

	class ServiceProvider final
	{
	public:
		ServiceProvider() : services(ServiceMap())
		{
		}
		
		~ServiceProvider()
		{
			for (auto pair : services)
			{
				std::cout << "deleting: " << typeid(pair.second).name() << " " << sizeof(*(pair.second)) << " size." << std::endl;
				delete pair.second;
			}
		}
		
		template <typename T>
		T& Get()
		{
			std::size_t key = typeid(T).hash_code();
			ServiceMap::iterator it = services.find(key);
			
			std::cout << "Key: " << key << std::endl;
			
			if (it != services.end())
			{
				std::cout << "Gevonden" << std::endl;
				return *(T*)(it->second);
			}
			
			std::cout << "Aanmaken" << std::endl;
			T* service = new T();
			services.insert(std::pair<std::size_t, BaseService*>(key, service));
			
			return *service;
		}
		
	private:
		ServiceMap services;
	};
}
