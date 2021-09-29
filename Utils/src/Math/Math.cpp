#include "Math.h"

float Utils::Math::Lerp(float a, float b, float t)
{
	return ((b - a) * std::clamp(t, 0.0f, 1.0f) + a);
}

float Utils::Math::InverseLerp(float a, float b, float value)
{
	return std::clamp((value - a) / (b - a), 0.0f, 1.0f);
}
