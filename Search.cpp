#include "Search.h"

//0 id搜索 1 字符串搜索 2模糊字符串搜索
void SearchOption(size_t option)
{
	switch (option)
	{
	case 0:
		SearchByID();
		break;
	case 1:
		SearchAccurateString();
		break;
	case 2:
		SearchByString();
		break;
	}
}
//判断ID是否存在并且合法的函数
bool IDExist(size_t* pID, TCHAR* buf)
{
	bool flag = false;
	if (Filter(buf, STRING_MAX_LENTH, '0', '9'))
	{
		*pID = GetID(buf);
		if ((IdentifyValidID(*pID, g_uValidElemNum+g_uFragileElemNum) && g_INDEX[*pID].IsFragile == false))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
void SearchByID()
{

	size_t uID = 0;
	TCHAR buf[STRING_MAX_LENTH] = { 0 };
	TPRINTF(TEXT("Input the ID of the string (0 - %u)\n"), g_uValidElemNum - 1);
	//判断输入是否合法
	GetString(buf, STRING_MAX_LENTH);

	if (IDExist(&uID, buf))
	{
		TPRINTF(TEXT("ID:%u string:%s\n"), g_INDEX[uID].ID, g_INDEX[uID].pBufferBegin);
	}
	else
	{
		TPUTS(TEXT("Invalid ID or Deleted string.\n"), stdout);
	}
}
//判断输入的str是否存在
bool StringExist(TCHAR* buf, size_t* IDIndex, size_t* pStringNum)
{
	size_t i = 0;
	size_t TotalElemNum = g_uValidElemNum + g_uFragileElemNum;
	size_t ConditionalStringNum = 0;
	bool StrExisted = false;
	while (i < TotalElemNum)
	{
		if (g_INDEX[i].IsFragile == false)
		{
			if (TSTRSTR(g_INDEX[i].pBufferBegin, buf))
			{
				StrExisted = true;
				IDIndex[ConditionalStringNum] = i;
				++ConditionalStringNum;
			}
		}
		i++;
	}
	*pStringNum = ConditionalStringNum;
	return StrExisted;
}
//调用了StringExist（）打印存在的函数，否则打印不存在
void SearchByString()
{  //这个数组按照顺序记录出现相同子串的内存ID
	size_t uIndexArr[100] = { 0 };
	size_t uStringNum = 0;
	TPUTS(TEXT("put your string you are looking for.\n"), stdout);
	TCHAR buf[STRING_MAX_LENTH] = { 0 };
	//把要查询的字符串传入buf
	GetString(buf, STRING_MAX_LENTH);
	//exist函数不但判断是否存在要查询的内容，还向StringNum传出内容，内容是符合要求串的个数
	if (StringExist(buf, uIndexArr, &uStringNum))
	{
		//只需要循环符合要求的串的次数
		for (size_t i = 0; i < uStringNum; i++)
		{
			//表中表，IndexArr[i]的值是符合要求串的ID
			TPRINTF(TEXT("ID:%u  %s\n"), g_INDEX[uIndexArr[i]].ID, g_INDEX[uIndexArr[i]].pBufferBegin);
		}
	}
	else
	{
		TPRINTF(TEXT("\"%s\"does not exist\n"), buf);
	}

}

void SearchAccurateString()
{  //这个数组按照顺序记录出现完全相同子串的内存ID
	TPUTS(TEXT("put your string you are looking for.\n"), stdout);
	TCHAR buf[STRING_MAX_LENTH] = { 0 };
	//把要查询的字符串传入buf
	GetString(buf, STRING_MAX_LENTH);
	//完全匹配的串是否存在，先默认不存在
	bool IsExisted = false;
	for (size_t i = 0; i < g_uValidElemNum + g_uFragileElemNum; i++)
	{
		if (!g_INDEX[i].IsFragile)
		{
			if (TSTRCMP(g_INDEX[i].pBufferBegin, buf) == 0)
			{
				//找到后改为存在
				IsExisted = true;
				TPRINTF(TEXT("ID:%u  %s\n"), g_INDEX[i].ID, g_INDEX[i].pBufferBegin);
			}
		}
	}
	//不存在
	if(!IsExisted)
	{
		TPRINTF(TEXT("\"%s\"does not exist\n"), buf);
	}

}