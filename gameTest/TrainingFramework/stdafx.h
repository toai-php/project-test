// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#if WIN32
#define LOG(fmt, ...)		{printf(fmt, __VA_ARGS__); printf("\n");}
#endif
#define MEM_FREE(p)			{if (p != NULL) {delete p; p = NULL;}}
#define MEM_FREE1D(p)		{if (p != NULL) {delete[] p; p = NULL;}}
#define PI 3.14159265359


// TODO: reference additional headers your program requires here
