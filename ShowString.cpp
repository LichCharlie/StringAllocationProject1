#include "ShowString.h"
//չʾ�ַ���
void ShowStrings()
{
	TPRINTF(TEXT("TotalElemNum=%d\n"),g_uValidElemNum+g_uFragileElemNum);
	TPRINTF(TEXT("g_uValidElemNum=%d\n"), g_uValidElemNum );
	TPRINTF(TEXT("g_uFragileElemNum=%d\n"),  g_uFragileElemNum);
	for (size_t i = 0; i < g_uValidElemNum + g_uFragileElemNum; i++)
	{   //ֻҪ������Ƭ�ʹ�ӡ
		if (!g_INDEX[i].IsFragile)
		{
			TPRINTF(TEXT("ID: %u  StringLength:%-3u  String: %s\n"), g_INDEX[i].ID, g_INDEX[i].StringLength, g_INDEX[i].pBufferBegin);
		}
		//�������ƬҲ��ʾ������Ƭ
		else
		{
			TPRINTF(TEXT("ID: %u  Fragment\n"), g_INDEX[i].ID);
		}
	}
}
