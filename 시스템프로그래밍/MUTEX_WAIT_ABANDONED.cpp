/*
	MUTEX_WAIT_ABANDONED.cpp
	���α׷� ����: ���ؽ��� ���õ� ��ȯ�� WAIT_ABANDONED�� ���� ����.
*/

#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <tchar.h>

LONG gTotalCount = 0;
HANDLE hMutex;

unsigned int WINAPI IncreaseCountOne(LPVOID lpParam)
{
	WaitForSingleObject(hMutex, INFINITE);
	gTotalCount++;

	return 0;
}

unsigned int WINAPI IncreaseCountTwo(LPVOID lpParam)
{
	DWORD dwWaitResult = 0;    
	dwWaitResult = WaitForSingleObject(hMutex, INFINITE);
	
	switch (dwWaitResult) 
	{
       case WAIT_OBJECT_0:
		   ReleaseMutex(hMutex);
		   break; 

       case WAIT_ABANDONED: 
		   _tprintf( _T("WAIT_ABANDONED \n") );
		   break; 
    }

	gTotalCount++;

	ReleaseMutex(hMutex);
	return 0;
}

int _tmain(int argc, TCHAR** argv)
{
    
    DWORD dwThreadIDOne;
    DWORD dwThreadIDTwo;
    HANDLE hThreadOne;
    HANDLE hThreadTwo;	

    hMutex = CreateMutex (
		           NULL,     // ����Ʈ ���Ȱ�����.
               FALSE,    // ������ ���� �� �� �ִ� ���·� ����.
               NULL      // numaned mutex
		     );

    if (hMutex == NULL) 
    {
        _tprintf(_T("CreateMutex error: %d\n"), GetLastError());
    }


	// ������ ������.
    hThreadOne = (HANDLE)_beginthreadex (
		NULL, 0, IncreaseCountOne, NULL, 0, (unsigned *)&dwThreadIDOne 
	);
    
	hThreadTwo = (HANDLE)_beginthreadex (
		NULL, 0, IncreaseCountTwo, NULL, CREATE_SUSPENDED, (unsigned *)&dwThreadIDTwo   
	);

	Sleep(1000);
	ResumeThread(hThreadTwo);

	WaitForSingleObject(hThreadTwo, INFINITE);
	_tprintf(_T("total count: %d \n"), gTotalCount);

	CloseHandle(hThreadOne);  
	CloseHandle(hThreadTwo);  
	CloseHandle(hMutex);

	return 0;
}
