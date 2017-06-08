// u6_03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <windows.h>

int main(int argc, _TCHAR* argv[])
{
	STARTUPINFO SUInfo;
	PROCESS_INFORMATION PInfo1;
	PROCESS_INFORMATION PInfo2;
	PROCESS_INFORMATION PInfo3;
	PROCESS_INFORMATION PInfo4;
	PROCESS_INFORMATION PInfo5;
	PROCESS_INFORMATION PInfo6;

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
		&PInfo1 // Zeiger auf Process-Informations-Struktur
	);
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
		&PInfo2 // Zeiger auf Process-Informations-Struktur
	);
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
		&PInfo3 // Zeiger auf Process-Informations-Struktur
	);
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
		&PInfo4 // Zeiger auf Process-Informations-Struktur
	);
	CreateProcess(
		_T("u6_01.exe"), // Modulname
		NULL, // Kommando-Zeile
		NULL, // Prozess-Handle nicht vererbbar
		NULL, // Thread-Handle nicht vererbbar
		FALSE, // Handle.Verebung auf FALSE
		HIGH_PRIORITY_CLASS, // Normale Priorität
		NULL, // Eltern-Evironment-Block verwenden
		NULL, // Elternverzeichnis als Startverzeichnis
		&SUInfo, // Zeiger auf Startup-Struktur
		&PInfo5 // Zeiger auf Process-Informations-Struktur
	);
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
		&PInfo6 // Zeiger auf Process-Informations-Struktur
	);

	printf("Alles ok, PID=%d\n", PInfo1.dwProcessId);
	printf("Alles ok, PID=%d\n", PInfo2.dwProcessId);
	printf("Alles ok, PID=%d\n", PInfo3.dwProcessId);
	printf("Alles ok, PID=%d\n", PInfo4.dwProcessId);
	printf("Alles ok, PID=%d\n", PInfo5.dwProcessId);
	printf("Alles ok, PID=%d\n", PInfo6.dwProcessId);
	int a = 5;
	while (a == 5);

	system("PAUSE");
	return 0;
}