#include<stdio.h>
#include<conio.h>
void main()
{
	int n, rem=0, sum=0;
	printf("enter a number: ");
	scanf_s("%d", &n);
	while (n > 0)
	{
		rem = n % 10;
		sum = sum + rem;
		n = n / 10;
	}
	printf("Sum = %d\n", sum);
	_getch();
}