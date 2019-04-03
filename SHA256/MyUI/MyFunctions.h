#pragma once

#include "sha256.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <windows.h>
#include<conio.h>
#include<stdio.h>
#include<map>



#include < stdlib.h >
#include < vcclr.h >



namespace fs = std::experimental::filesystem;
//using namespace std;




using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace Data;
using namespace Data::SqlClient;

ref class MyFunctions
{
public:
	MyFunctions();

	SqlConnection^ sqlcon;
	SqlConnectionStringBuilder^ sqlconStrBuilder;

	void connectToDb()
	{
		//Data Source=BLAH;Initial Catalog=my_hash;Integrated Security=True
		sqlconStrBuilder = gcnew SqlConnectionStringBuilder();
		sqlconStrBuilder->DataSource = "BLAH";
		sqlconStrBuilder->InitialCatalog = "my_hash";
		sqlconStrBuilder->IntegratedSecurity = "True";

		sqlcon = gcnew SqlConnection(Convert::ToString(sqlconStrBuilder));
	}

public:

	void insert_query(std::map<std::string, std::string>hash_search)
	{
		try
		{

			std::map<std::string, std::string>::iterator it;
			connectToDb();
			for (it = hash_search.begin(); it != hash_search.end(); it++)
			{
				std::string res = "insert into hash_details values('" + it->second + "','" + it->first + "', GetDate())";
				String^ my_query = gcnew String(res.c_str());
				SqlCommand^ sqlcmd = gcnew SqlCommand(my_query, sqlcon);

				sqlcon->Open();
				sqlcmd->ExecuteNonQuery();
				delete my_query;
				delete sqlcmd;
			}
		}
		finally
		{
			if (nullptr != sqlcon)
			{
				sqlcon->Close();
				delete sqlcon;
			}
		}
	}




	void myMainFun()
	{
		try
		{
			std::map<std::string, std::string>hash_search;
			std::map<std::string, std::string>::iterator it;

			//FILE
			std::string path = "D:/NAVYA/TEST FOLDER";  //"/path/to/directory";

			for (const auto & entry : fs::recursive_directory_iterator(path))
			{
				//cout <<"hii"<< typeid(entry.path()).name()  << endl;
				//const string file_path = entry.path().string();
				auto file_path = entry.path();

				//cout << "FILE NAME: " << file_path<<endl;

				std::string line = "";
				std::string para1 = "";
				//string para2 = "";

				std::ifstream myfile(entry.path()); //("Text.txt");
				if (myfile.is_open())
				{
					while (getline(myfile, line))
					{
						//cout << line << '\n';
						para1 += line;
						para1 += "\n";
					}
					myfile.close();
					//	cout << "My para is: " << para1 << endl;

					//HASH CODE
					std::string hash_code = sha256(para1); // sha256(input);
					if (hash_search.find(hash_code) != hash_search.end())
					{
						int status = remove(file_path);
					}
					else
					{
						std::string filePath = entry.path().string();
						hash_search.insert(std::pair<std::string, std::string >(hash_code, filePath));
					}

				} //end of file IF
				  //else 
				  //std::cout << "Unable to open file" << std::endl;


			}//for

		//	insert_query(hash_search);
		}catch(Exception^ ex) {}
}

	void insert(String^ name)
	{
		try
		{
			connectToDb();

			String^ my_query = "select * from hash_details"; //"insert into hash_details(file_path, file_hash) values('navya', 'blah')";
			SqlCommand^ sqlcmd = gcnew SqlCommand(my_query, sqlcon);

			sqlcon->Open();
			sqlcmd->ExecuteNonQuery();
			delete sqlcmd;
		}
		finally
		{
			if (nullptr != sqlcon)
			{
				sqlcon->Close();
				delete sqlcon;
			}
		}
	}

	/*void ChooseFolder()
	{
	if (folderBrowserDialog1.ShowDialog() == DialogResult.OK)
	{
	textBox1.Text = folderBrowserDialog1.SelectedPath;
	}
	}*/
};
