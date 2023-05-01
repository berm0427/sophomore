/*
    ListProcessInfo.cpp
    ���α׷� ����: ���� �������� ���μ��� ���� ���.
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h> 
#include <tlhelp32.h> /* ���μ��� ���� ������� �Լ� ���� */

int _tmain(int argc, TCHAR * argv[])
{
	/**** Snapshot! �� �״�� ������ ��� �Լ�. ************************
	 **** ���μ��� ���� ������ ��� ���� TH32CS_SNAPPROCESS ���� ���� **/
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0 );
	if( hProcessSnap == INVALID_HANDLE_VALUE )
	{
		_tprintf( _T("CreateToolhelp32Snapshot error! \n") );
		return -1;
	}

	/** �� �Լ� CreateToolHelp32Snapshot�� ���� ������ �̹� �����. **
	 ** ������ ������ ���μ��� ������ ���� �����ϴ� ������ �����Ѵ� **/

	PROCESSENTRY32 pe32;   /* ���μ��� ���� ������� ����ü ���� */

	/* PROCESSENTRY32 ������ ����ϱ� ���� ũ�� ���� �ʱ�ȭ �ؾ��Ѵ� */
	pe32.dwSize = sizeof( PROCESSENTRY32 );

	/** ù ��° ���μ��� ���� ���� ���� Process32First �Լ� ��� ***
	 ** �� ���� ���μ��� ���� ���� ���� Process32Next �Լ� ��� ****/
	if( !Process32First( hProcessSnap, &pe32 ) )
	{
		_tprintf( _T("Process32First error! \n") );
		CloseHandle( hProcessSnap );
		return -1;
	}

	HANDLE hProcess;
	do
	{
		/* ���μ��� �̸�, ID ���� ��� */
		_tprintf(_T("%25s %5d \n"), pe32.szExeFile, pe32.th32ProcessID); 

	} while( Process32Next( hProcessSnap, &pe32 ) );

	CloseHandle( hProcessSnap );
	return 0; 
}
