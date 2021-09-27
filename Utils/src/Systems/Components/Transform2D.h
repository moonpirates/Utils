#pragma once

#include <iostream>
#include "Macros/Macros.h"
#include "Transform.h"
#include "Math/Vector2.h"

namespace Utils
{
	class Transform2D : public Transform
	{
		Vector2 Position;
		Vector4 Rotation;
		Vector2 Scale;
	};
}