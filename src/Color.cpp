#include "Color.h"
#include "YosefFloat.h"
namespace yf
{
    Color4B::Color4B() { r = 255; g = 255; b = 255; a = 255; }
    Color4B::Color4B(YosefUInt8 _r, YosefUInt8 _g, YosefUInt8 _b, YosefUInt8 _a/* = 255*/) { r = _r; g = _g; b = _b; a = _a; }
    Color4B::Color4B(const char* hexStr)
    {
        char digits[3];
        char* error;
        if (strlen(hexStr) != 8) 
        {
            r = 255; 
            g = 255; 
            b = 255; 
            a = 255;
        }
        digits[0] = *hexStr;
		digits[1] = *(hexStr + 1);
		digits[2] = '\0';
        r = (YosefUInt8)strtoul(digits, &error, 16);
        digits[0] = *(hexStr+2);
		digits[1] = *(hexStr + 3);
		digits[2] = '\0';
        g = (YosefUInt8)strtoul(digits, &error, 16);
		digits[0] = *(hexStr + 4);
		digits[1] = *(hexStr + 5);
		digits[2] = '\0';
		b = (YosefUInt8)strtoul(digits, &error, 16);
		digits[0] = *(hexStr + 6);
		digits[1] = *(hexStr + 7);
		digits[2] = '\0';
		a = (YosefUInt8)strtoul(digits, &error, 16);
    }
    bool Color4B::operator==(const Color4B& right) const { return (r == right.r && g == right.g && b == right.b && a == right.a); }
	bool Color4B::operator!=(const Color4B& right) const { return !(r == right.r && g == right.g && b == right.b && a == right.a);}
	void Color4B::operator=(const Color4B&color) { r = color.r; g = color.g; b = color.b; a = color.a; }
	Color4B Color4B::operator+(const Color4B&color) { return Color4B(r + color.r, g + color.g, b + color.b, a + color.a); }
	Color4B Color4B::operator*(float v) { r = YosefUInt8(r * v); g = YosefUInt8(g * v); b = YosefUInt8(b * v); a = YosefUInt8(a * v); return *this; }
    void Color4B::Set(YosefUInt8 _r, YosefUInt8 _g, YosefUInt8 _b, YosefUInt8 _a/* = 255*/) { r = _r; g = _g; b = _b; a = _a; }
	std::ostream& operator<<(std::ostream& os, const Color4B& color)
	{
		os << (int)color.r << " " << (int)color.g << " "
			<< (int)color.b << " " << (int)color.a << " ";
		return os;
	}
	Color4B Lerp(Color4B from, Color4B to, float t) { return Color4B(from * t + to * (1.0f - t));}
	const Color4B WHITEB     = Color4B(255, 255, 255, 255);
	const Color4B YELLOWB    = Color4B(255, 255, 0, 255);
	const Color4B BLUEB      = Color4B(0, 0, 255, 255);
	const Color4B GREENB     = Color4B(0, 255, 0, 255);
	const Color4B REDB       = Color4B(255, 0, 0, 255);
	const Color4B MAGENTAB   = Color4B(255, 0, 255, 255);
	const Color4B BLACKB     = Color4B(0, 0, 0, 255);
	const Color4B ORANGEB    = Color4B(255, 165, 0, 255);
	const Color4B GRAYB      = Color4B(41, 41, 41, 255);

	Color4f::Color4f() { r = 1.0f; g = 1.0f; b = 1.0f; a = 1.0f; }
	Color4f::Color4f(float _r, float _g, float _b, float _a/* = 255*/) { r = _r; g = _g; b = _b; a = _a; }
	Color4f::Color4f(const char* hexStr)
	{
		char digits[3];
		char* error;
		if (strlen(hexStr) != 8)
		{
			r = 1.0f;
			g = 1.0f;
			b = 1.0f;
			a = 1.0f;
		}
		digits[0] = *hexStr;
		digits[1] = *(hexStr + 1);
		digits[2] = '\0';
		r = (float)((int)((YosefUInt8)strtoul(digits, &error, 16)) / 255.0f);
		digits[0] = *(hexStr + 2);
		digits[1] = *(hexStr + 3);
		digits[2] = '\0';
		g = (float)((int)((YosefUInt8)strtoul(digits, &error, 16)) / 255.0f);
		digits[0] = *(hexStr + 4);
		digits[1] = *(hexStr + 5);
		digits[2] = '\0';
		b = (float)((int)((YosefUInt8)strtoul(digits, &error, 16)) / 255.0f);
		digits[0] = *(hexStr + 6);
		digits[1] = *(hexStr + 7);
		digits[2] = '\0';
		a = (float)((int)((YosefUInt8)strtoul(digits, &error, 16)) / 255.0f);
	}
	bool Color4f::operator==(const Color4f& right) const { return (r == right.r && g == right.g && b == right.b && a == right.a); }
	bool Color4f::operator!=(const Color4f& right) const { return !(r == right.r && g == right.g && b == right.b && a == right.a); }
	void Color4f::operator=(const Color4f& color) { r = color.r; g = color.g; b = color.b; a = color.a; checkError(); }
	Color4f Color4f::operator+(const Color4f& color) { Color4f temp(r + color.r, g + color.g, b + color.b, a + color.a); temp.checkError(); return temp; }
	Color4f Color4f::operator*(float v) { r = (r * v); g = (g * v); b = (b * v); a = (a * v); checkError();  return *this; }
	void Color4f::Set(float _r, float _g, float _b, float _a/* = 255*/) { r = _r; g = _g; b = _b; a = _a; checkError(); }
	void Color4f::checkError()
	{
		if (r > 1.0f) r = 1.0f;
		if (g > 1.0f) g = 1.0f;
		if (b > 1.0f) b = 1.0f;
		if (a > 1.0f) a = 1.0f;
	}
	std::ostream& operator<<(std::ostream& os, const Color4f& color)
	{
		os << color.r << " " << color.g << " "
			<< color.b << " " << color.a << " ";
		return os;
	}
	Color4f Lerp(Color4f from, Color4f to, float t) { return Color4f(from * t + to * (1.0f - t)); }
	const Color4f WHITE		= Color4f(1.0f, 1.0f, 1.0f, 1.0f);
	const Color4f YELLOW	= Color4f(1.0f, 1.0f, 0.0f, 1.0f);
	const Color4f BLUE		= Color4f(0.0f, 0.0f, 1.0f, 1.0f);
	const Color4f GREEN		= Color4f(0.0f, 1.0f, 0.0f, 1.0f);
	const Color4f RED		= Color4f(1.0f, 0.0f, 0.0f, 1.0f);
	const Color4f MAGENTA	= Color4f(1.0f, 0.0f, 1.0f, 1.0f);
	const Color4f BLACK		= Color4f(0.0f, 0.0f, 0.0f, 1.0f);
	const Color4f ORANGE	= Color4f(1.0f, 1.0f, 0.0f, 1.0f);
	const Color4f GRAY		= Color4f(0.16f, 0.16f, 0.16f, 1.0f);

	ColorHSB::ColorHSB()
	{
		h = 0;
		s = 0;
		b = 0;
	}

	ColorHSB::ColorHSB(YosefUInt8 r, YosefUInt8 g, YosefUInt8 b)
	{
		unsigned short max, min, delta;
		short temp;
		max = Max(r, g, b);
		min = Min(r, g, b);
		delta = max - min;
		if (max == 0)
		{
			s = h = b = 0;
			return;
		}

		b = (unsigned short)((double)max / 255.0 * 100.0);
		s = (unsigned short)(((double)delta / max) * 100.0);

		if (r == max)
			temp = (short)(60 * ((g - b) / (double)delta));
		else if (g == max)
			temp = (short)(60 * (2.0 + (b - r) / (double)delta));
		else
			temp = (short)(60 * (4.0 + (r - g) / (double)delta));

		if (temp < 0)
			h = temp + 360;
		else
			h = temp;
	}

	ColorHSB::ColorHSB(Color4B& color)
	{
		YosefUInt8 colorR = color.r, colorG = color.g, colorB = color.b;
		unsigned short max, min, delta;
		short temp;

		max = Max(colorR, colorG, colorB);
		min = Min(colorR, colorG, colorB);
		delta = max - min;

		if (max == 0)
		{
			s = h = b = 0;
			return;
		}

		b = (unsigned short)((double)max / 255.0 * 100.0);
		s = (unsigned short)(((double)delta / max) * 100.0);

		if (colorR == max)
			temp = (short)(60 * ((colorG - colorB) / (double)delta));
		else if (colorG == max)
			temp = (short)(60 * (2.0 + (colorB - colorR) / (double)delta));
		else
			temp = (short)(60 * (4.0 + (colorR - colorB) / (double)delta));

		if (temp < 0)
			h = temp + 360;
		else
			h = temp;
	}

	ColorHSB::ColorHSB(Color4f& color)
	{
		YosefUInt8 r = (YosefUInt8)color.r * 255;
		YosefUInt8 g = (YosefUInt8)color.g * 255;
		YosefUInt8 b = (YosefUInt8)color.b * 255;
		YosefUInt8 colorR = r, colorG = g, colorB = b;
		unsigned short max, min, delta;
		short temp;

		max = Max(colorR, colorG, colorB);
		min = Min(colorR, colorG, colorB);
		delta = max - min;

		if (max == 0)
		{
			s = h = b = 0;
			return;
		}

		b = (unsigned short)((double)max / 255.0 * 100.0);
		s = (unsigned short)(((double)delta / max) * 100.0);

		if (colorR == max)
			temp = (short)(60 * ((colorG - colorB) / (double)delta));
		else if (colorG == max)
			temp = (short)(60 * (2.0 + (colorB - colorR) / (double)delta));
		else
			temp = (short)(60 * (4.0 + (colorR - colorB) / (double)delta));

		if (temp < 0)
			h = temp + 360;
		else
			h = temp;
	}

	void ColorHSB::ToRGB(Color4B& color)
	{
		int conv;
		double hue, sat, val;
		int base;

		hue = (float)h / 100.0f;
		sat = (float)s / 100.0f;
		val = (float)b / 100.0f;

		if ((float)s == 0)
		{
			conv = (unsigned short)(255.0f * val);
			color.r = color.g = color.b = conv;
			color.a = 255;
			return;
		}

		base = (unsigned short)(255.0f * (1.0 - sat) * val);

		switch ((unsigned short)((float)h / 60.0f))
		{
		case 0:
			color.r = (unsigned short)(255.0f * val);
			color.g = (unsigned short)((255.0f * val - base) * (h / 60.0f) + base);
			color.b = base;
			break;

		case 1:
			color.r = (unsigned short)((255.0f * val - base) * (1.0f - ((h % 60) / 60.0f)) + base);
			color.g = (unsigned short)(255.0f * val);
			color.b = base;
			break;

		case 2:
			color.r = base;
			color.g = (unsigned short)(255.0f * val);
			color.b = (unsigned short)((255.0f * val - base) * ((h % 60) / 60.0f) + base);
			break;

		case 3:
			color.r = base;
			color.g = (unsigned short)((255.0f * val - base) * (1.0f - ((h % 60) / 60.0f)) + base);
			color.b = (unsigned short)(255.0f * val);
			break;

		case 4:
			color.r = (unsigned short)((255.0f * val - base) * ((h % 60) / 60.0f) + base);
			color.g = base;
			color.b = (unsigned short)(255.0f * val);
			break;

		case 5:
			color.r = (unsigned short)(255.0f * val);
			color.g = base;
			color.b = (unsigned short)((255.0f * val - base) * (1.0f - ((h % 60) / 60.0f)) + base);
			break;
		}
	}

	void ColorHSB::ToRGB(Color4f& color)
	{
		YosefUInt8 r = (YosefUInt8)color.r * 255;
		YosefUInt8 g = (YosefUInt8)color.g * 255;
		YosefUInt8 b = (YosefUInt8)color.b * 255;
		Color4B tmp(r, g, b);
		ToRGB(tmp);
	}

} // namespace yf
