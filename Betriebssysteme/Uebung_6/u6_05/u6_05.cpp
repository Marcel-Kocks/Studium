#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;
int a;
int b;

// Mutex-Handle definieren und Mutex erzeugen
HANDLE mutex = CreateMutex(NULL, FALSE, NULL);

DWORD WINAPI ThreadProc(LPVOID pvoid)
{
	// Übergebenen int-Parameter holen
	int* pid = (int*)pvoid;
	int id = *pid;
	for (int i = 0; i < 1000000; i++) {
		// Mutex setzen
		WaitForSingleObject(mutex, INFINITE);
		a = (int)id;
		b = (int)id;
		// Mutex wieder freigeben
		ReleaseMutex(mutex);
		if (a != b)
		{
			printf("Fehler: a = %d und b = %d \n", a, b);
		}
	}
	return(0);
}
void main()
{
	// Threads erzeugen
	cout << "Thread1 startet..." << endl;
	DWORD dwThreadParam1 = 1;
	HANDLE hThread1 = CreateThread(NULL, 0, ThreadProc, &dwThreadParam1, 0, NULL);
	cout << "Thread2 startet..." << endl;
	DWORD dwThreadParam2 = 2;
	HANDLE hThread2 = CreateThread(NULL, 0, ThreadProc, &dwThreadParam2, 0, NULL);
	// Auf Threads warten
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	// Thread-Handles schließen
	cout << "Thread1 schliesst..." << endl;
	CloseHandle(hThread1);
	cout << "Thread2 schliesst..." << endl;

	CloseHandle(hThread2);

	system("PAUSE");

	// Mutex zerstören
	CloseHandle(mutex);
}