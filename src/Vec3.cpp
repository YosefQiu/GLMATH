#include "Vec3.h"
#include "Vec4.h"
namespace yf
{
	const float Vec3f::epsilon = 0.00001f;
	Vec3f::Vec3f(float x, float y, float z) :x(x), y(y), z(z) { }
	Vec3f::Vec3f(const Vec3f& v) :x(v.x), y(v.y), z(v.z) { }
	Vec3f::Vec3f(const float* v) :x(v[0]), y(v[1]), z(v[2]) { }
	Vec3f::Vec3f() :x(0.0f), y(0.0f), z(0.0f) { }

	Vec3f& Vec3f::operator=(const Vec3f& v) { x = v.x; y = v.y; z = v.z; return *this; }
	void Vec3f::operator=(const Vec4f& v) { x = v.x; y = v.y; z = v.z; }
	Vec3f Vec3f::operator*(const float scalar) { return Vec3f(x * scalar, y * scalar, z * scalar); }
	//Vec3f Vec3f::operator*(const Vec3f& v) { return Vec3f(x * v.x, y * v.y, z * v.z); }
	float& Vec3f::operator[](int index) { return v[index]; }
	bool Vec3f::operator==(const Vec3f& v) { return x == v.x && y == v.y && z == v.z; }
	bool Vec3f::operator!=(const Vec3f& v) { return x != v.x || y != v.y || z != v.z; }
	Vec3f& Vec3f::operator+=(const Vec3f& inV) { x += inV.x; y += inV.y; z += inV.z; return *this; }
	Vec3f& Vec3f::operator-=(const Vec3f& inV) { x -= inV.x; y -= inV.y; z -= inV.z; return *this; }
	Vec3f& Vec3f::operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
	Vec3f& Vec3f::operator/=(float s) { x /= s; y /= s; z /= s; return *this; }
	Vec3f Vec3f::operator+(const Vec3f& inV) { x += inV.x; y += inV.y; z += inV.z; return *this; }
	Vec3f Vec3f::operator-(const Vec3f& inV) { x -= inV.x; y -= inV.y; z -= inV.z; return *this; }
	Vec3f Vec3f::operator/(float s) { x /= s; y /= s; z /= s; return *this; }

	void Vec3f::Set(float inX, float inY, float inZ) { x = inX; y = inY; z = inZ; }
	void Vec3f::Set(const float* array) { x = array[0]; y = array[1]; z = array[2]; }
	float Vec3f::Length() 
	{
		float len = (float)sqrt(x * x + y * y + z * z);
		return len;
	}
	float Vec3f::LengthSquared()
	{
		float len = x * x + y * y + z * z;
		return len != 0.0f ? len : 1.0f;
	}
	float Vec3f::Sin(Vec3f& v)
	{
		Vec3f temp = (*this).Cross(v);
		return temp.Length() / (Length() * v.Length());
	}
	float Vec3f::Cos(Vec3f& v)
	{
		return ((*this).Dot(v)) / (Length() * v.Length());
	}
	float Vec3f::Dot(const Vec3f& v) { return x * v.x + y * v.y + z * v.z; }
	bool Vec3f::IsPerpendicularTo(Vec3f& v) { return ((*this).Dot(v) == 0); }
	Vec3f Vec3f::Normalize()
	{
		float len = Length();
		if (EqualApproximately(len, 0.0f))
		{
			x = 0.0f;
			y = 1.0f;
			z = 0.0f;
		}
		else
		{
			*this = *this * (1.0f / len);
		}
		return *this;
	}
	Vec3f Vec3f::ProjectTo(Vec3f& v)
	{
		float lenSquared = v.LengthSquared();
		return (*this).Dot(v) * v  / lenSquared;
	}
	Vec3f Vec3f::PerpendicularTo(Vec3f& v)
	{
		Vec3f projP2Q = ProjectTo(v);
		return (*this) - projP2Q;
	}
	Vec3f Vec3f::Cross(const Vec3f& v) { return Vec3f(y * v.z - v.y * z, v.x * z - x * v.z, x * v.y - v.x * y); }

	Vec3f operator+(const Vec3f& lhs, const Vec3f& rhs) { return Vec3f(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }
	Vec3f operator-(const Vec3f& lhs, const Vec3f& rhs) { return Vec3f(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }
	Vec3f operator*(const float s, const Vec3f& inV) { return Vec3f(inV.x * s, inV.y * s, inV.z * s); }
	Vec3f operator*(const Vec3f& inV, float s) { return Vec3f(inV.x * s, inV.y * s, inV.z * s); }
	Vec3f minVector3(const Vec3f& lhs, const Vec3f& rhs) { return Vec3f(YOSEF_MIN(lhs.x, rhs.x), YOSEF_MIN(lhs.y, rhs.y), YOSEF_MIN(lhs.z, rhs.z)); }
	Vec3f maxVector3(const Vec3f& lhs, const Vec3f& rhs) { return Vec3f(YOSEF_MAX(lhs.x, rhs.x), YOSEF_MAX(lhs.y, rhs.y), YOSEF_MAX(lhs.z, rhs.z)); }
	Vec3f Lerp(Vec3f& from, Vec3f& to, float t) { return from * t + to * (1.0F - t); }
	Vec3f Abs(const Vec3f& v) { return Vec3f(YOSEF_ABS(v.x), YOSEF_ABS(v.y), YOSEF_ABS(v.z)); }
	Vec3f Cross(const Vec3f& lhs, const Vec3f& rhs)
	{
		return Vec3f(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x);
	}
	float Dot(const Vec3f& lhs, const Vec3f& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z; }
	float SqrMagnitude(const Vec3f& inV) { return Dot(inV, inV); }
	float Magnitude(const Vec3f& inV) { return YOSEF_SQRTF(Dot(inV, inV)); }
	float Length(const Vec3f& inV) { return YOSEF_SQRTF(Dot(inV, inV)); }
	Vec3f Normalize(Vec3f& inV) { return inV / Magnitude(inV); }
	bool IsFinite(const Vec3f& f) { return ::IsFinite(f.x) & ::IsFinite(f.y) & ::IsFinite(f.z); }

	std::ostream& operator<<(std::ostream& os, const Vec3f& v)
	{
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}
} // namespace yf