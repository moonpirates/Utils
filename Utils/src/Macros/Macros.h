#pragma once

#include <typeindex>
#include <regex>
#include "Logging/Logger.h"

template <typename T>
size_t GetTypeHash()
{
	return typeid(T).hash_code();
}

template <typename T>
size_t GetTypeIndex()
{
	return std::type_index(typeid(T));
}

const std::string TypeToClassName(const std::type_info& typeInfo);