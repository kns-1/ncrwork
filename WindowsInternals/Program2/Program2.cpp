#include<Windows.h>
#include<iostream>
#define MAX_SIZE 100
using namespace std;

void main(int argc, LPWSTR *argv)
{
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInfo;
	//the process info handle must be closed at the end

	ZeroMemory(&startupInfo, sizeof(startupInfo));
	ZeroMemory(&processInfo, sizeof(processInfo));

	cout << "PROCESS - 2:" << endl;
	//CHILD-2
	int returnValueProcess = CreateProcess(TEXT("D:/NAVYA/VISUAL STUDIO-NCR/kns-1/ncrwork/WindowsInternals/inheritFileHandle/Program1.cpp"), NULL, NULL, NULL, TRUE, 0, NULL, NULL, &startupInfo, &processInfo);
	if (0 == returnValueProcess)
	{
		cout << "CreateProcess() failed, Error code is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "CHILD-2 \nReturn value of CreateProcess() is: " << returnValueProcess << endl;
	WaitForSingleObject(processInfo.hProcess, INFINITE); // waits for the first process/application to be closed, only then the next process is executed.

	cout << "Current Process ID: " << GetCurrentProcessId() << endl;

	//write file
	CHAR *myText = "I am writing the content into a file\n\nWelcome to MyFile.\n";
	DWORD numberOfBytesWrite = 0;

	int returnValueWrite = WriteFile(argv[0], myText, MAX_SIZE, &numberOfBytesWrite, NULL);
	if (0 == returnValueWrite)
	{
		cout << "Error code of ReadFile() is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}
	cout << "Return value of WriteFile() is: " << returnValueWrite << endl;
	CloseHandle(argv[2]);


	//opening an existing file to read
	HANDLE fHandler1 = CreateFile(argv[0], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == fHandler1)
	{
		cout << "Error code of 2nd CreateFile() is: " << GetLastError() << endl;
		system("pause");
		exit(0);
	}

	cout << "Return value of 2nd CreateFile() is: " << fHandler1 << endl;


	CHAR *fileBuffer = new CHAR[MAX_SIZE];
	DWORD numberOfBytesRead = 0;

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

	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);
	
	system("pause");
}