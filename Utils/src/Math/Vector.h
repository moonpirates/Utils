#pragma once

namespace Utils
{
	struct Vector3;
	struct Vector4;

	struct Vector2
	{
		float X;
		float Y;

		const static Vector2 Zero;
		const static Vector2 One;
		const static Vector2 Left;
		const static Vector2 Right;
		const static Vector2 Up;
		const static Vector2 Down;

		operator Vector3() const;
		operator Vector4() const;
	};

	struct Vector3
	{
		float X;
		float Y;
		float Z;

		const static Vector3 Zero;
		const static Vector3 One;
		const static Vector3 Left;
		const static Vector3 Right;
		const static Vector3 Up;
		const static Vector3 Down;
		const static Vector3 Forward;
		const static Vector3 Back;

		operator Vector2() const;
		operator Vector4() const;
	};

	struct Vector4
	{
		float X;
		float Y;
		float Z;
		float W;

		const static Vector4 Zero;
		const static Vector4 One;

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