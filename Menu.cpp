#include "Menu.h"
const TCHAR* MenuOption[9] =
{
	TEXT("1.Add String"),
	TEXT("2.Delete String"),
	TEXT("3.Modify String"),
	TEXT("4.Search String(By ID+By String)"),
	TEXT("5.Memory Map"),
	TEXT("6.Letter Statistics"),
	TEXT("7.Disk Fragment Sort"),
	TEXT("8.ShowStrings"),
	TEXT("9.Quit")
};
//画菜单
void DrawMenu()
{
	int i = 0;
	TPRINTF(TEXT("Memory Allocation Project----------LEI ZHANG\n"));
	while (i < sizeof(MenuOption) / sizeof(*MenuOption))
	{
		TPRINTF(TEXT("%s\n"), MenuOption[i]);
		++i;
	}
}
//选择
int Switch()
{
	TCHAR buf[100] = { 0 };
	TCHAR buf2[100] = { 0 };
	TPUTS(TEXT("Menu:Have a choose from 1-9\n"),stdout);
	//输入选项
	GetString(buf, 100);
	//保证无效输入导致函数结束，并且过滤无效输入。只有输入'0'-'9'才能进入内层函数
	if (Filter(buf, 1, '0', '9'))
	{
		switch (*buf)
		{
			//添加
		case '1':
		{
			TPUTS(TEXT("Please input your string.\n"), stdout);
			size_t uID=AddString(g_INDEX);
			MergeIndexList(g_INDEX);
			TPRINTF(TEXT("ID:%u  String:%s  Length:%u\n"), g_INDEX[uID].ID, g_INDEX[uID].pBufferBegin, g_INDEX[uID].StringLength);
			break;
		}
		//删除
		case '2':
		{
			TPUTS(TEXT("Please input the ID of the string you want to delete.\n"),stdout);
		size_t uIDDelete;
		if (SpecificOptions(buf2, &uIDDelete, '0', '9',g_uValidElemNum + g_uFragileElemNum, DeleteString))
		{
			TPUTS(TEXT("Delete Succeed.\n"), stdout);
			MergeIndexList(g_INDEX);
		}
			break;
		}
		//修改
		case '3':
		{
			TPUTS(TEXT("Please input the ID of the string you want to modify.\n"),stdout);
			size_t uIDMofidy;
		    if (SpecificOptions(buf2, &uIDMofidy, '0', '9', g_uValidElemNum + g_uFragileElemNum, ModifyString))
			{
				MergeIndexList(g_INDEX);
			}
			break;
		}
		//查询
		case '4':
		{
			TPUTS(TEXT("Input the g_INDEX of Search Pattern\n"), stdout);
			TPUTS(TEXT("0:ID Search\n"), stdout);
			TPUTS(TEXT("1:Accurate Search\n"), stdout);
			TPUTS(TEXT("2:Fuzzy Search\n"), stdout);
			size_t uSerachID;
			SpecificOptions(buf2, &uSerachID, '0', '3',3, SearchOption);
			break;
		}
		//内存打印
		case '5':
		{
			ShowMemory();
			break;
		}
		//字符统计
		case '6':
		{
			LetterStatistics();
			break;
		}
		//碎片整理
		case '7':
		{
			DiskSort();
			TPUTS(TEXT("Memory sorted!\n"), stdout);
			MergeIndexList(g_INDEX);
			break;
		}
		//字符串打印
		case '8':
		{
			ShowStrings();
			break;
		}
		//退出
		case '9':
		{
			TPUTS(TEXT("Bye!\n"), stdout);
			break;
		}
		}
		return *buf;
	}
}
