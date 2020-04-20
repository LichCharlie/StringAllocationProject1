#include "Definition.h"
//记录总共有多少个有效内存块
//size_t ElemNum = 0;
size_t g_uFragileElemNum = 0;
size_t g_uValidElemNum=0;
/*
管理每个buf的标记
1.ID
2.起始地址
3.字符串原本长度
4.字符串实际长度
*/

//内存
TCHAR g_szBuf[1024 * 1024] = { 0 };
//字符串属性表数组，就是个结构体数组
Flag g_INDEX[100];