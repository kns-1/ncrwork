#include<iostream>
#include<conio.h>
using namespace std;
int *arr = NULL;

void quicksort(int low, int high)
{
	
	if (low < high)
	{
		int i = low + 1, j = high;
		while (i<j)
		{
			while (arr[i] < arr[low]) //pivot is arr[low]
				i++;
			while (arr[j] > arr[low])
				j--;
			if (i < j)
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		
				int temp = arr[j];
				arr[j] = arr[low];
				arr[low] = temp;

				quicksort(low, j - 1);
				quicksort(j + 1, high);
			
	}
	
}
void main()
{
	int n;
	cout << "enter size of array: ";
	cin >> n;
	arr = new int[n];
	cout << "enter elements: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Before sort: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	quicksort(0, n - 1);
	cout << "After sort: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	delete arr;
	_getch();
}