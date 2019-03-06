#include<Windows.h>
#include<iostream>
	using namespace std;

	DWORD WINAPI myFun(LPVOID blah)
	{
		cout << "This is SECONDARY THREAD:" << endl;

		for (int i = 100; i <= 103; i++)
		{
			cout << "\n" << i << endl;
			Sleep(1000);
		}
		cout << "Loop completed" << endl;
		return 0;
	}

	void main(int argc, LPWSTR *argv)
	{
		STARTUPINFO startupInfo;
		PROCESS_INFORMATION processInfo;
		//the process info handle must be closed at the end

		ZeroMemory(&startupInfo, sizeof(startupInfo));
		ZeroMemory(&processInfo, sizeof(processInfo));
		
		//CHILD Process
		int returnValueProcess = CreateProcess(TEXT("D:/WinObj.exe"), NULL, NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL, NULL, &startupInfo, &processInfo);
		//sets process priority to hogh(13)
		if (0 == returnValueProcess)
		{
			cout << "CreateProcess() failed, Error code is: " << GetLastError() << endl;
			system("pause");
			exit(0);
		}
		cout << "CHILD Process \nReturn value of CreateProcess() is: " << returnValueProcess << endl;
		cout << "Current Process ID: " << GetCurrentProcessId() << endl;
		Sleep(5000);

		//Setting Priority / changing priority of the child process to normal priority(6)
		int retPriorityProcess = SetPriorityClass(processInfo.hProcess, BELOW_NORMAL_PRIORITY_CLASS);
		if (0 == retPriorityProcess)
		{
			cout << "SetPriority() failed, Error code is: " << GetLastError() << endl;
			system("pause");
			exit(0);
		}
		cout << "CHILD Process priority set\nReturn value of SetPriority() is: " << retPriorityProcess << endl;
		
		Sleep(5000);
		//Thread creation in the child process
		DWORD threadId = 0;
		HANDLE threadHandle = CreateThread(NULL, 0, myFun, &threadId, 0, NULL); 
		if (NULL == threadHandle)
		{
			cout << "CreateThread() failed, Error code is: " << GetLastError() << endl;
			system("pause");
			exit(0);
		}
		cout << "Current Thread ID: " << GetCurrentThreadId() << endl;

		int retPriorityThread = SetThreadPriority(threadHandle, THREAD_PRIORITY_LOWEST);
		if (0 == retPriorityThread)
		{
			cout << "CreateThread() failed, Error code is: " << GetLastError() << endl;
			system("pause");
			exit(0);
		}
		cout << "Thread priority set" << endl;
		Sleep(5000);
		
		WaitForSingleObject(processInfo.hProcess, INFINITE);
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);

	system("pause");
}