/*
	CloseHandleProb1.cpp
	���α׷� ���� : CloseHandle �Լ� ���� 1.
*/

#include <stdio.h>
#include <windows.h>
#include <tchar.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si={0,};
	PROCESS_INFORMATION pi;
	
	si.cb=sizeof(si);

	TCHAR command[]=_T("KernerlObjProb2.exe");

	CreateProcess(NULL,     // ���μ��� ����.
			      command, NULL, NULL, TRUE, 
				  0, NULL, NULL, &si, &pi
	);  //CreateProcess

	CloseHandle(pi.hProcess);

	return 0;
}
