#include "Macros.h"

const std::string TypeToClassName(const std::type_info& typeInfo)
{
	const std::regex CLASS_NAME_REGEX("([A-Za-z])\\w+$");
	std::cmatch match;

	if (std::regex_search(typeInfo.name(), match, CLASS_NAME_REGEX))
	{
		return match.str();
	}
	else
	{
		return "";
	}
}
