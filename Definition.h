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
//�ַ������Ա����飬���Ǹ��ṹ������
extern Flag g_INDEX[100];