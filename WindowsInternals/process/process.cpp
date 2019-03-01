#include<Windows.h>
#include<iostream>
using namespace std;

void main(int argc, LPWSTR *argv)
{
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInfo;
	//the process info handle must be closed at the end

	ZeroMemory(&startupInfo, sizeof(startupInfo));
	ZeroMemory(&processInfo, sizeof(processInfo));
//CHILD-1
	int returnValueProcess = CreateProcess(TEXT("D:/WinObj.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL,&startupInfo ,&processInfo);
	if (0 == returnValueProcess)
	{
		cout << "CreateProcess() failed, Error code is: " <<GetLastError()<< endl;
		system("pause");
		exit(0);
	}
	cout << "CHILD-1 \nReturn value of CreateProcess() is: " << returnValueProcess << endl;

	cout << "Startup Info size is: " << sizeof(startupInfo)<< endl;
	cout << "Process Info size is : " << sizeof(processInfo) << endl;
	cout << "Process ID is : " << sizeof(processInfo.dwProcessId) << endl;
	cout << "Process Tread ID is : " << sizeof(processInfo.dwThreadId) << endl;

	WaitForSingleObject(processInfo.hProcess, INFINITE); // waits for the first process/application to be closed, only then the next process is executed.
	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);
	

//CHILD-2
	int returnValueProcess1 = CreateProcess(TEXT("D:/Calculator.exe"), argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInfo);
	if (0 == returnValueProcess1)
	{
		cout << "CreateProcess() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "CHILD-2 \nReturn value of CreateProcess() is: " << returnValueProcess1 << endl;

	cout << "Startup Info size is: " << sizeof(startupInfo) << endl;
	cout << "Process Info is : " << sizeof(processInfo) << endl;
	cout << "Process ID is : " << sizeof(processInfo.dwProcessId) << endl;
	cout << "Process Tread ID is : " << sizeof(processInfo.dwThreadId) << endl;
	WaitForSingleObject(processInfo.hProcess, INFINITE);
	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);
	system("pause");
}