#include <windows.h> 
#include <tchar.h>
#include <stdio.h> 
#include <strsafe.h>
#include <conio.h>
#include "..\ProgLab\strings.h"

void CreateChildProcess(char filePath[]);

int main(int argc, char *argv[])
{
	printf_s("Starting XmlParser.exe...\n");
	CreateChildProcess("D:\\Desktop\\proglab.xml");
	printf_s("XmlParser completed.\n");

	_getch();
	return 0;
}

void CreateChildProcess(char filePath[])
{
	PROCESS_INFORMATION piProcInfo;
	STARTUPINFO siStartInfo;

	ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
	siStartInfo.cb = sizeof(STARTUPINFO);

	siStartInfo.hStdError = GetStdHandle(STD_OUTPUT_HANDLE);
	siStartInfo.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	siStartInfo.dwFlags |= STARTF_USESTDHANDLES;
 
	char path[1024] = "XmlParser.exe \0";
	//stringConcat(&path, filePath);

	bool success = CreateProcess(
		NULL,
		path,		   // command line 
		NULL,          // process security attributes 
		NULL,          // primary thread security attributes 
		true,          // handles are inherited 
		0,             // creation flags 
		NULL,          // use parent's environment 
		NULL,          // use parent's current directory 
		&siStartInfo,  // STARTUPINFO pointer 
		&piProcInfo    // PROCESS_INFORMATION pointer
	);

	if (!success)
		printf_s("Error: Can't start XmlParser.exe.\n");
	else
	{
		WaitForSingleObject(piProcInfo.hProcess, INFINITE);
	}

	CloseHandle(piProcInfo.hProcess);
	CloseHandle(piProcInfo.hThread);
}