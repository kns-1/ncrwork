#include<stdio.h>
#include<conio.h>
void main()
{
	int arr[100],n,i,ele,j;
	printf("enter size of array: ");
	scanf_s("%d", &n);
	printf("enter elements: ");
	scanf_s("%d", &arr[0]);
	for(i = 1; i < n; i++)
	{
		scanf_s("%d", &ele);
		if (ele >= 0)
			arr[i] = ele;
		else
		{
			for (j = i; j > 0; j--)
			{
				if (arr[j - 1] >= 0)
					arr[j] = arr[j - 1];
				else
					break;
			}
			arr[j] = ele;
		}
	}
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	_getch();
}
