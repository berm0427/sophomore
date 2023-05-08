#define _CRT_SECURE_NO_WARNINGS
/*
	CommandPrmpt_with_SEN.cpp
	프로그램 설명: 기존의 명령 프롬프트에 Start,Echo,Notepad를 추
*/

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#define STR_LEN 256
#define CMD_TOKEN_NUM 10

TCHAR ERROR_CMD[]
= _T("'%s'은(는) 실행할 수 있는 프로그램이 아닙니다. \n");
TCHAR cmdString[STR_LEN];
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");
int CmdProcessing(int);
int cmdReadTokenize(void);
TCHAR* StrLower(TCHAR*);
int _tmain(int argc, TCHAR* argv[])
{
	//한글 입력을 가능하게 하기 위해
	_tsetlocale(LC_ALL, _T("Korean"));
	/* 매개 변수 전잘인자 처리용 (start 명령어 전용)*/
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

		if (tokenNum == 0) /* Enter 입력처리 위한 부분 */
		{
			continue;
		}

		isExit = CmdProcessing(tokenNum);
		if (isExit == TRUE)
		{
			_fputts(_T("명령어 처리를 종료합니다. \n"), stdout);
			break;
		}
	}
	return 0;
}
/********************************
함수: int cmdReadTokenize(void)
기능 및 해석: 
CommandPrmpt_with_notepad.cpp의 CmdProcessing 함수는 사용자의 선택을 입력받는 기능과
선택에 따른 명령어 처리기능을 동시에 가지고 있다. 이에 사용자의 선택을 입력받는 기능을
CmdReadTokenize로 분리함 명령어가 main 함수를 통해 전달되는 경우에는 사용자 입력이 불필요한 경우에 수행됨
*********************************/
int cmdReadTokenize(void)
{
	TCHAR * token;

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
함수: int Cmdprocessing(void)
기능: 명령어를 입력받아서 해당 명령어에 저장되어 있는 기능을 수행한다.
		exit가 입력되면 TRUE를 반환하고 프로그램의 종료로 이어진다
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
		/* 이 프로그램의 실행파일이름이 NewCmd.exe라고 가정한다*/

		if (tokenNum > 1) /* "start echo nacho"라는 문자열 처리 위해*/
		{
			/* start를 제외한 나머지 문자열 재구성 */
			/* 즉, "echo nacho"를 만든다 */
			for (int i = 1; i < tokenNum; i++)
			{
				_stprintf(optString, _T("%s %s"), optString, cmdTokenList[i]);
			}
			_stprintf(cmdstringWithOptions, _T("%s %s"), _T("NewCmd.exe"),optString);
		}
		else /* start만 입력하는 경우 */
		{
			_stprintf(cmdstringWithOptions, _T("%s"), _T("NewCmd.exe"));
		}
		isRun = CreateProcess(NULL, cmdstringWithOptions, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else if (!_tcscmp(cmdTokenList[0], _T("echo")))
	{
		/* 입력된 문자열을 그대로 실행하는 echo 명령어 */
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
	else
	{
		_tcscpy(cmdstringWithOptions, cmdTokenList[0]);

		//CheckPoint 1: 입력된 문자열 처리를 위한 for문
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
함수: TCHAR * StrLower(TCAHR * pStr)
기능: 문자열 내에 존재하는 모든 대문자를 소문자로 변경한다.
		변경된 문자열의 포인터를 반환한다
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
