#pragma once
#include "Math/Vector.h"

namespace Utils
{
	struct Color
	{
		static const Color White;
		static const Color LightGrey;
		static const Color Grey;
		static const Color DarkGrey;
		static const Color Black;
		static const Color Red;
		static const Color Orange;
		static const Color Yellow;
		static const Color Green;
		static const Color Cyan;
		static const Color Blue;
		static const Color Purple;

		float R;
		float G;
		float B;
		float A;

		operator Vector4() const { return { R, G, B, A }; }

	};

	//inline const Color Color::White = { 1.0f, 1.0f, 1.0f, 1.0f };
}