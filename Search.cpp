#include "Search.h"

//0 id���� 1 �ַ������� 2ģ���ַ�������
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
//�ж�ID�Ƿ���ڲ��ҺϷ��ĺ���
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
	//�ж������Ƿ�Ϸ�
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
//�ж������str�Ƿ����
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
//������StringExist������ӡ���ڵĺ����������ӡ������
void SearchByString()
{  //������鰴��˳���¼������ͬ�Ӵ����ڴ�ID
	size_t uIndexArr[100] = { 0 };
	size_t uStringNum = 0;
	TPUTS(TEXT("put your string you are looking for.\n"), stdout);
	TCHAR buf[STRING_MAX_LENTH] = { 0 };
	//��Ҫ��ѯ���ַ�������buf
	GetString(buf, STRING_MAX_LENTH);
	//exist���������ж��Ƿ����Ҫ��ѯ�����ݣ�����StringNum�������ݣ������Ƿ���Ҫ�󴮵ĸ���
	if (StringExist(buf, uIndexArr, &uStringNum))
	{
		//ֻ��Ҫѭ������Ҫ��Ĵ��Ĵ���
		for (size_t i = 0; i < uStringNum; i++)
		{
			//���б�IndexArr[i]��ֵ�Ƿ���Ҫ�󴮵�ID
			TPRINTF(TEXT("ID:%u  %s\n"), g_INDEX[uIndexArr[i]].ID, g_INDEX[uIndexArr[i]].pBufferBegin);
		}
	}
	else
	{
		TPRINTF(TEXT("\"%s\"does not exist\n"), buf);
	}

}

void SearchAccurateString()
{  //������鰴��˳���¼������ȫ��ͬ�Ӵ����ڴ�ID
	TPUTS(TEXT("put your string you are looking for.\n"), stdout);
	TCHAR buf[STRING_MAX_LENTH] = { 0 };
	//��Ҫ��ѯ���ַ�������buf
	GetString(buf, STRING_MAX_LENTH);
	//��ȫƥ��Ĵ��Ƿ���ڣ���Ĭ�ϲ�����
	bool IsExisted = false;
	for (size_t i = 0; i < g_uValidElemNum + g_uFragileElemNum; i++)
	{
		if (!g_INDEX[i].IsFragile)
		{
			if (TSTRCMP(g_INDEX[i].pBufferBegin, buf) == 0)
			{
				//�ҵ����Ϊ����
				IsExisted = true;
				TPRINTF(TEXT("ID:%u  %s\n"), g_INDEX[i].ID, g_INDEX[i].pBufferBegin);
			}
		}
	}
	//������
	if(!IsExisted)
	{
		TPRINTF(TEXT("\"%s\"does not exist\n"), buf);
	}

}