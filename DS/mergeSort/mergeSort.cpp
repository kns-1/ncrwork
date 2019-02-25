#include<iostream>
#include<conio.h>
using namespace std;
int *arr=NULL;

void merge(int low, int mid, int high)
{
	int i=low, j=mid+1, k=low, *arr2=NULL;
	arr2 = new int[high - low + 1];
	while(i <= mid && j <= high)
	{
		if (arr[i] <= arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];		
	}
	while (i <= mid)
		arr2[k++] = arr[i++];		
	while (j <= high)
		arr2[k++] = arr[j++];
	for (i = low; i <= high; i++)
		arr[i] = arr2[i];
	delete arr2;
}

void mergesort(int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(low, mid);
		mergesort(mid + 1, high);
		merge(low, mid, high);
	}
	return;
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
	mergesort(0, n - 1);
	cout << "After sort: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	delete arr;
	_getch();
}