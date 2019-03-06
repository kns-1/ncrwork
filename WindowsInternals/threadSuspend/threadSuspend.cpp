#include<Windows.h>
#include<iostream>
using namespace std;

DWORD WINAPI myFun(LPVOID blah)
{
	cout << "this is my thread function" << endl;
	int time = 0;
	cout << "enter sleep time for thread: ";
	cin >> time;
	for (int i = 1; i <= 10; i++)
	{
		cout << i << endl;
	Sleep(time);
    }
	cout << "Loop completed" << endl;
	return 0;
}
void main()
{
	//Thread creation
	DWORD threadId = 0;
	HANDLE threadHandle = CreateThread(NULL, 0, myFun, &threadId, CREATE_SUSPENDED, NULL); //CreateThread(NULL, 0, myFun, NULL, 0, &threadId);
	if (NULL == threadHandle)
	{
		cout << "CreateThread() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	Sleep(5000); //sleep for 5 seconds
	
	DWORD threadResume = ResumeThread(threadHandle);

	WaitForSingleObject(threadHandle, INFINITE);
	cout << "Return value of CreateThread() is: " << threadHandle << endl;
	cout << "Current Process ID: " << GetCurrentProcessId() << endl;
	cout << "Current Thread ID: " << GetCurrentThreadId() << endl;
	cout << "Process ID: " << GetProcessId << endl;
	cout << "Thread ID: " << GetThreadId << endl;
	cout << "Process ID of Thread: " << GetProcessIdOfThread << endl;

	system("pause");
}