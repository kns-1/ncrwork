#include<iostream>
using namespace std;

namespace MyNamespace
{
	class MutableDemo
	{
		int var1;
		mutable int var2;
	public:
		MutableDemo()
		{
			var1 = var2 = 0;
		}
		void const_function() const;
		void normal_function();
	};

	void MutableDemo::const_function() const
	{
		int local_var=0;
		local_var = local_var + 10;
		//var1 = var1 + 10; //This is not possible as it is a constant member function and it cannot modify any member variables of the class
		var2 = var2 + 20;
		cout << "Inside Constant function\nValue of local variable= " << local_var << "\nValue of mutable class member= " << var2;
	}

	void MutableDemo::normal_function()
	{
		var1 = var1 + 100;
		var2 = var2 + 200;
		cout << "Inside Normal Member function\nValue of class member variable= " << var1 << "\nValue of mutable class member= " << var2;
	}
}

using namespace MyNamespace;

void main()
{
	MutableDemo obj;
	obj.const_function();
	obj.normal_function();
	system("pause");
}