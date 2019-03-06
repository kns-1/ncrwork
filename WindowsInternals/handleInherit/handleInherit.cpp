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
	
	SECURITY_ATTRIBUTES secAtt;
	ZeroMemory(&secAtt, sizeof(secAtt));
	secAtt.bInheritHandle = TRUE;

	//Create event
	HANDLE eventHandler = CreateEvent(&secAtt, FALSE, FALSE, TEXT("FirstEvent"));
	if (NULL == eventHandler)
	{
		cout << "CreateEvent() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "Return value of CreateEvent() is: " << eventHandler << endl;

	//CHILD-1
	int returnValueProcess = CreateProcess(TEXT("D:/WinObj.exe"), NULL, NULL, NULL, TRUE, 0, NULL, NULL, &startupInfo, &processInfo);
	if (0 == returnValueProcess)
	{
		cout << "CreateProcess() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "CHILD-1 \nReturn value of CreateProcess() is: " << returnValueProcess << endl;
	cout << "Current Process ID: " << GetCurrentProcessId() << endl;
	WaitForSingleObject(processInfo.hProcess, INFINITE); // waits for the first process/application to be closed, only then the next process is executed.

	
	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);

	
	system("pause");
}