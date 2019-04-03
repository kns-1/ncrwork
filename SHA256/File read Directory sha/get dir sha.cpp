#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
namespace fs = std::experimental::filesystem;
using namespace std;

void main()
{
	string path = "C:/Users/Navya/Pictures/Photos";//"D:/NAVYA/TEST FOLDER";  //"/path/to/directory";

	for (const auto & entry : fs::recursive_directory_iterator(path))
	{
		cout << entry.path() << endl;
		string line;
		string para = "";
		ifstream myfile(entry.path());
		cout << "The file extension is: " << entry.path().extension() << endl; //gives the extension of the file
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				//cout << line << '\n';
				para += line;
				para += "\n";
			}
			myfile.close();
		}

		else 
			cout << "Unable to open file\n";

		cout << "My para is: " << para << endl;
	}

	system("pause");
}