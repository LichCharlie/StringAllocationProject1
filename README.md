# StringAllocationProject1

This project is a tiny tiny toyy memory allocation project to practice my coding control capabality.

下面用中文复制下项目内容吧，英文懒得写啦，毕竟是玩具项目。 要求在指定数组内存储字符串 功能：

在char g_szBuf[1024*1024]中操作内存

增加: 完成对字符串的增加操作，最长不超过100个字节。
删除：完成对字符串的删除操作
修改：可修改指定的字符串，如果空间长度不够则存储在其他地方，原字符串视为被删除。
查询：可按字符串内容、地址或者编号等不同方式查找字符串的基本信息，要求支持模糊查找。
统计：可统计每个字母的出现次数和比例。
存储信息：显示存储的资源分布，如windows提供的磁盘碎片整理图，按顺序显示各种已分配、未分配资源。举例，如存储空间为10字节，可以用一个F表示空 闲区域一字节，一个U表示已使用区域一字节：UFUUFFFUUU。
并提供碎片整理功能。
本项目不允许使用malloc和new系列功能。
注释： 本项目是在Visual Studio 2019 IDE下完成的。

如果你想直接编译生成可执行文件，直接把.h文件和.cpp文件全部添加到你的工程即可编译成功。

本项目经过了一次修改，进行了ASCII和UNICODE的条件编译版本。如果调整版本只需要调整编译选项，或者直接对main函数里的#undef UNICODE进行注释或者取消注释即可！
