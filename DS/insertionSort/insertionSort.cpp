#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int arr[100], n, temp;
	cout << "enter n:";
	cin >> n;
	cout << "enter elements: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i <= n - 1; i++)
	{
		int j;
		j = i - 1;
		temp=arr[i];
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
	cout << "after sort: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	_getch();
}