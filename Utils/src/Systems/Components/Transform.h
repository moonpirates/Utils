#pragma once

#include <iostream>
#include "Macros/Macros.h"
#include "Systems/Components/Component.h"
#include "Math/Vector3.h"
#include "Math/Quaternion.h"

namespace Utils
{
	class Transform : public Component
	{
	public:
		Vector3 Position;
		Quaternion Rotation;
		Vector3 Scale;
	};
}