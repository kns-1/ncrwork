#include<iostream>
using namespace std;


namespace MyNamespace1
{
	class Func_Ptr_Demo
	{
	public:
		int addition(int, int);
		int multiplication(int, int);
		int operation(int, int, int (Func_Ptr_Demo::*)(int, int));
	};

	int Func_Ptr_Demo::addition(int num1, int num2)
	{
		return (num1 + num2);
	}

	int Func_Ptr_Demo::multiplication(int num1, int num2)
	{
		return (num1 * num2);
	}

	int Func_Ptr_Demo::operation(int num1, int num2, int (Func_Ptr_Demo::*fun_ptr)(int,int))
	{
		return (this->*fun_ptr)(num1,num2);
	}
}

using namespace MyNamespace1;
void main()
{
	Func_Ptr_Demo obj;
	cout << "Addition: " << obj.operation(2, 3,&Func_Ptr_Demo::addition) << "\n";
	cout<< "Multiplication: " << obj.operation(2, 3, &Func_Ptr_Demo::multiplication) << "\n";

	
	system("pause");
}
