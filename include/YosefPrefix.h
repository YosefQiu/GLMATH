#pragma once
#define _00000000_00000000_00000000_00000001 1
#define _00000000_00000000_00000000_00000010 2
#define _00000000_00000000_00000000_00000100 4
#define _00000000_00000000_00000000_00001000 8
#define _00000000_00000000_00000000_00010000 16
#define _00000000_00000000_00000000_00100000 32
#define _00000000_00000000_00000000_01000000 64
#define _00000000_00000000_00000000_10000000 128
#define _00000000_00000000_00000001_00000000 256
#define _00000000_00000000_00000010_00000000 512
#define _00000000_00000000_00000100_00000000 1024
#define _00000000_00000000_00001000_00000000 2048
#define _00000000_00000000_00010000_00000000 4096
#define _00000000_00000000_00100000_00000000 8192
#define _00000000_00000000_01000000_00000000 16384
#define _00000000_00000000_10000000_00000000 32768
#define YOSEF_DEPRECATED __declspec(deprecated)
typedef signed char			YosefSInt8;
typedef unsigned char		YosefUInt8;
typedef YosefUInt8			YosefUByte;
typedef YosefSInt8			YosefByte;
typedef signed short		YosefSInt16;
typedef unsigned short		YosefUInt16;
typedef int					YosefSInt32;
typedef unsigned int		YosefUInt32;
typedef unsigned long long	YosefUInt64;
typedef signed long long	YosefSInt64;
typedef void*				YosefAny;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <numeric>