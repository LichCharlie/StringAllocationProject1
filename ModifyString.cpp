#pragma once
#include "ModifyString.h"
/*
����������������
1.�޸ĺ���ַ������ȵ���֮ǰ��
2.�޸ĺ���ַ������ȴ���֮ǰ��
3.�޸ĺ���ַ������ȵ���֮ǰ��
*/
//�޸��ַ�������
//���ȣ��޷��޸���Ƭ��ֻ���޸�IsFragileΪfalse��
//Ȼ��������������
//1.����ǡ�õ��ڣ�2ԭ�����ڴ��㹻 3.�ڴ治��
void ModifyString(size_t ID)
{
	
	//�������Ƭ�������޸ģ�
	if (g_INDEX[ID].IsFragile)
	{
		TPUTS(TEXT("You can't modify a fragment.\n"),stdout);
	}
	//������Ƭ�����������
	else
	{
		//�Ȱ���Ҫд�����ַ���д�뻺����,��ǰ�ó���Ҫ�����ڴ�
		TPUTS(TEXT("Please input the new string.\n"), stdout);
		TCHAR buf[STRING_MAX_LENTH] = { 0 };
		GetString(buf, STRING_MAX_LENTH);
		size_t uModifyStringLength = TSTRLEN(buf)+1;

		//�������Ҫ�޸ĵ��ַ���������ȣ�ֻ��Ҫ����,ȫ�ֱ�������Ҫ�䶯
		if (uModifyStringLength == g_INDEX[ID].StringLength)
		{
			TSTRCPY(g_INDEX[ID].pBufferBegin, buf);
			TPUTS(TEXT("Modify Succeed.\n"), stdout);
		}
		//���ַ����������޷�װ�£�ԭ��Ϊɾ�������ڴ��������
		else if (uModifyStringLength > g_INDEX[ID].StringLength)
		{
			size_t offset = 0;
			//����ɾ��g_INDEX(ID)��ȫ�ֱ�����Ƭ������1����Ч�ַ���������1�����������ǲ����
			DeleteString(ID);
			//����ַ�����ճ����ַ ����� �����ڴ�g_szBuf��ƫ�� offset
			for (size_t i = 0; i < g_uValidElemNum + g_uFragileElemNum; i++)
			{
				offset += g_INDEX[i].StringLength;
			}
			//�ڴ濽�����
			TSTRCPY(g_szBuf + offset, buf);
			//����
			//������Ƭ
			g_INDEX[g_uValidElemNum + g_uFragileElemNum].IsFragile = false;
			//�ַ�����ʼ��ַ
			g_INDEX[g_uValidElemNum + g_uFragileElemNum].pBufferBegin = g_szBuf + offset;
			//�ַ�������
			g_INDEX[g_uValidElemNum + g_uFragileElemNum].StringLength = uModifyStringLength;
			//��Ч�ַ�����Ŀ+1
			g_uValidElemNum++;
			TPUTS(TEXT("Modify Succeed.\n"), stdout);
		}

		//ModifyStringLength < g_INDEX[ID].StringLength
		else
		{
			//�ȸ��ڴ�
			TSTRCPY(g_INDEX[ID].pBufferBegin, buf);
			//�����²�������Ƭ��С
			size_t NewFragileLength = g_INDEX[ID].StringLength - uModifyStringLength;
			//�ٸ��������������ĵ�һ������������Ԫ�أ�ID���øģ����ͳһ����,��Ƭ����־��Ϊfalse�����ȸ�ΪModifyStringLength
			g_INDEX[ID].IsFragile = false;
			g_INDEX[ID].StringLength = uModifyStringLength;

			//����ı�Ԫ�غ��ƣ�Ϊ��������Ƭ��׼��
			for (size_t i = g_uValidElemNum + g_uFragileElemNum; i > ID; i--)
			{
				g_INDEX[i] = g_INDEX[i - 1];
			}
			//���޸����µı�Ԫ�أ�ID����Ҫ����Ϊ������ �ǲ�����ƬΪ��׼��
			//pBufferBegin��ǰһ��Ԫ�ر����ָ��+ǰһ��Ԫ�صĳ���
			g_INDEX[ID + 1].pBufferBegin = g_INDEX[ID].pBufferBegin + g_INDEX[ID].StringLength;
			//��Ƭ��־Ϊ��
			g_INDEX[ID + 1].IsFragile = true;
			//����ΪNewFragileLength
			g_INDEX[ID + 1].StringLength = NewFragileLength;

			//��ƬԪ����Ŀ+1,��ЧԪ���������ֲ���
			g_uFragileElemNum++;
			TPUTS(TEXT("Modify Succeed.\n"), stdout);
		}

	}
}

