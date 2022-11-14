#pragma once
#include "Vec3.h"
#include "Vec4.h"
#define YOSEF_MAT4_DATA(m,r,c) (m)[(c)*4+(r)]
namespace yf
{
	class Mat3f;
	class Mat4f
	{
	public:
		float mData[16];
	public:
		Mat4f();
		Mat4f(const Mat4f& r);
		Mat4f(const Mat3f& other);
		Vec3f operator*(Vec3f& vec);
		Vec3f operator*(const Vec4f& v)const;
		float& Get(int row, int column) { return mData[row + (column * 4)]; }
		const float& Get(int row, int column)const { return mData[row + (column * 4)]; }
		Mat4f& operator = (const Mat3f& m);
		void operator *= (const Mat4f& inM);
		Mat4f& operator=(const Mat4f& inM);
		double GetDeterminant() const;

		Vec3f MultiplyVector3(const Vec3f& inV) const;
		Vec3f MultiplyPoint3(const Vec3f& inV) const;
		void MultiplyPoint3(const Vec3f& inV, Vec3f& output) const;
		bool PerspectiveMultiplyPoint3(const Vec3f& inV, Vec3f& output) const;
		Vec3f InverseMultiplyPoint3Affine(const Vec3f& inV) const;
		Vec3f InverseMultiplyVector3Affine(const Vec3f& inV) const;

		void LookAt(Vec3f& eye, Vec3f& lookAt, Vec3f& up);
		void SetPerspective(float fovy, float aspect, float zNear, float zFar);
		void SetOrtho(float left, float right, float bottom, float top, float zNear, float zFar);

		void LoadIdentity();
		Mat4f& LocalTranslate(const Vec3f& trans);
		Mat4f& LocalTranslate(float x, float y, float z);

		void Transpose();
		void SetRotationPart(float* data);
		void SetTranslatePart(float x, float y, float z);
		Mat4f& Scale(float x, float y, float z);
		Mat4f& SetScale(float x, float y, float z);
		Mat4f& Rotate(Vec3f& from, Vec3f& to);
		void Rotate(Vec4f v);
	};
	void Mat4fMultiplyMat4f(const float* left, const float* right, float* result);
	bool InvertMat4f(const float* m, float* out);
} // namespace yf

