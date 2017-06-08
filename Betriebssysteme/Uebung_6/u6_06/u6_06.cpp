// Es gibt in der Semaphor 8 freie Plätze, //
// sodass von den 12 Threads 4 warten müssen //
#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;
#define MAX_SEM_COUNT 8
#define THREADCOUNT 12
HANDLE ghSemaphore;
DWORD WINAPI ThreadProc(LPVOID);


int main(void)
{
	HANDLE aThread[THREADCOUNT];
	DWORD ThreadID;
	int i;
	// Create a semaphore with initial and max counts of MAX_SEM_COUNT
	ghSemaphore = CreateSemaphore(
		NULL, // default security attributes
		MAX_SEM_COUNT, // initial count
		MAX_SEM_COUNT, // maximum count
		NULL); // unnamed semaphore
			   // Create worker threads
	for (i = 0; i < THREADCOUNT; i++)
	{
		aThread[i] = CreateThread(
			NULL, // default security attributes
			0, // default stack size
			(LPTHREAD_START_ROUTINE)ThreadProc,
			NULL, // thread function arguments
			0, // default creation flags
			&ThreadID); // receive thread identifier
	}
	// Wait for all threads to terminate
	WaitForMultipleObjects(THREADCOUNT, aThread, TRUE, INFINITE);
	// Close thread and semaphore handles
	printf("Alle Threads fertig \n");
	for (i = 0; i < THREADCOUNT; i++) CloseHandle(aThread[i]);
	CloseHandle(ghSemaphore);

	system("PAUSE");

	return 0;
}


DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	// lpParam not used in this example
	UNREFERENCED_PARAMETER(lpParam);
	DWORD dwWaitResult;
	BOOL bContinue = TRUE;
	while (bContinue)
	{
		// Try to enter the semaphore gate.
		dwWaitResult = WaitForSingleObject(
			ghSemaphore, // handle to semaphore
			0L); // zero-second time-out interval

		switch (dwWaitResult)
		{
			// The semaphore object was signaled.
		case WAIT_OBJECT_0:
			// TODO: Perform task
			printf(" Thread %5d: arbeitet jetzt\n", GetCurrentThreadId());
			bContinue = FALSE;
			// Simulate thread spending time on task
			Sleep(5);
			printf(" Thread %5d: ist fertig mit arbeiten\n", GetCurrentThreadId());
			// Release the semaphore when task is finished
			ReleaseSemaphore(
				ghSemaphore, // handle to semaphore
				1, // increase count by one
				NULL); // not interested in previous count
			break;
			// The semaphore was nonsignaled, so a time-out occurred.
		case WAIT_TIMEOUT:
			printf("Thread %5d: muss warten\n", GetCurrentThreadId());
			break;
		}
	}
	return TRUE;
}