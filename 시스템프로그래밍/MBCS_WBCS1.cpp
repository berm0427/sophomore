#define UNICODE
#define _UNICODE

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int wmain(void)
{
	TCHAR str[] = _T("1234567"); // XP이후에 코드를 전부 유니코드화 해놓음
	int size = sizeof(str);
	printf("string length : %d \n",size);

	return 0;
}
