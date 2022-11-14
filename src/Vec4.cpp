#include "Vec4.h"
#include "Vec2.h"
#include "Vec3.h"
namespace yf
{
	Vec4f::Vec4f(float x, float y, float z, float w /* = 1.0f */) :x(x), y(y), z(z), w(w) { }
	Vec4f::Vec4f(const Vec4f& v) : x(v.x), y(v.y), z(v.z), w(v.w) { }
	Vec4f::Vec4f(const Vec3f& v, float w /* = 1.0f */) : x(v.x), y(v.y), z(v.z), w(w) { }
	Vec4f::Vec4f(const float* buffer) : x(buffer[0]), y(buffer[1]), z(buffer[2]), w(buffer[3]) { }
	Vec4f::Vec4f() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) { }

	Vec4f& Vec4f::operator=(const Vec4f& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
	Vec4f& Vec4f::operator=(const Vec2f& v) { x = v.x; y = v.y; z = 0.0f; w = 1.0f; return *this; }
	bool Vec4f::operator == (const Vec4f& v) const { return x == v.x && y == v.y && z == v.z && w == v.w; }
	bool Vec4f::operator != (const Vec4f& v) const { return x != v.x || y != v.y || z != v.z || w != v.w; }
	bool Vec4f::operator == (const float v[4]) const { return x == v[0] && y == v[1] && z == v[2] && w == v[3]; }
	bool Vec4f::operator != (const float v[4]) const { return x != v[0] || y != v[1] || z != v[2] || w != v[3]; }
	Vec4f Vec4f::operator*(float v) { x *= v; y *= v; z *= v; w *= v; return *this; }
	Vec4f Vec4f::operator+(const Vec4f& color) { return Vec4f(x + color.x, y + color.y, z + color.z, w + color.w); }
	Vec4f Vec4f::operator-(const Vec4f& v) { return Vec4f(x - v.x, y - v.y, z - v.z, 1.0f); }
	Vec4f Vec4f::operator-() const { return Vec4f(-x, -y, -z, -w); }
	void Vec4f::Set(float inX, float inY, float inZ, float inW /* = 1.0f */) { x = inX; y = inY; z = inZ; w = inW; }
	float& Vec4f::operator[](int index) { return v[index]; }
	float Vec4f::SqrtMagnitude() { return x * x + y * y + z * z; }
	float Vec4f::Magnitude() { return sqrtf(x * x + y * y + z * z); }
	float Vec4f::Length() { return sqrtf(x * x + y * y + z * z); }

	std::ostream& operator<<(std::ostream& os, const Vec4f& v)
	{
		os << v.x << " " << v.y << " " << v.z << " " << v.w;
		return os;
	}

} // namespace yf