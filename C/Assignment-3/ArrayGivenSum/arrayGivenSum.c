#include<stdio.h>
#include<conio.h>
void main()
{
	int arr[100], sum, mysum, n, i, j, flag=0;
	printf("enter size of array and sum: ");
	scanf_s("%d%d", &n, &sum);
	printf("enter elements: ");
	for (i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	for (i = 0; i < n; i++)
	{
		mysum = 0;
		j = i;
		while (j < n)
		{
			mysum += arr[j];
			if (mysum == sum)
			{
				flag = 1;
				break;
			}
			if (mysum > sum)
				break;

			j++;
		}
		if (flag == 1)
			break;
	}
	if (flag == 1)
		printf("Sum found between indices %d and %d", i, j);
	else
		printf("No subarray found");
	_getch();
}