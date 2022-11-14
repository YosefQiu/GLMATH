#pragma once
#include "YosefFloat.h"
#include "Vec3.h"
#include "Mat3.h"
namespace yf
{
	class Quatf
	{
	public:
		Quatf() {}
		Quatf(float inX, float inY, float inZ, float inW);
		~Quatf() {}
	public:
		void Set(float inX, float inY, float inZ, float inW);
		inline friend Quatf operator*(const Quatf& lhs, const Quatf& rhs) 
		{
			return Quatf(
				lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
				lhs.w * rhs.y + lhs.y * rhs.w + lhs.z * rhs.x - lhs.x * rhs.z,
				lhs.w * rhs.z + lhs.z * rhs.w + lhs.x * rhs.y - lhs.y * rhs.x,
				lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z);
		}
	public:
		float x, y, z, w;
	};
	Quatf EulerToQuaternion(const Vec3f& euler);
	void QuaternionToMatrix(const Quatf& q, Mat3f& m);

	typedef Quatf Quat;
	typedef Quatf quat;

} // namespace yf
