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

//打印字符总数
void ShowStatisticString(size_t uCharaterNum)
{
	if (uCharaterNum - 1)
		printf("Total: %u characters\n", uCharaterNum);
	else
		printf("Total: %u character\n", uCharaterNum);
}

//字符统计函数，核心在于里面的数组Alphabat占128个size_t，数组size足够asicii码的长度，
//算英文字母的话可以直接按照索引对应，比如扫描到一个a，Alphabat['a']这个元素直接自增
//另外一个核心是第32行，要考虑字符串被修改的情况
//在碎片整理前每个字符串的真实长度不一定是表中的Strenlength，而是要用strlen来计算
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