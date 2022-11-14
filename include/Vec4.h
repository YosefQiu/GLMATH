#pragma once
#include "YosefFloat.h"

namespace yf
{
	class Vec2f;
	class Vec3f;
	class Vec4f
	{
	public:
		Vec4f(float x, float y, float z, float w = 1.0f);
		Vec4f(const Vec4f& v);
		Vec4f(const Vec3f& v, float w = 1.0f);
		Vec4f(const float* buffer);
		Vec4f();
	public:
		Vec4f& operator=(const Vec4f& v);
		Vec4f& operator=(const Vec2f& v);
		bool operator == (const Vec4f& v) const;
		bool operator != (const Vec4f& v) const;
		bool operator == (const float v[4]) const;
		bool operator != (const float v[4]) const;
		Vec4f operator*(float v);
		Vec4f operator+(const Vec4f& color);
		Vec4f operator-(const Vec4f& v);
		Vec4f operator - () const;
		void Set(float inX, float inY, float inZ, float inW = 1.0f);
		float& operator[](int index);
		float SqrtMagnitude();
		float Magnitude();
		float Length();
		friend std::ostream& operator<<(std::ostream& os, const Vec4f& v);
	public:
		union
		{
			struct
			{
				float x, y, z, w;
			};
			float v[4];
		};
	};

	typedef Vec4f Vec4;
	typedef Vec4f vec4f;
	typedef Vec4f vec4;

} // namespace yf

