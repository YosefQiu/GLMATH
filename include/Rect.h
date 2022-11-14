#pragma once
#include "Vec2.h"

namespace yf
{
	template <typename T>
	class Rect
	{
	public:
		Rect(T x, T y, T width, T height) :mLeft(x), mBottom(y), mWidth(width), mHeight(height) {}
		Rect() :mLeft(0), mBottom(0), mWidth(0), mHeight(0) {}
		~Rect() {}
	public:
		inline T GetRight() { return mLeft + mWidth; }
		inline T GetBottom() { return mBottom + mHeight; }
		inline bool Contains(T x, T y) 
		{
			if (x > mLeft && x < (mLeft + mWidth) && y > mBottom && y < (mBottom + mHeight))
			{
				return true;
			}
			return false;
		}
	public:
		void Set(T x, T y, T width, T height)
		{
			mLeft = x;
			mBottom = y;
			mWidth = width;
			mHeight = height;
		}
		bool IsOverlappedWith(const Rect& other)
		{
			if (mLeft > (other.mLeft + other.mWidth) || other.mLeft > (mLeft + mWidth))
				return false;
			if ((mBottom + mHeight) < other.mBottom || (other.mBottom + other.mHeight) < mBottom)
				return false;
			return true;
		}
	public:
		T mLeft;
		T mBottom;
		T mWidth;
		T mHeight;
	};
} // namespace yf