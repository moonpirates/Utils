#pragma once

#include <iostream>
#include "Macros/Macros.h"
#include "Systems/Components/Component.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

namespace Utils
{
	class Transform : public Component
	{
	public:
		Vector3 Position;
		Vector4 Rotation;
		Vector3 Scale;
	};
}