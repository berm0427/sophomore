/*
	namedpipe_server.cpp
	���α׷� ����: �̸� �ִ� ������ ����.
*/
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h> 

#define BUF_SIZE 1024

int CommToClient(HANDLE);

int _tmain(int argc, TCHAR* argv[]) 
{
	LPCWSTR pipeName = _T("\\\\.\\pipe\\simple_pipe"); 

	HANDLE hPipe;
	
	while(1)
	{
  	hPipe = CreateNamedPipe ( 
  		pipeName,							 // ������ �̸�
  		PIPE_ACCESS_DUPLEX,					 // �б�,���� ��� ����
  		PIPE_TYPE_MESSAGE |
  		PIPE_READMODE_MESSAGE | PIPE_WAIT,
  		PIPE_UNLIMITED_INSTANCES,		// �ִ� �ν��Ͻ� ����.
  		BUF_SIZE,				      // ��¹��� ������.
  		BUF_SIZE,				     // �Է¹��� ������ 
  		20000,						// Ŭ���̾�Ʈ Ÿ��-�ƿ�  
  		NULL				       // ����Ʈ ���� �Ӽ�
  		);
  
  	if (hPipe == INVALID_HANDLE_VALUE) 
  	{
  		_tprintf( _T("CreatePipe failed")); 
  		return -1;
  	}
  
  	BOOL isSuccess; 
  	isSuccess = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); 
  
  	if (isSuccess) 
  		CommToClient(hPipe);
  	else 
  		CloseHandle(hPipe); 
	}
	return 1; 
} 

int CommToClient(HANDLE hPipe)
{ 
	TCHAR fileName[MAX_PATH] = _T("ee.txt");
	TCHAR dataBuf[BUF_SIZE];

	BOOL isSuccess;
	DWORD fileNameSize;

	isSuccess = ReadFile ( 
		hPipe,        // ������ �ڵ� 
		fileName,    // read ���� ����.
		MAX_PATH * sizeof(TCHAR), // read ���� ������ 
		&fileNameSize,  // ������ ������ ũ��
		NULL);       

	if (!isSuccess || fileNameSize == 0) 
	{
		_tprintf( _T("Pipe read message error! \n") );
		return -1; 
	}

	FILE * filePtr = _tfopen(fileName, _T("r") );

	if(filePtr == NULL)
	{
		_tprintf( _T("File open fault! \n") );
		return -1; 
	}

	DWORD bytesWritten = 0;
	DWORD bytesRead = 0;

	while( !feof(filePtr) )
	{
		bytesRead = fread(dataBuf, 1, BUF_SIZE, filePtr);

		WriteFile ( 
			hPipe,				// ������ �ڵ�
			dataBuf,			// ������ ������ ����  
			bytesRead,		// ������ ������ ũ�� 
			&bytesWritten,	// ���۵� ������ ũ�� 
			NULL);	

       if (bytesRead != bytesWritten)
		{
		    _tprintf( _T("Pipe write message error! \n") );
		    break; 
		}
	}

	FlushFileBuffers(hPipe); 
	DisconnectNamedPipe(hPipe); 
	CloseHandle(hPipe); 
	return 1;
}
