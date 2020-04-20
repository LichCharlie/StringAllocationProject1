#include "ShowMemory.h"

/*
内存状态打印，U占用，F非占用
根据删除标记作为判断条件，ElemNum作为循环条件来打印到屏幕
*/
void ShowMemory()
{
	size_t uNum = 0;
	for (size_t i = 0; i <  g_uFragileElemNum+g_uValidElemNum; i++)
	{
		for (size_t j = 0; j < g_INDEX[i].StringLength; j++)
		{
			//32个字符换一行，并打印地址，美观
			if (uNum % 0x20 == 0)
			{
				putchar('\n');
				TPRINTF(TEXT("%p "), g_szBuf + uNum);
			}
			//不是碎片打印U
			if (!g_INDEX[i].IsFragile)
			{
				uNum++;
				putchar('U');
			}
			//是碎片打印F
			else if (g_INDEX[i].IsFragile)
			{
				uNum++;
				putchar('F');
			}
		}
	}
	putchar('\n');
}