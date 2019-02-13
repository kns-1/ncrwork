#include<iostream>
#include<conio.h>
using namespace std;
class matMul
{
	int **m1, **m2, **res;
public:
	matMul()
	{
		m1 = m2 = res = NULL;
	}
	friend void multiply(int &r1, int &c1, int &r2);
	void display(int &r2)
	{
		cout << "Resultant matrix is: " << endl;
		for (int i = 0; i < r2; i++)
			cout << res[i][0] << endl;
	}
	~matMul()
	{
		free(m1);
		free(m2);
		free(res);
		cout << "Memory freed";
	}
};
void multiply(int &r1, int &c1, int &r2)
{
	matMul ob;
	ob.m1 = (int **)malloc(r1 * sizeof(int *));
	ob.m2 = (int **)malloc(r2 * sizeof(int *));
	ob.res = (int **)malloc(r2 * sizeof(int *));
	printf("enter matrix m1: ");
	for (int i = 0; i < r1; i++)
	{
		ob.m1[i] = (int *)malloc(c1 * sizeof(int));
		for (int j = 0; j < c1; j++)
			cin >> ob.m1[i][j];
	}
	printf("enter matrix m2: ");
	for (int i = 0; i < r2; i++)
	{
		ob.m2[i] = (int *)malloc(1 * sizeof(int));
			cin >> ob.m2[i][0];
	}

	cout << "m1 is: " << endl;
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
			cout << ob.m1[i][j] << " ";
		cout << endl;
	}
	cout << "m2 is: " << endl;
	for (int i = 0; i < r2; i++)
		cout << ob.m2[i][0] << endl;
	
	for (int i = 0; i < r1; i++)
	{
		int sum = 0;
		ob.res[i] = (int *)malloc(r2 * sizeof(int));
		for (int k = 0; k < r2; k++)
			sum= sum + (ob.m1[i][k] * ob.m2[k][0]);
		ob.res[i][0] = sum;
	}
	ob.display(r2);
}
void main()
{
	int r1, r2, c1;
	cout << "Enter r1, c1: ";
	cin >> r1 >> c1;
	cout << "Enter r2: ";
	cin >> r2;
	multiply(r1, c1, r2);
	_getch();
}