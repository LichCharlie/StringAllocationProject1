#include "ShowMemory.h"

/*
�ڴ�״̬��ӡ��Uռ�ã�F��ռ��
����ɾ�������Ϊ�ж�������ElemNum��Ϊѭ����������ӡ����Ļ
*/
void ShowMemory()
{
	size_t uNum = 0;
	for (size_t i = 0; i <  g_uFragileElemNum+g_uValidElemNum; i++)
	{
		for (size_t j = 0; j < g_INDEX[i].StringLength; j++)
		{
			//32���ַ���һ�У�����ӡ��ַ������
			if (uNum % 0x20 == 0)
			{
				putchar('\n');
				TPRINTF(TEXT("%p "), g_szBuf + uNum);
			}
			//������Ƭ��ӡU
			if (!g_INDEX[i].IsFragile)
			{
				uNum++;
				putchar('U');
			}
			//����Ƭ��ӡF
			else if (g_INDEX[i].IsFragile)
			{
				uNum++;
				putchar('F');
			}
		}
	}
	putchar('\n');
}