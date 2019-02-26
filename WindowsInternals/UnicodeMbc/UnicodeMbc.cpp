#include<Windows.h>
#include<iostream>
#include<conio.h>
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
//	cout << cChar << endl << cString << endl << cString1 << endl;
	//print wide string
//	wcout << wChar << endl << wString << endl << wString1 << endl;
	

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
/*	int returnValue = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, cString1, strlen(cString1)+1, NULL, 0);
	if (!returnValue)
		cout << "Conversion fail" << endl;
	else
		cout << "Conversion successful"<<endl;
	
	
	
	
	WCHAR *ptr=NULL;
	cout<<"After conversion: "<< MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, cString1, strlen(cString1) + 1, ptr , 0);
	cout << endl << ptr; */

	_getch();
}
