#include<Windows.h>
#include<iostream>
using namespace std;
int sharedValue = 0;

DWORD WINAPI myFun1(LPVOID blah)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "ONE: " << sharedValue++ << endl;
		Sleep(1000);
	}
	return 0;
}
DWORD WINAPI myFun2(LPVOID blah)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "TWO: " << sharedValue++ << endl;
		Sleep(1000);
	}
	return 0;
}
void main()
{
	//Thread creation
	DWORD threadId1 = 0;
	HANDLE threadHandle1 = CreateThread(NULL, 0, myFun1, &threadId1, 0, NULL); 
	if (NULL == threadHandle1)
	{
		cout << "CreateThread() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	
	Sleep(1000);
	DWORD threadId2 = 0;
	HANDLE threadHandle2 = CreateThread(NULL, 0, myFun2, &threadId2, 0, NULL); 
	if (NULL == threadHandle2)
	{
		cout << "CreateThread() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "Current Thread ID: " << GetCurrentThreadId() << endl;
	Sleep(1000); /* Here, inconsistency among the thread execution is seen. There is no proper synchronization among the primary thread and the two threads.
	Hence, the final value printed in the primary thread will wary from each execution depending on the execution times and sleep times of each thread. */
	cout << "Final Shared Value is: " << sharedValue << endl;
	

	system("pause");
}