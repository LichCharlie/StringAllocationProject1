
#include "DiskFragment.h"
/*
之前已经保证表和全局变量都是正确的，现在只遍历每个表元素
如果它是碎片，把它右侧的所有内存向左移，并把它覆盖，同时碎片数目-1,
而最后一个表元素单独处理，因为它后面没有元素可搬运了
*/
void FragileStringRemoveLoop()
{
	//需要遍历的元素数量
	size_t uTotalElemNum = g_uValidElemNum + g_uFragileElemNum;
	//需要删除的元素数量,先设为0,然后在下面自增（碎片数量）
	size_t uDeletedStringCount = 0;
	//遍历每个元素
	for (int i = 0; i < uTotalElemNum; i++)
	{
		//前提是碎片
		if (g_INDEX[i].IsFragile == true)
		{
			//如果遍历到最后一个元素并且它是碎片
			if (i + 1 == uTotalElemNum)
			{
				//把碎片都初始化为‘\0’
				for (size_t k = 0; k < g_INDEX[i].StringLength -1; k++)
				{
					g_INDEX[i].pBufferBegin[k] = TCHARSIGN'\0';
				}
				//不再是碎片
				g_INDEX[i].IsFragile = false;
				//长度为0
				g_INDEX[i].StringLength = 0;
				//删除的元素数量++
				uDeletedStringCount++;
				break;
			}
			//不是最后一个元素
			else if (!(i + 1 == uTotalElemNum))
			{
				//先挪内存，暂时不管表的数据
				//需要向左挪动的内存
				size_t offset = g_INDEX[i].StringLength; 
				for (int j = i; j < uTotalElemNum; j++)
				{
					for (int s = 0; s < g_INDEX[j + 1].StringLength; s++)
					{
						(g_INDEX[j + 1].pBufferBegin - offset)[s] = g_INDEX[j + 1].pBufferBegin[s];
					}
				}

				//挪表
				for (int k = i; k < uTotalElemNum; k++)
				{
					g_INDEX[k + 1].pBufferBegin -= offset;
					g_INDEX[k] = g_INDEX[k + 1];
				}
				uDeletedStringCount++;
			}
		}
	}
	//更新元素数量，保证有效的表元素和字符串数量相等
	g_uFragileElemNum -= uDeletedStringCount;
}


void DiskSort()
{

	FragileStringRemoveLoop();

}

