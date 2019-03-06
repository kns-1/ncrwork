#include<Windows.h>
#include<iostream>
using namespace std;

CRITICAL_SECTION csptr;

DWORD WINAPI myFun(LPVOID blah)
{

	cout << "\nthis is thread 1 function";
	EnterCriticalSection(&csptr);
	for (int i = 0; i < 5; i++)
	{
		cout << "\nThread id: " << GetCurrentThreadId();
		Sleep(1000);
	}
	LeaveCriticalSection(&csptr);
	return 0;
}

void main()
{
	//Thread creation
	HANDLE threadHandle = NULL, threadHandle1 = NULL;
	DWORD threadId1 = 0, threadId = 0;
	InitializeCriticalSection(&csptr);

	threadHandle = CreateThread(NULL, 0, myFun, NULL, 0, &threadId);
	if (NULL == threadHandle)
	{
		cout << "\nCreateThread() 1 failed, Error code is: " << GetLastError();
		system("pause");
		exit(0);
	}

	cout << "\nThread 1 ID = " << threadId;

	threadHandle1 = CreateThread(NULL, 0, myFun, NULL, 0, &threadId1);
	if (NULL == threadHandle1)
	{
		cout << "\nCreateThread() 2 failed, Error code is: " << GetLastError();
		system("pause");
		exit(0);
	}

	cout << "\nThread 2 ID = " << threadId1 << endl;


	WaitForSingleObject(threadHandle, INFINITE);
	WaitForSingleObject(threadHandle1, INFINITE);
	DeleteCriticalSection(&csptr);
	system("pause");
}


