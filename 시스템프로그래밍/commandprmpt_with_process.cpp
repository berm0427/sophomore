#define _CRT_SECURE_NO_WARNINGS
/*
	CommandPrmpt_with_Process.cpp
*/

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <tlhelp32.h>

#define STR_LEN 256
#define CMD_TOKEN_NUM 10

TCHAR ERROR_CMD[]
= _T("'%s'��(��) ������ �� �ִ� ���α׷��� �ƴմϴ�. \n");
TCHAR cmdString[STR_LEN];
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");
int CmdProcessing(int);
int cmdReadTokenize(void);
TCHAR* StrLower(TCHAR*);
int ListProcessInfo();
void KillProcess();
int _tmain(int argc, TCHAR* argv[])
{
	//�ѱ� �Է��� �����ϰ� �ϱ� ����
	_tsetlocale(LC_ALL, _T("Korean"));
	/* �Ű� ���� �������� ó���� (start ��ɾ� ����)*/
	if (argc > 2)
	{
		for (int i = 1; i < argc; i++)
		{
			_tcscpy(cmdTokenList[i - 1], argv[i]);
		}
		CmdProcessing(argc - 1);
	}


	DWORD isExit = NULL;
	while (1)
	{
		int tokenNum = cmdReadTokenize();

		if (tokenNum == 0) /* Enter �Է�ó�� ���� �κ� */
		{
			continue;
		}

		isExit = CmdProcessing(tokenNum);
		if (isExit == TRUE)
		{
			_fputts(_T("��ɾ� ó���� �����մϴ�. \n"), stdout);
			break;
		}
	}
	return 0;
}
/********************************
�Լ�: int cmdReadTokenize(void)
��� �� �ؼ�:
CommandPrmpt_with_notepad.cpp�� CmdProcessing �Լ��� ������� ������ �Է¹޴� ��ɰ�
���ÿ� ���� ��ɾ� ó������� ���ÿ� ������ �ִ�. �̿� ������� ������ �Է¹޴� �����
CmdReadTokenize�� �и��� ��ɾ main �Լ��� ���� ���޵Ǵ� ��쿡�� ����� �Է��� ���ʿ��� ��쿡 �����
*********************************/
int cmdReadTokenize(void)
{
	TCHAR* token;

	_fputts(_T("Best command prompt>> "), stdout);
	_getts_s(cmdString, sizeof(cmdString));
	token = _tcstok(cmdString, seps);
	int tokenNum = 0;
	while (token != NULL)
	{
		_tcscpy(cmdTokenList[tokenNum++], StrLower(token));
		token = _tcstok(NULL, seps);
	}

	return tokenNum;
}


/********************************
�Լ�: int Cmdprocessing(void)
���: ��ɾ �Է¹޾Ƽ� �ش� ��ɾ ����Ǿ� �ִ� ����� �����Ѵ�.
		exit�� �ԷµǸ� TRUE�� ��ȯ�ϰ� ���α׷��� ����� �̾�����
*********************************/
int CmdProcessing(int tokenNum)
{
	BOOL isRun;
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;

	TCHAR cmdstringWithOptions[STR_LEN] = { 0, };
	TCHAR optString[STR_LEN] = { 0, };

	si.cb = sizeof(si);
	TCHAR command[] = _T("notepad.exe");
	SetCurrentDirectory(_T("C:\\WINDOWS\\system32"));


	if (!_tcscmp(cmdTokenList[0], _T("exit")))
	{
		return TRUE;
	}
	else if (!_tcscmp(cmdTokenList[0], _T("start")))
	{
		/* �� ���α׷��� ���������̸��� NewCmd.exe��� �����Ѵ�*/

		if (tokenNum > 1) /* "start echo nacho"��� ���ڿ� ó�� ����*/
		{
			/* start�� ������ ������ ���ڿ� �籸�� */
			/* ��, "echo nacho"�� ����� */
			for (int i = 1; i < tokenNum; i++)
			{
				_stprintf(optString, _T("%s %s"), optString, cmdTokenList[i]);
			}
			_stprintf(cmdstringWithOptions, _T("%s %s"), _T("NewCmd.exe"), optString);
		}
		else /* start�� �Է��ϴ� ��� */
		{
			_stprintf(cmdstringWithOptions, _T("%s"), _T("NewCmd.exe"));
		}
		isRun = CreateProcess(NULL, cmdstringWithOptions, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else if (!_tcscmp(cmdTokenList[0], _T("echo")))
	{
		/* �Էµ� ���ڿ��� �״�� �����ϴ� echo ��ɾ� */
		for (int i = 1; i < tokenNum; i++)
		{
			_stprintf(optString, _T("%s %s"), optString, cmdTokenList[i]);
		}
		_tprintf(_T("echo message: %s \n"), optString);
	}
	else if (!_tcscmp(cmdTokenList[0], _T("notepad")))
	{
		ZeroMemory(&pi, sizeof(pi));
		CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);

	}
	else if (!_tcscmp(cmdTokenList[0], _T("lp")))
	{
		ListProcessInfo();
	}
	else if (!_tcscmp(cmdTokenList[0], _T("kp")))
	{
		KillProcess();
	}
	else
	{
		_tcscpy(cmdstringWithOptions, cmdTokenList[0]);

		//CheckPoint 1: �Էµ� ���ڿ� ó���� ���� for��
		for (int i = 1; i < tokenNum; i++)
		{
			_stprintf(cmdstringWithOptions, _T("%s %s"), cmdstringWithOptions, cmdTokenList[i]);
		}
		isRun = CreateProcess(NULL, cmdstringWithOptions, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		if (isRun == FALSE)
		{
			_tprintf(ERROR_CMD, cmdTokenList[0]);
		}
	}

	return 0;
}

/********************************
�Լ�: TCHAR * StrLower(TCAHR * pStr)
���: ���ڿ� ���� �����ϴ� ��� �빮�ڸ� �ҹ��ڷ� �����Ѵ�.
		����� ���ڿ��� �����͸� ��ȯ�Ѵ�
*********************************/
TCHAR* StrLower(TCHAR* pStr)
{
	TCHAR* ret = pStr;

	while (*pStr)
	{
		if (_istupper(*pStr))
		{
			*pStr = _totlower(*pStr);
		}
		pStr++;
	}
	return ret;
}
/********************************
�Լ�: void ListProcess
���: ���μ����� ����Ʈ�� ��ȯ�Ѵ�	
*********************************/
int ListProcessInfo()
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
		_tprintf(_T("%25s %5d \n"), pe32.szExeFile, pe32.th32ProcessID);
	} while (Process32Next(hProcessSnap, &pe32));
}
/********************************
�Լ�: void KillProcess
���: ���μ����� �����Ѵ�
*********************************/
void KillProcess()
{
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("CreateToolhelp32Snapshot (of Process)") );
		return;
	}

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	
	if (!Process32First(hProcessSnap, &pe32))
	{
		_tprintf(_T("Process32First"));
		return;
	}

	HANDLE hProcess;
	BOOL isKill = FALSE;
	do
	{
		if (_tcscmp(pe32.szExeFile, cmdTokenList[1]) == 0)
		{
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);

			if (hProcess != NULL)
			{
				TerminateProcess(hProcess, -1);
				isKill = TRUE;
			}

			CloseHandle(hProcess);
			break;
		}
	} while (Process32Next(hProcessSnap, &pe32));
	
	CloseHandle(hProcessSnap);

	if (isKill == FALSE)
	{
		_tprintf(_T("Kill Process Fail, Try again! \n"));
	}
}