#pragma once

#include <algorithm>

namespace Utils
{
	class Math
	{
	public:
		static float Lerp(float a, float b, float t);
		static float InverseLerp(float a, float b, float value);
	};
}

