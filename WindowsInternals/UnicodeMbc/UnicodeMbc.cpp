#include<Windows.h>
#include<iostream>
using namespace std;
void main()
{
	char cString[] = "normal string"; //MBC = 1 byte for each character
	wchar_t wString[] = L"wide string"; //Unicode(UTF-16) = 2 bytes for each character

	char cChar = 'A';
	wchar_t wChar = 'A'; //no need of L for single character

	//user defined datatypes in "Windows.h" using "typedef"
	CHAR cString1[] = "ansi string";
	WCHAR wString1[] = TEXT("wide windows string"); // it appends 'L' to the beginning === L"wide windows string"

	//print normal C string
	cout << cChar << endl << cString << endl << cString1 << endl;
	//print wide string
	wcout << wChar << endl << wString << endl << wString1 << endl;
	
	//TCHAR usage == converts into CHAR or WCHAR on its own
	/*
	#include<tchar.h>
	_tprintf(_T("%s"),var);
	_tprintf(_T("%S"),var);
	Format Specifiers: 
	If system default is ANSI, %s = ANSI, %S = Unicode
	If system default is Unicode, %s = Unicode, %S = ANSI
	*/
	TCHAR tString[] = TEXT("t char string");
	wcout << tString << endl;



	/* //printing using format specifiers
	printf("%s\n", cString);
	printf("%S", wString); //%Ls, %lls = prints first character;    %ws, %S = prints whole string    */
	
	//Testing if the text is Unicode or not
	//strlen() = normal string length;  wcslen() = wide string length
	
	BOOL creturn = IsTextUnicode(cString1, strlen(cString1)+1, NULL); // returns "int" typedefined as BOOL
	BOOL wreturn = IsTextUnicode(wString1, wcslen(wString1)+1, NULL);
	//string length also matters while determining whether the string is unicode or not	
	if (0 == creturn)
		cout << "C String is NOT Unicode" << endl;
	else
		cout << "C String is Unicode" << endl;

	if (0 == wreturn)
		cout << "W String is NOT Unicode" << endl;
	else
		cout << "W String is Unicode" << endl;



	//MBC to Wide char(Unicode) conversion
	int returnValue = MultiByteToWideChar(CP_UTF8, 0, cString1, -1, NULL, 0);
	cout << "return value= " << returnValue << endl;
	if (!returnValue)
		cout << "MultiByte to WideChar Conversion failed, Error code is: " << GetLastError()<<endl;
	else
		cout << "Conversion successful"<<endl;
	
		
	WCHAR *ptr=new WCHAR[returnValue];
	MultiByteToWideChar(CP_UTF8, 0, cString1, -1, ptr , returnValue);
	wcout << "MultiByte to WideChar string is: " << ptr<<endl; 
	delete[] ptr;

	returnValue = WideCharToMultiByte(CP_UTF8, 0, wString1, -1, NULL, 0, NULL, NULL);
	cout << "return value= " << returnValue << endl;
	if (!returnValue)
		cout << "WideChar to MultiByte Conversion failed, Error code is: " << GetLastError()<<endl;
	else
		cout << "Conversion successful" << endl;

	//CHAR *ptr = new CHAR[returnValue]; //if char ptr and wchar ptr are same, then "GetLastError" is invoked
	CHAR *cptr = new CHAR[returnValue];
	WideCharToMultiByte(CP_UTF8, 0, wString1, -1, cptr, returnValue, NULL, NULL);
	wcout << "WideChar to MultiByte string is: " << cptr << endl;
	delete[] cptr;

	DWORD blah = 2000; //the given number is an error code
	SetLastError(blah);
	cout << "Error code is: "<< GetLastError() << endl;
	//_getch();
	system("pause"); //waits for a key to be pressed
}
