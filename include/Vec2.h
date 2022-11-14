#pragma once
#include "YosefFloat.h"


namespace yf
{
	class Vec2f
	{
	public:
		Vec2f(float x, float y);
		Vec2f(const Vec2f& v);
		Vec2f(float* v);
		Vec2f();
	public:
		void Set(const float& xValue, const float& yValue);
		void Set(const float* v);
	public:
		bool operator == (const Vec2f& v);
		bool operator != (const Vec2f& v);
		void operator=(const Vec2f& v);
		Vec2f operator+(const Vec2f& v);
		void operator+=(const Vec2f& v);
		Vec2f operator-(const Vec2f& v);
		void operator-=(const Vec2f& v);
		Vec2f operator*(float scalar);
		void operator*=(float scalar);
		//Vec2f operator*(const Vec2f& v);
		Vec2f operator/(float f);
		void operator/=(float f);
		float& operator[](int index);
		float Dot(const Vec2f& v);
		float Cross(const Vec2f& v);
		void Normalize();
	public:
		float LengthSquared();
		float Length();
		bool IsPerpendicularTo(Vec2f& v);
		Vec2f ProjectTo(Vec2f& v);
		Vec2f PerpendicularTo(Vec2f& v);
		float Sin(Vec2f& v);
		float Cos(Vec2f& v);
		friend std::ostream& operator<<(std::ostream& os, const Vec2f& v);
	public:
		union 
		{
			struct
			{
				float x, y;
			};
			float v[2];
		};
	};
	Vec2f operator*(float scalar, Vec2f& v);
	Vec2f operator-(const Vec2f& r);
	Vec2f Normalize(Vec2f& v);
	float Dot(const Vec2f& v1, const Vec2f& v2);
	float Cross(const Vec2f& v1, const Vec2f& v2);
	float Length(Vec2f& v);
	
	typedef Vec2f Vec2;
	typedef Vec2f vec2f;
	typedef Vec2f vec2;
} // namespace yf


