#pragma once
#include "Vec3.h"
namespace yf
{
	class Mat4f;
	class Mat3f
	{
	public:
		float mData[9];
		Mat3f();
		Mat3f(const Mat3f& r);
		Mat3f(float value);
		Mat3f(const Mat4f& m);
		float& Get(int row, int column) { return mData[row + (column * 3)]; }
		const float& Get(int row, int column)const { return mData[row + (column * 3)]; }
		void operator= (const Mat4f& m);
		void operator=(const Mat3f& r);

		Mat3f& operator *= (const Mat3f& inM);
		Mat3f& operator *= (const Mat4f& inM);
		friend Mat3f operator * (const Mat3f& lhs, const Mat3f& rhs) { Mat3f temp(lhs); temp *= rhs; return temp; }
		Vec3f MultiplyVector3(const Vec3f& inV) const;
		void MultiplyVector3(const Vec3f& inV, Vec3f& output) const;

		Vec3f MultiplyPoint3(const Vec3f& inV) const { return MultiplyVector3(inV); }

		Mat3f& operator *= (float f);
		Mat3f& operator /= (float f) { return *this *= (1.0F / f); }
		float GetDeterminant() const;
		Mat3f& Transpose();
		bool Invert();
		void InvertTranspose();
		void LoadIdentity();
		bool IsIdentity(float threshold = 0.00001f);
	};
	void RotationMatrix(const Vec3f& from, const Vec3f& to, float* rotation_matrix_3x3);
	bool MatrixToEuler(const Mat3f& matrix, Vec3f& v);
	void EulerToMatrix(const Vec3f& v, Mat3f& matrix);
	inline Vec3f Mat3f::MultiplyVector3(const Vec3f& v) const 
	{
		Vec3f res;
		res.x = mData[0] * v.x + mData[3] * v.y + mData[6] * v.z;
		res.y = mData[1] * v.x + mData[4] * v.y + mData[7] * v.z;
		res.z = mData[2] * v.x + mData[5] * v.y + mData[8] * v.z;
		return res;
	}
	inline void Mat3f::MultiplyVector3(const Vec3f& v, Vec3f& output) const 
	{
		output.x = mData[0] * v.x + mData[3] * v.y + mData[6] * v.z;
		output.y = mData[1] * v.x + mData[4] * v.y + mData[7] * v.z;
		output.z = mData[2] * v.x + mData[5] * v.y + mData[8] * v.z;
	}
	void FromToRotation(const float* from, const float* to, float mtx[3][3]);
} // namespace yf


