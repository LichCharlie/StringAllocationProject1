#pragma once
#include <stdio.h>
#include <string.h>
#include "MyTCHAR.h"
#include "Definition.h"

//Ϊд��ĸͳ����ƣ�ֻҪ�ļ���д������ȷ�������ݲ������κ�����


//��һ���ж��ٸ�Ӣ����ĸ���Ա���������Ǹ�����������Ԫ��֮�͵ĺ���
size_t MySum(size_t* Arr, size_t size);


//��ӡ�ַ�����
void ShowStatisticString(size_t CharaterNum);



//�ַ�ͳ�ƺ����������������������Alphabatռ128��size_t������size�㹻asicii��ĳ��ȣ�
//��Ӣ����ĸ�Ļ�����ֱ�Ӱ���������Ӧ������ɨ�赽һ��a��Alphabat['a']���Ԫ��ֱ������
//����һ�������ǵ�32�У�Ҫ�����ַ������޸ĵ����
//����Ƭ����ǰÿ���ַ�������ʵ���Ȳ�һ���Ǳ��е�Strenlength������Ҫ��strlen������
void LetterStatistics();
