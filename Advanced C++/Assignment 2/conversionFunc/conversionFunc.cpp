#include<iostream>
using namespace std;

namespace MyNamespace1
{
	class Conversion_Function_Demo
	{
		int coef, pow;
	public:
		Conversion_Function_Demo()
		{
			coef = pow = 0;
		}
		
		int pwr(int coef, int pow);
		operator double()
		{
			return pwr(2, 3);
		}
	};

	int Conversion_Function_Demo::pwr(int coef, int pow)
	{
		int temp = coef;
		for (int i = 1; i < pow; i++)
			temp *= coef;
		return temp;
	}
}



using namespace MyNamespace1;

void main()
{
	Conversion_Function_Demo obj;

	cout << "Result of power(2,3)= " << obj.pwr(2,3)<<"\n";
	double val = 0;
	val = obj + 10.5;
	cout << "After conversion, Result= " << val << "\n";

	system("pause");
}