/*
	ListProcessInfo.cpp
	���α׷� ����: ���� �������� ���μ��� ���� ���
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <tlhelp32.h>

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hProcessSnap =
	CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("CreateToolhelp32Snapshot error! \n"));
		return -1;
	}

	/* ���μ��� ������ ��� ���� ����ü ���� */
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(hProcessSnap, &pe32))
	{
		_tprintf(_T("Process32First error! \n"));
		CloseHandle(hProcessSnap);
		return -1;
	}


	do
	{
		/* ���μ��� �̸�, ID ���� ��� */
		_tprintf(_T("%25s %5d \n"),pe32.szExeFile, pe32.th32ProcessID);
	} while (Process32Next(hProcessSnap, &pe32));
}