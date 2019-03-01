#include<Windows.h>
#include<iostream>
#define MAX_SIZE 100
using namespace std;
void main()
{
	//HANDLE = It's an abstract reference value to a resource, often memory or an open file, or a pipe.
	//creating a new file
	HANDLE fHandler = CreateFile(TEXT("D:/myfile1.txt"), GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == fHandler)
	{
		cout << "Error code of 1st CreateFile() is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}

	cout << "Return value of 1st CreateFile() is: " << fHandler << endl;

	CHAR *myText = "I am writing the content into a file\n\nWelcome to MyFile.\n";
	DWORD numberOfBytesWrite = 0;
	//writing into a file
	int returnValueWrite = WriteFile(fHandler, myText, MAX_SIZE, &numberOfBytesWrite, NULL);
		if (0 == returnValueWrite)
		{
			cout << "Error code of ReadFile() is: " << GetLastError() << endl;
			system("pause");
			exit(0);
		}
	cout << "Return value of WriteFile() is: " << returnValueWrite << endl;
	CloseHandle(fHandler);


	//opening an existing file
	HANDLE fHandler1 = CreateFile(TEXT("D:\\myfile1.txt"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == fHandler1)
	{
		cout << "Error code of 2nd CreateFile() is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	
	cout << "Return value of 2nd CreateFile() is: " << fHandler1<<endl;

	
	CHAR *fileBuffer = new CHAR[MAX_SIZE];
	DWORD numberOfBytesRead=0;

	//ReadFile reads the content of the file in the form of Bytes. Hence take care while printing.
	ZeroMemory(fileBuffer, MAX_SIZE);
	 int returnValueRead = ReadFile(fHandler1, fileBuffer, MAX_SIZE, &numberOfBytesRead, NULL);

	if (0 == returnValueRead)
	{
		cout << "Error code of ReadFile() is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "Return value of ReadFile() is: " << returnValueRead << endl;
	cout << "Number of Bytes read = " << numberOfBytesRead << endl;
	cout << "File content is: " << fileBuffer << endl;

	CloseHandle(fHandler1);
	delete[] fileBuffer;

	int returnValueDel = DeleteFile(TEXT("D:\\myfile1.txt"));
	if (0 == returnValueRead)
	{
		cout << "Error code of ReadFile() is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "The file is successfully deleted" << endl;
	
	system("pause");
}