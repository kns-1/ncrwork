#include<Windows.h>
#include<iostream>
using namespace std;

void main(int argc, LPWSTR *argv)
{
	STARTUPINFO startupInfo, startupInfo1;
	PROCESS_INFORMATION processInfo, processInfo1;
	//the process info handle must be closed at the end

	ZeroMemory(&startupInfo, sizeof(startupInfo));
	ZeroMemory(&processInfo, sizeof(processInfo));
	ZeroMemory(&startupInfo1, sizeof(startupInfo1));
	ZeroMemory(&processInfo1, sizeof(processInfo1));
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
	cout << "Process ID is : " << processInfo.dwProcessId<< endl;
	cout << "Process Tread ID is : " << processInfo.dwThreadId << endl;
	
	cout << "Current Process ID: " << GetCurrentProcessId() << endl;
	cout << "Current Thread ID: " << GetCurrentThreadId() << endl;
	cout << "Get Process ID: " << GetProcessId << endl;
	cout << "Get Thread ID: " << GetThreadId << endl;
	cout << "Process ID of Thread: " << GetProcessIdOfThread << endl;

	WaitForSingleObject(processInfo.hProcess, INFINITE); // waits for the first process/application to be closed, only then the next process is executed.
	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);
	

//CHILD-2
	int returnValueProcess1 = CreateProcess(TEXT("D:/Calculator.exe"), argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo1, &processInfo1);
	if (0 == returnValueProcess1)
	{
		cout << "CreateProcess() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "CHILD-2 \nReturn value of CreateProcess() is: " << returnValueProcess1 << endl;

	cout << "Startup Info size is: " << sizeof(startupInfo1) << endl;
	cout << "Process Info is : " << sizeof(processInfo1) << endl;
	cout << "Process ID is : " << processInfo1.dwProcessId << endl;
	cout << "Process Tread ID is : " << processInfo1.dwThreadId << endl;

	cout << "Current Process ID: " << GetCurrentProcessId() << endl;
	cout << "Current Thread ID: " << GetCurrentThreadId() << endl;
	cout << "Get Process ID: " << GetProcessId << endl;
	cout << "Get Thread ID: " << GetThreadId << endl;
	cout << "Process ID of Thread: " << GetProcessIdOfThread << endl;

	WaitForSingleObject(processInfo1.hProcess, INFINITE);
	CloseHandle(processInfo1.hProcess);
	CloseHandle(processInfo1.hThread);
	system("pause");
}