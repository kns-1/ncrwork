#include<Windows.h>
#include<iostream>
using namespace std;
void main(int argc, LPWSTR *argv)
{

	/* for (int i = 0; i< argc; i++)
		cout << argv[i] << " ";  */
	wcout << GetCommandLineW() << endl; //displays output (Unicode)
	LPWSTR *returnValue = CommandLineToArgvW(GetCommandLineW(), &argc);
	if (NULL == returnValue)
	{
		cout <<"CommandLine to ArgW failed, Error code is: "<< GetLastError()<<endl;
		system("pause");
		exit(0);
	}
	wcout<<"argv[1] Address is: "<< returnValue <<endl;
	for (int i = 1; i< argc; i++)
	wcout << "Value is: " << returnValue[i] << endl;

	//print first letter of each argument
	for (int i = 1; i< argc; i++)
		wcout << "Value is: " << *returnValue[i] << endl;

	//getchar();
	system("pause");
}