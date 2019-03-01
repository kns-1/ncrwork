#include<Windows.h>
#include<iostream>
using namespace std;

DWORD WINAPI myFun(LPVOID blah)
{
	cout << "this is my function"<<endl;
	return 0;
}
void main()
{
	//Thread creation
	DWORD threadId = 0;
	HANDLE threadHandle = CreateThread(NULL, 0, myFun, NULL, 0, &threadId);
	if (NULL == threadHandle)
	{
		cout << "CreateThread() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	WaitForSingleObject(threadHandle, INFINITE);
	cout << "Return value of CreateThread() is: " << threadHandle << endl;
	cout << "Current Process ID: " << GetCurrentProcessId() << endl;
	cout << "Current Thread ID: " << GetCurrentThreadId() << endl;
	cout << "Process ID: " << GetProcessId<< endl;
	cout << "Thread ID: " << GetThreadId << endl;
	cout << "Process ID of Thread: " << GetProcessIdOfThread << endl;

	system("pause");
}