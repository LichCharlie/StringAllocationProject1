#include "Definition.h"
//��¼�ܹ��ж��ٸ���Ч�ڴ��
//size_t ElemNum = 0;
size_t g_uFragileElemNum = 0;
size_t g_uValidElemNum=0;
/*
����ÿ��buf�ı��
1.ID
2.��ʼ��ַ
3.�ַ���ԭ������
4.�ַ���ʵ�ʳ���
*/

//�ڴ�
TCHAR g_szBuf[1024 * 1024] = { 0 };
//�ַ������Ա����飬���Ǹ��ṹ������
Flag g_INDEX[100];