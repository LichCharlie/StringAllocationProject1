#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "MyTCHAR.h"
#include <stdio.h>
#include <stdlib.h>
#include "AddString.h"
#include"Definition.h"
#include "FilterFunction.h"
#include "GetString.h"
#include "ModifyString.h"
#include "Search.h"
#include "MergeIndexList.h"
#include "ShowMemory.h"
#include "ShowString.h"
#include "DiskFragment.h"
#include "LetterStatistics.h"
//#include "DiskFragmentSort.h"
//�˵��ַ���
extern const TCHAR* MenuOption[9];
//���˵�
void DrawMenu();

//ѡ��
int Switch();

