#include<iostream>
#include<windows.h>
using namespace std;
#define MAX 5
#define READERS 2
#define WRITERS 4
#define MAXIMUM(x,y) x>y?x:y

//#include<queue>
//queue <int> myqueue;


int q[MAX], element = 0;
int f = -1, l = -1;
SRWLOCK srwLock;
CONDITION_VARIABLE ConditionVariable;

void insertQ(int ele)
{
	if (f == MAX - 1)
	{
		cout << "queue full" << endl;
		return;
	}

	if (f == -1)
	{
		f = l = 0;
		q[f] = ele;
	}
	else
	{
		q[++f] = ele;
		cout << "\nThe inserted element is " << q[f];
	}
}


void removeQ()
{
	if (f == -1 || l == f + 1)
	{
		cout << "queue empty" << endl;
		return;
	}
	cout << "\nThe removed element is: " << l++;
}


DWORD WINAPI readerFun(LPVOID blah)
{
	/*cout << "\nThis is my function";
	cout << "\nCurrent Thread id: " << GetCurrentThreadId();*/
	AcquireSRWLockShared(&srwLock);
	cout << "\nREADER Thread: " << GetCurrentThreadId();
	InitializeConditionVariable(&ConditionVariable);
	/*int ret = SleepConditionVariableSRW(&ConditionVariable,&srwLock,1000,NULL);
	if (0 == ret)
	{
		cout << "\nSleep Condition Variable failed, Error code is: " << GetLastError();
		Sleep;
	}*/
	removeQ();
	ReleaseSRWLockShared(&srwLock);
	Sleep(1000);

	return 0;
}

DWORD WINAPI writerFun(LPVOID blah)
{
	/*cout << "\nThis is my function";
	cout << "\nCurrent Thread id: " << GetCurrentThreadId();*/
	AcquireSRWLockExclusive(&srwLock);
	cout << "\nWRITER Thread: " << GetCurrentThreadId();
	insertQ(++element);
	ReleaseSRWLockExclusive(&srwLock);
	Sleep(1000);

	return 0;
}

void main()
{
	int r = 0, w = 0;
	//Thread creation
	DWORD readerID[READERS], writerID[WRITERS];
	HANDLE reader[READERS], writer[WRITERS];

	int ret = MAXIMUM(READERS, WRITERS);
	InitializeSRWLock(&srwLock);
	while(ret--)
	{
		if (r < READERS)
		{
			reader[r] = CreateThread(NULL, 0, readerFun, NULL, 0, &readerID[r]);
			r++;
			if (NULL == reader)
			{
				cout << "\nReader Creation failed, Error code is: " << GetLastError();
				system("pause");
				exit(0);
			}
		}
	//	cout << "\nREADER Thread id: " << readerID[i];	
		if (w < WRITERS)
		{
			writer[w] = CreateThread(NULL, 0, writerFun, NULL, 0, &writerID[w]);
			w++;
			if (NULL == reader)
			{
				cout << "\nWriter Creation failed, Error code is: " << GetLastError();
				system("pause");
				exit(0);
			}
		}
		//cout << "\nWRITER Thread id: " << writerID[i];
		Sleep(1000);
	}

	WaitForMultipleObjects(MAXIMUM_WAIT_OBJECTS,reader,TRUE, INFINITE);
	WaitForMultipleObjects(MAXIMUM_WAIT_OBJECTS, writer, TRUE, INFINITE);
	system("pause");
}