#define _CRT_SECURE_NO_WARNINGS
/*
	polymorphic2.cpp
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

UINT_PTR CalDistance(UINT_PTR a, UINT_PTR b)
{
	if (a > b)
	{
		return a - b;
	}
	else
	{
		return b - a;
	}
}
int _tmain(void)
{
	INT32 val1 = 10;
	INT32 val2 = 20;

	_tprintf(_T("Position %d, %d \n"), (UINT_PTR)&val1, (UINT_PTR)&val2);
	_tprintf(_T("distance %d \n"), CalDistance((UINT_PTR)&val1, (UINT_PTR)&val2));

	return 0;
}
