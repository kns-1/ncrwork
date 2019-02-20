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
	for (int i = 0; i < n - 1; i++)
	{
		int loc = i, j = i + 1;
		while (j <= n - 1)
		{
			if (arr[j] < arr[loc])
				loc = j;
			j++;
		}
		temp = arr[i]; arr[i] = arr[loc]; arr[loc] = temp;
	}
	cout << "after sort: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	_getch();
}