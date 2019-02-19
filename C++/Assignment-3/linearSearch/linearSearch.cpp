#include<iostream>
#include<conio.h>
using namespace std;

/*template<class C>
class Complex
{
	double real, imag;
public:
	Complex(double r, double i)
	{
		real = r; imag = i;
	}
};
*/

template <class T>
void search(T arr[], T item = NULL)
{
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == item)
		{
			flag = 1;
			cout << endl << item << " found at position " << i << endl;
			break;
		}
	}
	if (flag == 0)
		cout << "element not found" << endl;
}


template<>
void search<char>(char arr[], char item)
{
	cout << "explicit template" << endl;
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == item)
		{
			flag = 1;
			cout << endl << item << " found at position " << i << endl;
			break;
		}
	}
	if (flag == 0)
		cout << "element not found" << endl;
}






void read(int n)
{
	cout << "enter 10 elements: ";
	switch (n)
	{
	case 1: int iarr[10];
		for (int i = 0; i < 10; i++)
		cin >> iarr[i]; 
		search<int>(iarr, 2); 
		break;
	case 2: double farr[10];
		for (int i = 0; i < 10; i++)
			cin >> farr[i]; 
		search<double>(farr, 1.5); 
		break;
	case 3: float carr[10];
		for (int i = 0; i < 10; i++)
			cin >> carr[i]; 
		search<float>(carr, 1.3); 
		break;
	
	case 4: char *arr = new char[10];
		for (int i = 0; i < 10; i++)
			cin >> arr[i];
		search<char>(arr, 'k');
		delete arr;
		break;
//	case 5: 

	//default: cout << "invalid choice" << endl;
	}
}
void main()
{
	int n;
	cout << "enter choice: 1.int, 2.double,3.float, 4.char, 5.complex, 6.exit\n";
	cin >> n;
	read(n);
	_getch();
}