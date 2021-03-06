#pragma once
#include <stdio.h>
#include <string.h>
#include "MyTCHAR.h"
#include "Definition.h"

//为写字母统计设计，只要文件的写操作正确，读内容不会有任何问题


//算一共有多少个英文字母，以便算比例，是个求数组所有元素之和的函数
size_t MySum(size_t* Arr, size_t size);


//打印字符总数
void ShowStatisticString(size_t CharaterNum);



//字符统计函数，核心在于里面的数组Alphabat占128个size_t，数组size足够asicii码的长度，
//算英文字母的话可以直接按照索引对应，比如扫描到一个a，Alphabat['a']这个元素直接自增
//另外一个核心是第32行，要考虑字符串被修改的情况
//在碎片整理前每个字符串的真实长度不一定是表中的Strenlength，而是要用strlen来计算
void LetterStatistics();
