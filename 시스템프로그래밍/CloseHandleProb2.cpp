/*
	CloseHandleProb2.cpp
	���α׷� ���� : CloseHandle �Լ� ���� 2.
*/

#include <stdio.h>
#include <windows.h>
#include <tchar.h>

int _tmain(int argc, TCHAR* argv[])
{
	DWORD n=0;
	while(n<100)
	{
		for(DWORD i=0; i<10000; i++)
			for(DWORD i=0; i<10000; i++); //Busy Waiting!!

		_fputts(_T("KernerlObjProb2.exe \n"), stdout); 
		n++;
	}

	return 0;
}
