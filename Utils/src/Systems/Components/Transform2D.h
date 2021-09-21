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
		Quaternion Rotation;
		Vector2 Scale;
	};
}