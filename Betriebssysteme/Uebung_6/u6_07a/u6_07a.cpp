#include "stdafx.h"
#include <iostream>
#include <windows.h>
int main(void)
{
	HANDLE hIn;
	DWORD dwBytesRead;
	char buf[100];
	LPTSTR lpszPipename = TEXT("\\\\.\\pipe\\mynamedpipe");
	hIn = CreateNamedPipe(lpszPipename, // Name
		PIPE_ACCESS_DUPLEX | WRITE_DAC, // OpenMode
		PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT, // PipeMode
		2, // MaxInstances
		1024, // OutBufferSize
		1024, // InBuffersize
		2000, // TimeOut
		NULL); // Security
	if (hIn == INVALID_HANDLE_VALUE)
	{
		printf("Could not create the pipe\n");
		exit(1);
	}
	printf("hIn=%p\n", hIn);
	printf("connect...\n");
	ConnectNamedPipe(hIn, NULL);
	printf("...connected\n");
	for (;;)
	{
		if (!ReadFile(hIn, buf, sizeof(buf), &dwBytesRead, NULL))
		{
			printf("ReadFile failed -- probably EOF\n");
			break;
		}
		buf[dwBytesRead] = '\0';
		printf("read [%s]\n", buf);
	}
	DisconnectNamedPipe(hIn);
	CloseHandle(hIn);
}