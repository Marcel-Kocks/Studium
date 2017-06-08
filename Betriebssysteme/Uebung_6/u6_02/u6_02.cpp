// u6_02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <windows.h>

int main(int argc, _TCHAR* argv[])
{
	STARTUPINFO SUInfo;
	PROCESS_INFORMATION PInfo;
	// Start-Up-Info auf 0
	ZeroMemory(&SUInfo, sizeof(SUInfo));
	SUInfo.cb = sizeof(SUInfo);
	printf("Folgender Prozess wurde gestartet: \n ");
	CreateProcess(
		_T("u6_01.exe"), // Modulname
		NULL, // Kommando-Zeile
		NULL, // Prozess-Handle nicht vererbbar
		NULL, // Thread-Handle nicht vererbbar
		FALSE, // Handle.Verebung auf FALSE
		0, // Normale Priorität
		NULL, // Eltern-Evironment-Block verwenden
		NULL, // Elternverzeichnis als Startverzeichnis
		&SUInfo, // Zeiger auf Startup-Struktur
		&PInfo // Zeiger auf Process-Informations-Struktur
	);
	printf("Alles ok, PID=%d\n", PInfo.dwProcessId);
	int a = 5;
	while (a == 5);
	// Close process and thread handles.
	CloseHandle(PInfo.hProcess);
	CloseHandle(PInfo.hThread);
	system("PAUSE");
	return 0;
}