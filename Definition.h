#pragma once
#include "MyTCHAR.h"
#define _CRT_SECURE_NO_WARNINGS
#define STRING_MAX_LENTH 100
struct Flag
{
	size_t ID;
	TCHAR* pBufferBegin;
	size_t StringLength;
	bool IsFragile=false;
};
extern size_t g_uValidElemNum;
extern size_t g_uFragileElemNum;
extern struct Flag;
extern TCHAR g_szBuf[1024 * 1024];
//字符串属性表数组，就是个结构体数组
extern Flag g_INDEX[100];