#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main() {
	string line;
	string para="";
	ifstream myfile("Text.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
			para += line;
			para += "\n";
		}
		myfile.close();
	}

	else cout << "Unable to open file";
	cout << "My para is: " << para << endl;
	system("pause");
}