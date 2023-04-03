/*
	MailReceiver.cpp
	���α׷� ���� : ���Ͻ��� Receiver
*/

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define SLOT_NAME    _T("\\\\.\\mailslot\\mailbox")

int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hMailSlot;  //mailslot �ڵ�
	TCHAR messageBox[50];
  DWORD bytesRead;  // number of bytes read

	/* mailslot ���� */
	hMailSlot=CreateMailslot(SLOT_NAME, 0, MAILSLOT_WAIT_FOREVER, NULL);
	if(hMailSlot==INVALID_HANDLE_VALUE)
	{
		_fputts(_T("Unable to create mailslot!\n"), stdout);
		return 1;
	}

	/* Message ���� */
	_fputts(_T("******** Message ********\n"), stdout);
	while(1)
	{
		if(!ReadFile(hMailSlot, messageBox, sizeof(TCHAR)*50, &bytesRead, NULL))
		{
			_fputts(_T("Unable to read!"), stdout);
			CloseHandle(hMailSlot);
			return 1;
		}

		if(!_tcsncmp(messageBox, _T("exit"), 4))
		{
			_fputts(_T("Good Bye!"), stdout);
			break;
		}

		messageBox[bytesRead/sizeof(TCHAR)]=0; //NULL ���� ����.
		_fputts(messageBox, stdout);
	}

	CloseHandle(hMailSlot);
	return 0;
}
