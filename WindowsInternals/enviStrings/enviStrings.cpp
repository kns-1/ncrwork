#include<Windows.h>
#include<iostream>
using namespace std;
void main()
{
	cout << "Environment block Address is: " << GetEnvironmentStrings() << endl;
	TCHAR *oldString = TEXT("%navya%");
	TCHAR *newString = new TCHAR[wcslen(oldString) + 1];

	DWORD envReturnValue = ExpandEnvironmentStrings(oldString, newString, wcslen(oldString) + 1);
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