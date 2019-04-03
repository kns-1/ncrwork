#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>

#include "sha256.h"


namespace fs = std::experimental::filesystem;
using namespace std;
//
//
//int main() {
//#define SQL_RESULT_LEN 240
//#define SQL_RETURN_CODE_LEN 1000
//	//define handles and variables
//	SQLHANDLE sqlConnHandle;
//	SQLHANDLE sqlStmtHandle;
//	SQLHANDLE sqlEnvHandle;
//	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
//	//initializations
//	sqlConnHandle = NULL;
//	sqlStmtHandle = NULL;
//	//allocations
//	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
//		goto COMPLETED;
//	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
//		goto COMPLETED;
//	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
//		goto COMPLETED;
//	//output
//	cout << "Attempting connection to SQL Server...";
//	cout << "\n";
//	//connect to SQL Server  
//	//I am using a trusted connection and port 14808
//	//it does not matter if you are using default or named instance
//	//just make sure you define the server name and the port
//	//You have the option to use a username/password instead of a trusted     connection
//	//but is more secure to use a trusted connection
//	switch (SQLDriverConnectW(sqlConnHandle,
//		NULL,
//		//(SQLWCHAR*)L"Data Source=DESKTOP-LII74GI;Initial Catalog=ncr_db;Integrated Security=True",
//		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=BLAH, 1433;DATABASE=emp;Trusted=true;",
//		SQL_NTS,
//		retconstring,
//		1024,
//		NULL,
//		SQL_DRIVER_NOPROMPT)) {
//	case SQL_SUCCESS:
//		cout << "Successfully connected to SQL Server";
//		cout << "\n";
//		break;
//	case SQL_SUCCESS_WITH_INFO:
//		cout << "Successfully connected to SQL Server";
//		cout << "\n";
//		break;
//	case SQL_INVALID_HANDLE:
//		cout << "Could not connect to SQL Server";
//		cout << "\n";
//		goto COMPLETED;
//	case SQL_ERROR:
//		cout << "Could not connect to SQL Server";
//		cout << "\n";
//		goto COMPLETED;
//	default:
//		break;
//	}
//	//if there is a problem connecting then exit application
//	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
//		goto COMPLETED;
//	//output
//	cout << "\n";
//	cout << "Executing T-SQL query...";
//	cout << "\n";
//	//if there is a problem executing the query then exit application
//	//else display query result
//	if (SQL_SUCCESS != SQLExecDirectW(sqlStmtHandle, (SQLWCHAR*)L"select * from emp_details", SQL_NTS)) {
//		cout << "Error querying SQL Server";
//		cout << "\n";
//		goto COMPLETED;
//	}
//	else {
//		//declare output variable and pointer
//		SQLCHAR sqlVersion[SQL_RESULT_LEN];
//		SQLINTEGER ptrSqlVersion;
//		char name[21];
//		int age;
//		int id;
//		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
//
//			//do {
//			SQLGetData(sqlStmtHandle, 1, SQL_C_ULONG, &id, 0, NULL);
//			SQLGetData(sqlStmtHandle, 2, SQL_C_CHAR, name, 21, NULL);
//			SQLGetData(sqlStmtHandle, 3, SQL_C_ULONG, &age, 0, NULL);
//			cout << id << " " << name << " " << age << endl;
//			//} while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS);
//		}
//	}
//	//close connection and free resources
//COMPLETED:
//	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
//	SQLDisconnect(sqlConnHandle);
//	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
//	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
//	//pause the console window - exit when key is pressed
//	cout << "\nPress any key to exit...";
//	getchar();
//}
void main(int argc, char *argv[])
{
	string path = "D:/NAVYA/TEST FOLDER";  //"/path/to/directory";
	for (const auto & entry : fs::recursive_directory_iterator(path))
	{
		cout << entry.path() << endl;
		string line = "";
		string para1 = "";
		//string para2 = "";
		ifstream myfile(entry.path()); //("Text.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				//cout << line << '\n';
				para1 += line;
				para1 += "\n";
			}
			myfile.close();


			/*line = "";
			ifstream myfile2("Text2.txt");
			if (myfile2.is_open())
			{
			while (getline(myfile2, line))
			{
			cout << line << '\n';
			para2 += line;
			para2 += "\n";
			}
			myfile2.close();
			}
			*/


			cout << "My para is: " << para1 << endl;
			//cout << "My para 2 is: " << para2 << endl;

			//HASH CODE

			/* string input1 = "mango";
			string input2 = "mango";*/
			string output1 = sha256(para1); // sha256(input);
											//string output2 = sha256(para2);

			cout << "sha256() is: " << output1 << endl;

			//cout << "para 2: " << output2 << endl;
		}
		else
			cout << "Unable to open file" << endl;
	}
	system("pause");
}