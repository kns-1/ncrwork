#include<Windows.h>
#include<iostream>
#define MAX_SIZE 100
using namespace std;
void main()
{
	cout << "Environment block Address is: " << GetEnvironmentStrings() << endl;
	TCHAR *oldString = TEXT("%TEMP%"); //takes the path of the environment variable "TEMP"
	TCHAR *newString = new TCHAR[MAX_SIZE];

	DWORD envReturnValue = ExpandEnvironmentStrings(oldString, newString, MAX_SIZE);//wcslen(oldString) + 1);
	if (!envReturnValue)
	{
		cout << "ExpandEnvironmentStrings() failed, Error code is: "<<GetLastError()<<endl;
		system("pause");
		exit(0);
	}
	cout << "Return value is: " << envReturnValue << endl;
	wcout << "New String is:  " << newString << endl;
	
	delete[] newString;
	//getchar();
	system("pause");
}