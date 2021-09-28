#pragma once

namespace Utils
{
	struct Vector3;
	struct Vector4;

	struct Vector2
	{
		float X;
		float Y;

		operator Vector3() const;
		operator Vector4() const;
	};

	struct Vector3
	{
		float X;
		float Y;
		float Z;

		operator Vector2() const;
		operator Vector4() const;
	};

	struct Vector4
	{
		float X;
		float Y;
		float Z;
		float W;

		operator Vector2() const;
		operator Vector3() const;
	};

	inline Vector2::operator Vector3() const { return { X, Y, 0.0f }; }
	inline Vector2::operator Vector4() const { return { X, Y, 0.0f, 0.0f }; }

	inline Vector3::operator Vector2() const { return { X, Y }; }
	inline Vector3::operator Vector4() const { return { X, Y, Z, 0.0f }; }

	inline Vector4::operator Vector2() const { return { X, Y }; }
	inline Vector4::operator Vector3() const { return { X, Y, Z }; }
}