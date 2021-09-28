#pragma once

#include <iostream>
#include "Macros/Macros.h"
#include "Systems/Components/Component.h"
#include "Math/Vector.h"

namespace Utils
{
	//TODO to union?
	class Transform : public Component
	{
	public:
		Vector3 Position;
		Vector4 Rotation;
		Vector3 Scale;
		Vector2 Size;
	};
}