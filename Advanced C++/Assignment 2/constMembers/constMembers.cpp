#include<iostream>
using namespace std;

namespace MyNamespace1
{
	class MyClass
	{
		const int numA, numB;
	public:
		
		MyClass(int a, int b): numA(a), numB(b)
		{
		}
		void display()
		{
			cout << "NumA= " << numA << "\nNumB= " << numB << "\n";
		}
	};

	class MyClass_New
	{
		MyClass myClass_obj; 
	public:
		MyClass_New(int a, int b): myClass_obj(a,b)
		{
			cout << "Inside MyClass_New Constructor\n";
			myClass_obj.display();
		}
	};
}

using namespace MyNamespace1;
void main()
{
	MyClass myClass_obj(10,20);

	cout << "Inside main()\n";
	myClass_obj.display();

	MyClass_New myClassNew_obj(100,200);
	
	cout << "Inside main()\n";
	myClass_obj.display();

	system("pause");
}