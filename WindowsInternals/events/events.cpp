#include<Windows.h>
#include<iostream>
using namespace std;

void main()
{
	HANDLE eventHandler = CreateEvent(NULL,FALSE,FALSE,TEXT("FirstEvent"));
	if (NULL == eventHandler)
	{
		cout << "CreateEvent() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "Return value of CreateEvent() is: " << eventHandler<<endl;
	
	//CloseHandle(eventHandler); //it closes the event automatically. To see it in WinObj, don't close the handler.
	HANDLE mutexHandler = CreateMutex(NULL, TRUE, TEXT("FirstMutex"));
	if (NULL == mutexHandler)
	{
		cout << "CreateMutex() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
		}
	cout<< "Return value of CreateMutex() is: " << mutexHandler << endl;
	system("pause");
}