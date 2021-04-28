#include "Math.h"

float Utils::Math::GetVectorMagnitude(sf::Vector2f vector)
{
	return std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));
}

sf::Vector2f Utils::Math::NormalizeVector(sf::Vector2f vector)
{
	return vector / GetVectorMagnitude(vector);
}

sf::Vector2f Utils::Math::FlattenVectorX(sf::Vector2f vector)
{
	return sf::Vector2f(0, vector.y);
}

sf::Vector2f Utils::Math::FlattenVectorY(sf::Vector2f vector)
{
	return sf::Vector2f(vector.x, 0);
}
