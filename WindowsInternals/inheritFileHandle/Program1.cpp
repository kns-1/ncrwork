#include<Windows.h>
#include<iostream>
#define MAX_SIZE 100
using namespace std;


void main(int argc, LPWSTR *argv)
{
	//HANDLE = It's an abstract reference value to a resource, often memory or an open file, or a pipe.
	//creating a new file
	HANDLE fHandler = CreateFile(TEXT("D:\\File-1"), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == fHandler)
	{
		cout << "Error code of 1st CreateFile() is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}

	cout << "Return value of 1st CreateFile() is: " << fHandler << endl;

	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInfo;
	//the process info handle must be closed at the end

	ZeroMemory(&startupInfo, sizeof(startupInfo));
	ZeroMemory(&processInfo, sizeof(processInfo));

	cout << "PROCESS - 1:" << endl;
	//CHILD-1
	int returnValueProcess = CreateProcess(argv[2], (LPTSTR)&fHandler, NULL, NULL, TRUE, 0, NULL, NULL, &startupInfo, &processInfo);
	if (0 == returnValueProcess)
	{
		cout << "CreateProcess() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "CHILD-1 \nReturn value of CreateProcess() is: " << returnValueProcess << endl;
	WaitForSingleObject(processInfo.hProcess, INFINITE); // waits for the first process/application to be closed, only then the next process is executed.

	cout << "Current Process ID: " << GetCurrentProcessId() << endl;

	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);

		CloseHandle(fHandler);
		
	system("pause");
}