#define _CRT_SECURE_NO_WARNINGS
#define UNICODE
#define _UNICODE

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	LPTSTR str1 = _T("MBCS or WBCS 1"); //포인터로 문자를 받아옴
	TCHAR str2[] = _T("MBCS or WBCS 2");
	TCHAR str3[100];
	TCHAR str4[50];

	LPCTSTR pStr = str1;
	_tprintf(_T("string size: %d \n"), sizeof(str2)/*연산자라 변화가 없음*/);
	_tprintf(_T("string length: %d \n"), _tcslen(pStr));

	_fputts(_T("Input string 1 : "), stdout);
	_tscanf(_T("%s"), str3);
	_fputts(_T("Input string 2 : "), stdout);
	_tscanf(_T("%s"), str4);
	
	_tcscat(str3, str4);
	_tprintf(_T("String1 + String2 : %s \n"), str3);
	return 0;
}
