#pragma once
//#undef UNICODE
#ifdef UNICODE
#define _main wmain
#define TCHARSIGN (wchar_t)
#define TEXT(x) L##x
#define TCHAR wchar_t
#define TSTRCPY wcscpy
#define TPUTS fputws
#define TSTRLEN wcslen
#define TPRINTF wprintf
#define TFGETS fgetws
#define TGETCHAR getwchar
#define TSTRCMP wcscmp
#define TSTRSTR wcsstr

#else
#define _main main
#define TCHARSIGN 
#define TEXT(x) x
#define TCHAR char
#define TSTRCPY strcpy
#define TPUTS fputs
#define TSTRLEN strlen
#define TPRINTF printf
#define TFGETS fgets
#define TGETCHAR getchar
#define TSTRCMP strcmp
#define TSTRSTR strstr
#endif