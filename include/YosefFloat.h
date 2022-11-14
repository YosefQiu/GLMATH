#pragma once
#include "YosefPrefix.h"

#define YOSEF_PI            3.14159265358979323846264338327950288419716939937510f
#define YOSEF_PI_DIV_180    0.017453292519943f
#define YOSEF_180_DIV_PI    57.295779513082f
#define YOSEF_EPSILON       0.000001f
#define YOSEF_DEG2RAD(x)    ((x) * YOSEF_PI_DIV_180)
#define YOSEF_RAD2DEG(x)    ((x) * YOSEF_180_DIV_PI)
#define YOSEF_SQUARE(x)     (x*x)
#define YOSEF_ABS(x)        ((x)>0.0f?(x):-(x))
#define YOSEF_SQRTF(x)      sqrtf(x)
#define YOSEF_INVERSQRTF(x) (1.0f/YOSEF_SQRTF((x)))
#define YOSEF_COSF(x)       cosf(x)
#define YOSEF_SINF(x)       sinf(x)
#define YOSEF_SIGN(x)       (x>0.0f?1.0f:-1.0f)
#define YOSEF_MAX(x,y)      ((x)>(y)?(x):(y))
#define YOSEF_MIN(x,y)      ((x)<(y)?(x):(y))

bool IsFinite(const float& value);
bool IsFinite(const double& value);
const float sBiggestFloatSmallerThanOne = 0.99999994f;

namespace yf{
    int FloorfToInt(float f);
    bool EqualApproximately(float f0, float f1, float epsilon = 0.000001f);
	float LinearInterpolate(float from, float to, float t);
	float CopySignf(float x, float y);
    template<typename T>
    T Max(const T& l, const T& r) { return l > r ? l : r; }
    template<typename T>
    T Min(const T& l, const T& r) { return l < r ? l : r; }
    template<typename T>
    T Max(const T& a, const T& b, const T& c) { return ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c))); }
    template<typename T>
    T Min(const T& a, const T& b, const T& c) { return ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c))); }
    template<typename T>
    T Max() {return std::numeric_limits<T>::max(); }
    template<typename T>
    T Min() {return std::numeric_limits<T>::min(); }
    template<typename T>
    T Inf() {return std::numeric_limits<T>::infinity(); }
    template<typename T>
    T Yosef_ABS(const T& a) { return a >= 0.0f ? a : -a; }
    
    inline bool IsNaN(float v) { return v != v; }
    inline bool IsNaN(double v) { return v != v; }
}