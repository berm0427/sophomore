/* 
	MailSender2_2.cpp
	���α׷� ���� : �ڵ��� ��� Ȯ�ο� ����2.
*/

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hMailSlot; 
	TCHAR message[50];
    DWORD bytesWritten;  // number of bytes write

	/************* �ڵ��� ��� �ڵ� *****************/

	FILE* file=_tfopen(_T("C:\\source\\0424\\InheritableHandle.txt"), _T("rt"));
	_ftscanf(file, _T("%d"), &hMailSlot);
	fclose(file);

	_tprintf(_T("Inheritable Handle : %d \n"), hMailSlot);

	/**********************************************/

	while(1)
	{
		_fputts(_T("MY CMD>"), stdout);
		_fgetts(message, sizeof(message)/sizeof(TCHAR), stdin);

		if(!WriteFile(hMailSlot, message, _tcslen(message)*sizeof(TCHAR), &bytesWritten, NULL))
		{
			_fputts(_T("Unable to write!"), stdout);
			_gettchar();
			CloseHandle(hMailSlot);
			return 1;
		}

		if(!_tcscmp(message, _T("exit")))
		{
			_fputts(_T("Good Bye!"), stdout);
			break;
		}
	}

	CloseHandle(hMailSlot);
	return 0;
}
