
#include "AddString.h"
//�ж��Ƿ��п����õ���Ƭ�ռ䣬����з���true
bool HasCapableFragile(Flag* IndexArray, size_t uSpaceRequired, size_t* pIndex)
{
	
	size_t i = 0;
	//���������ڴ�������
	for (; i < g_uValidElemNum + g_uFragileElemNum; i++)
	{
		//������ڴ�εĳ����ܹ�����SpaceRequired��˵�����Դ洢
		if (IndexArray[i].IsFragile)
		{
			if (IndexArray[i].StringLength >= uSpaceRequired)
			{
				//����������ҷ���Ҫ����±�
				*pIndex = i;
				return true;
			}
		}
	}
	//���û�У��������±�Ϊ����Ԫ�ص��±� g_uValidElemNum + g_uFragileElemNum
	*pIndex = i;
	return false;
}

size_t AddString(Flag* IndexArray)
{
	size_t uIndex = 0;
	TCHAR buf[STRING_MAX_LENTH];
	GetString(buf, STRING_MAX_LENTH);
	//�����Ҫ����ַ����ĳ���
	size_t NewStringLength = TSTRLEN(buf) + 1;
	//�п�������Ƭ
	if (HasCapableFragile(IndexArray, NewStringLength, &uIndex))
	{
		//ִ�е������ʱ��g_INDEX�Ѿ�����ֵΪһ��������ڴ��ID��
		//�޸ĵĳ�����֮ǰ������ͬ�����
		if (IndexArray[uIndex].StringLength == NewStringLength)
		{   //�ȸ��ڴ�
			TSTRCPY(IndexArray[uIndex].pBufferBegin, buf);
			//�ٸ�����������ID��������������޸ģ�ֻ��Ҫ��������Ƭ����־��Ϊfalse
			IndexArray[uIndex].IsFragile = false;
			//����ȫ�ֱ�����Ҫ�仯����Ч�ַ�������+1,��Ƭ�ַ�������-1(��Ϊ������һ���ַ���������ַ�������������
			//ռ����Ѱ�ҵ�������ռ�,���������Ƭ��ʧ��)
			g_uValidElemNum++;
			g_uFragileElemNum--;
		}

		//��ӵĳ��ȱ�֮ǰ���ȶ̵����
		else
		{  //�ȸ��ڴ�
			TSTRCPY(IndexArray[uIndex].pBufferBegin, buf);
			//�ȼ�����²�������Ƭ���ȣ�Ϊ��ֵ���¸�Ԫ����׼������Ϊ��Ȼ������Ƭ��ƫ�Ʊ�Ҳ�ͱ�Ȼ���ģ���һ��Ԫ�ص�
			//����һ���������Ƭ����
			size_t NewFragileLength = IndexArray[uIndex].StringLength - NewStringLength;
			//�ٸ��������������ĵ�һ������������Ԫ�أ�ID���ø�,������������ͳһ������Ƭ����־��Ϊfalse�����ȸ�ΪNewStringLength
			IndexArray[uIndex].IsFragile = false;
			IndexArray[uIndex].StringLength = NewStringLength;
			//����ı�Ԫ�غ��ƣ�Ϊ��������Ƭ��׼��
			for (size_t i = g_uValidElemNum + g_uFragileElemNum; i > uIndex; i--)
			{
				IndexArray[i] = IndexArray[i - 1];
			}
			//���޸����µı�Ԫ�أ�ID����Ҫ������������ͳһ����
			//pBufferBegin��ǰһ��Ԫ�ر����ָ��+ǰһ��Ԫ�صĳ���
			IndexArray[uIndex + 1].pBufferBegin = IndexArray[uIndex].pBufferBegin + IndexArray[uIndex].StringLength;
			//��Ƭ��־Ϊ��
			IndexArray[uIndex + 1].IsFragile = true;
			//����Ϊ�����ָ����strlen
			IndexArray[uIndex + 1].StringLength = NewFragileLength;
			//��ЧԪ����Ŀ+1,��ƬԪ���������ֲ��䣨+1����Ϊ��һ���ڴ�ֳ������飬һ�������ЧԪ�أ���һ�黹����Ƭ��
			g_uValidElemNum++;
		}
	}

	//û�п���������Ƭλ��,������ĩβ�ӡ�ID����g_uValidElemNum+g_uFragileElemNum
	else
	{
		//��ƫ��
		size_t uOffset = 0;
		for (size_t i = 0; i < g_uValidElemNum + g_uFragileElemNum; i++)
		{
			uOffset += IndexArray[i].StringLength;
		}
		//�����ӵı�Ȼ��Ϊ��Ƭ
		IndexArray[g_uValidElemNum + g_uFragileElemNum].IsFragile = false;
		//�ڴ����ʼ��ַ
		IndexArray[g_uValidElemNum + g_uFragileElemNum].pBufferBegin = g_szBuf + uOffset;
		//���ַ���������ȥ
		TSTRCPY(IndexArray[g_uValidElemNum + g_uFragileElemNum].pBufferBegin, buf);
		//���Ⱦ����ַ�������
		IndexArray[g_uValidElemNum + g_uFragileElemNum].StringLength = NewStringLength;
		//��������λ��
		uIndex = g_uValidElemNum + g_uFragileElemNum;
		//������һ����ЧԪ��
		g_uValidElemNum++;
	}
	return uIndex;
}
