#define _CRT_SECURE_NO_WARNINGS
/*
	polymorphic.cpp
*/

#include <stdio.h>https://github.com/berm0427/sophomore
#include <tchar.h>
#include <windows.h>

UINT CalDistance(UINT a, UINT b)
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
	INT val1 = 10;
	INT val2 = 20;

	_tprintf(_T("Position %d, %d \n"), (UINT)&val1, (UINT)&val2);
	_tprintf(_T("distance %d \n"), CalDistance((UINT)&val1, (UINT)&val2));

	return 0;
}
