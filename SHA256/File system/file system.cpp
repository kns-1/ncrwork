#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::experimental::filesystem;

void main()
{
	std::string path = "D:/NAVYA/VISUAL STUDIO-NCR/kns-1/ncrwork/Advanced C++/Assignment 1/release";  //"/path/to/directory";
	for (const auto & entry : fs::recursive_directory_iterator(path))
		std::cout << entry.path() << std::endl;

	system("pause");
}