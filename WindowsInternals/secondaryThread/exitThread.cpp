#include<Windows.h>
#include<iostream>
using namespace std;

DWORD WINAPI myFun(LPVOID blah)
{
	cout << "This is SECONDARY THREAD:" << endl;

	for (int i = 1; i <= 3; i++)
	{
		cout << i << endl;
		Sleep(1000);
	}
	ExitThread(0);
	cout << "Loop completed" << endl;
	return 0;
}
void main()
{
	//Thread creation
	DWORD threadId = 0;
	HANDLE threadHandle = CreateThread(NULL, 0, myFun, &threadId, 0, NULL); //CreateThread(NULL, 0, myFun, NULL, 0, &threadId);
	if (NULL == threadHandle)
	{
		cout << "CreateThread() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	//Getting exit code of secondary thread
	DWORD exitCodeValue = NULL;
	int exitCodeReturn = GetExitCodeThread(threadHandle, &exitCodeValue);
	if (0 == exitCodeReturn)
	{
		cout << "GetExitCodeThread() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}

	WaitForSingleObject(threadHandle, INFINITE);

	
	cout << "Exit Code is: " <<exitCodeValue<< endl;
	

	cout << "This is PRIMARY THREAD: "<<endl;
	for (int i = 11; i <= 13; i++)
	{
		cout << i << endl;
		Sleep(1000);
	}

	

	system("pause");
}