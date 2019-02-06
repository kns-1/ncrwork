#include<stdio.h>
#include<conio.h>
void main()
{
	int n, count = 0, max=0, min=0, sum = 0;;
	printf("enter numbers, enter 0 to stop:\n");
	while (1)
	{
		scanf_s("%d", &n);
		if (n <= 0)
			break;
		sum += n;
		if (count == 0)
		{
			min = n;
			max = n;
		}
		count++;
		if (n<min)
			min = n;
		if (n > max)
			max = n;
	}
	printf("Number of positive elements= %d\n", count);
	printf("Maximum= %d\n", max);
	printf("Minimum= %d\n", min);
	printf("Average= %d\n", (sum/count));
	_getch();
}