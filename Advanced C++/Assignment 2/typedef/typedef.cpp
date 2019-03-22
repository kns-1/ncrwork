#include<iostream>
using namespace std;


namespace MyNamespace1
{
	typedef int my_int;
	typedef float my_float;
	typedef double my_double;
	class Func_Ptr_Demo
	{
	public:
		my_float addition(my_int, my_int);
		my_float multiplication(my_int, my_int);
		my_double operation(my_int num1, my_int num2, my_float(Func_Ptr_Demo::* fun_ptr)(my_int, my_int));
	};

	my_float Func_Ptr_Demo::addition(my_int num1, my_int num2)
	{
		return (num1 + num2);
	}

	my_float Func_Ptr_Demo::multiplication(my_int num1, my_int num2)
	{
		return (num1 * num2);
	}

	my_double Func_Ptr_Demo::operation(my_int num1, my_int num2, my_float (Func_Ptr_Demo::*fun_ptr)(my_int, my_int))
	{
		return (this->*fun_ptr)(num1, num2);
	}
}

using namespace MyNamespace1;
void main()
{
	Func_Ptr_Demo obj;
	cout << "Addition: " << obj.operation(2, 3, &Func_Ptr_Demo::addition) << "\n";
	cout << "Multiplication: " << obj.operation(2, 3, &Func_Ptr_Demo::multiplication) << "\n";


	system("pause");
}
