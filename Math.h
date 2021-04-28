#pragma once

#include <iostream>
#include <SFML\System\Vector2.hpp>

namespace Utils
{
	class Math
	{
	public:
		static float GetVectorMagnitude(sf::Vector2f vector);
		static sf::Vector2f NormalizeVector(sf::Vector2f vector);
		static sf::Vector2f FlattenVectorX(sf::Vector2f vector);
		static sf::Vector2f FlattenVectorY(sf::Vector2f vector);
	};
}