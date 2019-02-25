#include<iostream>
#include<conio.h>
using namespace std;
int mid = -1;

int binarySearch(int *arr, int low, int high, int ele)
{
	if (low < high)
	{
		mid = (low + high) / 2;
		if (ele < mid)
			binarySearch(arr, low, mid, ele);
		if (ele > mid)
			binarySearch(arr, mid + 1, high, ele);
	}
		return mid;
}

void main()
{
	int *arr = NULL;
	int n = -1, ele = -1;
	cout << "enter size of array: ";
	cin >> n;
	cout << "enter elements: ";
	arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "enter element to search: ";
	cin >> ele;
	int pos = binarySearch(arr, 0, n, ele);
	if (pos)
		cout << "element found at position " << pos-1;
	else
		cout << "element not found";
		
	delete arr;
	_getch();
}