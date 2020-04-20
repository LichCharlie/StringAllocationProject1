
#include "DiskFragment.h"
/*
֮ǰ�Ѿ���֤���ȫ�ֱ���������ȷ�ģ�����ֻ����ÿ����Ԫ��
���������Ƭ�������Ҳ�������ڴ������ƣ����������ǣ�ͬʱ��Ƭ��Ŀ-1,
�����һ����Ԫ�ص���������Ϊ������û��Ԫ�ؿɰ�����
*/
void FragileStringRemoveLoop()
{
	//��Ҫ������Ԫ������
	size_t uTotalElemNum = g_uValidElemNum + g_uFragileElemNum;
	//��Ҫɾ����Ԫ������,����Ϊ0,Ȼ����������������Ƭ������
	size_t uDeletedStringCount = 0;
	//����ÿ��Ԫ��
	for (int i = 0; i < uTotalElemNum; i++)
	{
		//ǰ������Ƭ
		if (g_INDEX[i].IsFragile == true)
		{
			//������������һ��Ԫ�ز���������Ƭ
			if (i + 1 == uTotalElemNum)
			{
				//����Ƭ����ʼ��Ϊ��\0��
				for (size_t k = 0; k < g_INDEX[i].StringLength -1; k++)
				{
					g_INDEX[i].pBufferBegin[k] = TCHARSIGN'\0';
				}
				//��������Ƭ
				g_INDEX[i].IsFragile = false;
				//����Ϊ0
				g_INDEX[i].StringLength = 0;
				//ɾ����Ԫ������++
				uDeletedStringCount++;
				break;
			}
			//�������һ��Ԫ��
			else if (!(i + 1 == uTotalElemNum))
			{
				//��Ų�ڴ棬��ʱ���ܱ������
				//��Ҫ����Ų�����ڴ�
				size_t offset = g_INDEX[i].StringLength; 
				for (int j = i; j < uTotalElemNum; j++)
				{
					for (int s = 0; s < g_INDEX[j + 1].StringLength; s++)
					{
						(g_INDEX[j + 1].pBufferBegin - offset)[s] = g_INDEX[j + 1].pBufferBegin[s];
					}
				}

				//Ų��
				for (int k = i; k < uTotalElemNum; k++)
				{
					g_INDEX[k + 1].pBufferBegin -= offset;
					g_INDEX[k] = g_INDEX[k + 1];
				}
				uDeletedStringCount++;
			}
		}
	}
	//����Ԫ����������֤��Ч�ı�Ԫ�غ��ַ����������
	g_uFragileElemNum -= uDeletedStringCount;
}


void DiskSort()
{

	FragileStringRemoveLoop();

}

