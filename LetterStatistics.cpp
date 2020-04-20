#include "LetterStatistics.h"
size_t MySum(size_t* Arr, size_t size)
{
	size_t uSum = 0;
	for (size_t i = 0; i < size; i++)
	{
		uSum += Arr[i];
	}
	return uSum;
}

//��ӡ�ַ�����
void ShowStatisticString(size_t uCharaterNum)
{
	if (uCharaterNum - 1)
		printf("Total: %u characters\n", uCharaterNum);
	else
		printf("Total: %u character\n", uCharaterNum);
}

//�ַ�ͳ�ƺ����������������������Alphabatռ128��size_t������size�㹻asicii��ĳ��ȣ�
//��Ӣ����ĸ�Ļ�����ֱ�Ӱ���������Ӧ������ɨ�赽һ��a��Alphabat['a']���Ԫ��ֱ������
//����һ�������ǵ�32�У�Ҫ�����ַ������޸ĵ����
//����Ƭ����ǰÿ���ַ�������ʵ���Ȳ�һ���Ǳ��е�Strenlength������Ҫ��strlen������
void LetterStatistics()
{
	TCHAR SumStatisticString[50] = { 0 };
	size_t Alphabat[128] = { 0 };
	size_t i = 0;
	size_t uTotalElemNum = g_uValidElemNum + g_uFragileElemNum;
	if (uTotalElemNum > 0)
	{
		while (i < uTotalElemNum)
		{
			size_t j = 0;
			if (!g_INDEX[i].IsFragile)
			{
				size_t uSTRLEN = TSTRLEN(g_INDEX[i].pBufferBegin) + 1;
				while (j <uSTRLEN)
				{
					if ((g_INDEX[i].pBufferBegin[j] >= TCHARSIGN'a' && g_INDEX[i].pBufferBegin[j] <= TCHARSIGN'z') ||
						(g_INDEX[i].pBufferBegin[j] >= TCHARSIGN'A' && g_INDEX[i].pBufferBegin[j] <= TCHARSIGN'Z'))
					{
						Alphabat[g_INDEX[i].pBufferBegin[j]]++;
					}
					++j;
				}
			}
			++i;
		}
		size_t uSum = MySum(Alphabat, sizeof(Alphabat) / sizeof(*Alphabat));
		ShowStatisticString(uSum);
		for (size_t i = 0; i < 26; i++)
		{
			TPRINTF(TEXT("%c appears for %u times,propotion:%4.2f%%\n"), TCHARSIGN'A' + i, Alphabat[TCHARSIGN'A' + i],(100 *( (float)Alphabat[TCHARSIGN'A' + i] / uSum)));
			TPRINTF(TEXT("%c appears for %u times,propotion:%4.2f%%\n"), TCHARSIGN'a' + i, Alphabat[TCHARSIGN'a' + i], (100 *( (float)Alphabat[TCHARSIGN'a' + i] / uSum)));
		}
	}
}