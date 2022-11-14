#pragma once
#include "YosefFloat.h"

#define YOSEF_VE3_CROSS(dest, v1, v2) do { \
		dest[0] = v1[1] * v2[2] - v1[2] * v2[1]; \
		dest[1] = v1[2] * v2[0] - v1[0] * v2[2]; \
		dest[2] = v1[0] * v2[1] - v1[1] * v2[0];} while (0)
#define YOSEF_VE3_DOT(v1,v2) (v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2])
#define YOSEF_VE3_SUB(dest,v1,v2) do{       \
          dest[0]=v1[0]-v2[0]; \
          dest[1]=v1[1]-v2[1]; \
          dest[2]=v1[2]-v2[2];}while(0)

namespace yf
{
	class Vec4f;
	class Vec3f
	{
	public:
		Vec3f(float x, float y, float z); 
		Vec3f(const Vec3f& v);
		Vec3f(const float* v);
		Vec3f();
	public:
		Vec3f& operator=(const Vec3f& v);
		void operator=(const Vec4f& v);
		Vec3f operator*(const float scalar);
		//Vec3f operator*(const Vec3f& v);
		float& operator[](int index);
		bool operator==(const Vec3f& v);
		bool operator!=(const Vec3f& v);
		Vec3f& operator+=(const Vec3f& inV);
		Vec3f& operator-=(const Vec3f& inV);
		Vec3f& operator*=(float s);
		Vec3f& operator/=(float s);
		Vec3f operator+(const Vec3f& inV);
		Vec3f operator-(const Vec3f& inV);
		Vec3f operator/(float s);
	public:
		void Set(float inX, float inY, float inZ);
		void Set(const float* array);
		float Length();
		float LengthSquared();
		float Sin(Vec3f& v);
		float Cos(Vec3f& v);
		float Dot(const Vec3f& v);
		bool IsPerpendicularTo(Vec3f& v);
		Vec3f Normalize();
		Vec3f ProjectTo(Vec3f& v);
		Vec3f PerpendicularTo(Vec3f& v);
		Vec3f Cross(const Vec3f& v);
		static const float	epsilon;
		friend std::ostream& operator<<(std::ostream& os, const Vec3f& v);
	public:
		union
		{
			struct
			{
				float x, y, z;
			};
			float v[3];
		};
	};
	Vec3f operator+(const Vec3f& lhs, const Vec3f& rhs);
	Vec3f operator-(const Vec3f& lhs, const Vec3f& rhs);
	Vec3f operator*(const float s, const Vec3f& inV);
	Vec3f operator*(const Vec3f& inV, float s);
	Vec3f minVector3(const Vec3f& lhs, const Vec3f& rhs);
	Vec3f maxVector3(const Vec3f& lhs, const Vec3f& rhs);
	Vec3f Lerp(Vec3f& from, Vec3f& to, float t);
	Vec3f Abs(const Vec3f& v);
	Vec3f Cross(const Vec3f& lhs, const Vec3f& rhs);
	float Dot(const Vec3f& lhs, const Vec3f& rhs);
	float SqrMagnitude(const Vec3f& inV);
	float Magnitude(const Vec3f& inV);
	float Length(const Vec3f& inV);
	Vec3f Normalize(Vec3f& inV);
	bool IsFinite(const Vec3f& f);


	typedef Vec3f Vec3;
	typedef Vec3f vec3f;
	typedef Vec3f vec3;
} // namespace yf

