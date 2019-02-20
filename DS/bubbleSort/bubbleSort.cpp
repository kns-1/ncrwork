#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int arr[100],n,temp;
	cout << "enter n:";
	cin >> n;
cout<<"enter elements: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - 1 -i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 1;
				temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
			}
		}
		if (flag == 0)
			break;
	}
	cout << "after sort: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	_getch();
}