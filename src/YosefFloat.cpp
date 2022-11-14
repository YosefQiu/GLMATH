#include "YosefFloat.h"

bool IsFinite(const float& value)
{
    // Returns false if value is NaN or +/- infinity
    YosefUInt32 intVal = *reinterpret_cast<const YosefUInt32*>(&value);
    return (intVal & 0x7f800000) != 0x7f800000;
}

bool IsFinite(const double& value)
{
    // Returns false if value is NaN or +/- infinity
    YosefUInt64 intVal = *reinterpret_cast<const YosefUInt64*>(&value);
	return (intVal & 0x7ff0000000000000LL) != 0x7ff0000000000000LL;
}

namespace yf
{
    int FloorfToInt(float f) { return f >= 0 ? (int)f : (int)(f - sBiggestFloatSmallerThanOne); }
    bool EqualApproximately(float f0, float f1, float epsilon /* = 0.000001f */)
    {
		float dist = (f0 - f1);
		dist = YOSEF_ABS(dist);
		return dist <= epsilon;
	}
    float LinearInterpolate(float from, float to, float t) { return to * t + from * (1.0f - t); }
    float CopySignf(float x, float y)
    {
        // Returns magnitude of x with the sign of y
        union 
        {
            float f;
            YosefUInt32 i;
        }u, u0, u1;
        u0.f = x;
        u1.f = y;
        YosefUInt32 a = u0.i;
		YosefUInt32 b = u1.i;
		YosefSInt32 mask = 1 << 31;
		YosefUInt32 sign = b & mask;
        a &= ~mask;
		a |= sign;
		u.i = a;
        return u.f;
    }
} // namespace yf
