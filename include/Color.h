#pragma once
#include "YosefPrefix.h"

namespace yf
{
    struct Color4B
    {
        YosefUInt8 r;
        YosefUInt8 g;
        YosefUInt8 b;
        YosefUInt8 a;
    public:
        Color4B();
        Color4B(YosefUInt8 _r, YosefUInt8 _g, YosefUInt8 _b, YosefUInt8 _a = 255);
        Color4B(const char* hexStr);
        bool operator==(const Color4B& right) const; 
		bool operator!=(const Color4B& right) const;
		void operator=(const Color4B&color);
		Color4B operator+(const Color4B&color);
		Color4B operator*(float v); 
        friend std::ostream& operator<<(std::ostream& os, const Color4B& color);
        void Set(YosefUInt8 _r, YosefUInt8 _g, YosefUInt8 _b, YosefUInt8 _a = 255);
        static const Color4B WHITEB;
		static const Color4B YELLOWB;
		static const Color4B BLUEB;
		static const Color4B GREENB;
		static const Color4B REDB;
		static const Color4B MAGENTAB;
		static const Color4B BLACKB;
		static const Color4B ORANGEB;
		static const Color4B GRAYB;
    };
    inline Color4B Lerp(Color4B from, Color4B to, float t);
    struct Color4f
    {
        float r;
        float g;
        float b;
        float a;
    public:
        Color4f();
        Color4f(float _r, float _g, float _b, float _a = 1.0f);
        Color4f(const char* hexStr);
        bool operator==(const Color4f& right) const;
        bool operator!=(const Color4f& right) const;
        void operator=(const Color4f& color);
        Color4f operator+(const Color4f& color);
        Color4f operator*(float v);
        friend std::ostream& operator<<(std::ostream& os, const Color4f& color);
        void Set(float _r, float _g, float _b, float _a = 1.0f);
        static const Color4f WHITE;
        static const Color4f YELLOW;
        static const Color4f BLUE;
        static const Color4f GREEN;
        static const Color4f RED;
        static const Color4f MAGENTA;
        static const Color4f BLACK;
        static const Color4f ORANGE;
        static const Color4f GRAY;
    private:
        void checkError();
    };
    inline Color4f Lerp(Color4f from, Color4f to, float t);

    class ColorHSB
    {
    public:
        ColorHSB();
        ColorHSB(YosefUInt8 r, YosefUInt8 g, YosefUInt8 b);
        ColorHSB(Color4B& color);
        ColorHSB(Color4f& color);
    public:
        void ToRGB(Color4B& color);
        void ToRGB(Color4f& color);
    public:
        YosefUInt16 h, s, b;
    };

} // namespace yf
