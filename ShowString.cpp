#include "ShowString.h"
//展示字符串
void ShowStrings()
{
	TPRINTF(TEXT("TotalElemNum=%d\n"),g_uValidElemNum+g_uFragileElemNum);
	TPRINTF(TEXT("g_uValidElemNum=%d\n"), g_uValidElemNum );
	TPRINTF(TEXT("g_uFragileElemNum=%d\n"),  g_uFragileElemNum);
	for (size_t i = 0; i < g_uValidElemNum + g_uFragileElemNum; i++)
	{   //只要不是碎片就打印
		if (!g_INDEX[i].IsFragile)
		{
			TPRINTF(TEXT("ID: %u  StringLength:%-3u  String: %s\n"), g_INDEX[i].ID, g_INDEX[i].StringLength, g_INDEX[i].pBufferBegin);
		}
		//如果是碎片也显示它是碎片
		else
		{
			TPRINTF(TEXT("ID: %u  Fragment\n"), g_INDEX[i].ID);
		}
	}
}
