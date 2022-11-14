#include "Vec2.h"

namespace yf
{
	Vec2f::Vec2f(float x, float y) : x(x), y(y) { }
	Vec2f::Vec2f(const Vec2f& v) : x(v.x), y(v.y) { }
	Vec2f::Vec2f(float* v) : x(v[0]), y(v[1]) { }
	Vec2f::Vec2f() : x(0.0f), y(0.0f) { }
	void Vec2f::Set(const float& xValue, const float& yValue) { x = xValue; y = yValue;}
	void Vec2f::Set(const float* v) { x = v[0]; y = v[1]; }
	bool Vec2f::operator==(const Vec2f& v) { return x == v.x && y == v.y;}
	bool Vec2f::operator != (const Vec2f& v) { return x != v.x || y != v.y; }
	void Vec2f::operator=(const Vec2f& v) { x = v.x; y = v.y; }
	Vec2f Vec2f::operator+(const Vec2f& v) { return Vec2f(x + v.x, y + v.y); }
	void Vec2f::operator+=(const Vec2f& v) { x += v.x; y += v.y; }
	Vec2f Vec2f::operator-(const Vec2f& v) { return Vec2f(x - v.x, y - v.y); }
	void Vec2f::operator-=(const Vec2f& v) { x -= v.x; y -= v.y; }
	Vec2f Vec2f::operator*(float scalar) { return Vec2f(x * scalar, y * scalar); }
	void Vec2f::operator*=(float scalar) { x *= scalar; y *= scalar; }
	//Vec2f Vec2f::operator*(const Vec2f& v) { return Vec2f(x * v.x, y * v.y); }
	float& Vec2f::operator[](int index) { return v[index]; }
	Vec2f Vec2f::operator/(float f)
	{
		if (f != 0)
		{
			float reciprocal = 1.0f / f;
			return Vec2f(x * reciprocal, y * reciprocal);
		}
		return Vec2f(x, y);
	}
	void Vec2f::operator/=(float f)
	{
		if (f != 0) 
		{
			float reciprocal = 1.0f / f;
			x *= reciprocal;
			y *= reciprocal;
		}
	}
	float Vec2f::Dot(const Vec2f& v) { return x * v.x + y * v.y; }
	float Vec2f::Cross(const Vec2f& v) { return x* v.y - v.x * y; }
	void Vec2f::Normalize() { float length = Length(); x /= length; y /= length; }
	float Vec2f::LengthSquared() { return YOSEF_SQUARE(x) + YOSEF_SQUARE(y); }
	float Vec2f::Length() { return YOSEF_SQRTF(LengthSquared()); }
	bool Vec2f::IsPerpendicularTo(Vec2f& v) { return ((*this).Dot(v) == 0); }
	Vec2f Vec2f::ProjectTo(Vec2f& v)
	{
		float lenSquared = v.LengthSquared();
		return (*this).Dot(v) * v / lenSquared;
	}
	Vec2f Vec2f::PerpendicularTo(Vec2f& v)
	{
		Vec2f projP2Q = ProjectTo(v);
		return (*this) - projP2Q;
	}
	float Vec2f::Sin(Vec2f& v) { float cos = Cos(v); return YOSEF_SQRTF(1 - YOSEF_SQUARE(cos)); }
	float Vec2f::Cos(Vec2f& v) { return ((*this).Dot(v)) / (Length() * v.Length()); }

	Vec2f operator*(float scalar, Vec2f& v) { return  Vec2f(v.x * scalar, v.y * scalar); }
	Vec2f operator-(const Vec2f& r) { return Vec2f(-r.x, -r.y); }
	Vec2f Normalize(Vec2f& v) { return v / v.Length(); }
	float Dot(const Vec2f& v1, const Vec2f& v2) { return v1.x * v2.x + v1.y * v2.y; }
	float Cross(const Vec2f& v1, const Vec2f& v2) { return v1.x * v2.y - v2.x * v1.y; }
	float Length(Vec2f& v) { return v.Length(); }
	std::ostream& operator<<(std::ostream& os, const Vec2f& v)
	{
		os << v.x << " " << v.y;
		return os;
	}
}

