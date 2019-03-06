#include<Windows.h>
#include<iostream>
using namespace std;

DWORD WINAPI myFun(LPVOID blah)
{
	cout << "This is SECONDARY THREAD:" << endl;

	for (int i = 100; i <= 103; i++)
	{
		cout <<"\n"<<i << endl;
		Sleep(1000);
	}
	cout << "Loop completed" << endl;
	return 0;
}
void main()
{
	//Thread creation
	DWORD threadId = 0;
	HANDLE threadHandle = CreateThread(NULL, 0, myFun, NULL, 0, &threadId); //CreateThread(NULL, 0, myFun, &threadId, 0, NULL); 
	if (NULL == threadHandle)
	{
		cout << "CreateThread() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "Current Thread ID: " << GetCurrentThreadId() << endl;
	Sleep(1000);
	//Getting exit code of secondary thread
	DWORD exitCodeValue = NULL;
	int exitCodeReturn = GetExitCodeThread(threadHandle, &exitCodeValue);
	if (0 == exitCodeReturn)
	{
		cout << "GetExitCodeThread() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "Exit Code is: " << exitCodeValue << endl;
	
	int terminateValue = TerminateThread(threadHandle, exitCodeValue);
	if (0 == terminateValue)
	{
		cout << "TerminateThread() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "Thread terminated successfully\nTerminating Code is: " << terminateValue << endl;
	


	cout << "This is PRIMARY THREAD: " << endl;
	for (int i = 11; i <= 13; i++)
	{
		cout << i << endl;
		Sleep(1000);
	}



	system("pause");
}