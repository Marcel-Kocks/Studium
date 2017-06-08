#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
void main()
{
	HANDLE hOut;
	char buf[1024];
	DWORD len;
	DWORD dwWritten;
	LPTSTR lpszPipename = TEXT("\\\\.\\pipe\\mynamedpipe");
	printf_s("pwrite: waiting for the pipe...\n");
	if (WaitNamedPipe(lpszPipename, NMPWAIT_WAIT_FOREVER) == 0)
	{
		printf("WaitNamedPipe failed. error=%d\n", GetLastError());
		return;
	}
	printf("pwrite: the pipe is ready\n");
	hOut = CreateFile(lpszPipename,
		GENERIC_WRITE,
		0,
		NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		printf("CreateFile failed with error %d\n", GetLastError());
		return;
	}
	printf("Opened the pipe\n");
	for (int i = 0; i < 15; i++)
	{
		sprintf_s(buf, "This is test line %d so there.", i);
		len = strlen(buf);
		printf("Sending [%s]\n", buf);
		if (!WriteFile(hOut, buf, len, &dwWritten, NULL))
		{
			printf("WriteFile failed\n");
			break;
		}
		Sleep(1000);
	}
		CloseHandle(hOut);
	printf("pwrite: done\n");
}