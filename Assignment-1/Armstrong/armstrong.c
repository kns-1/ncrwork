#include<stdio.h>
#include<conio.h>
void main()
{
	int n, k=0, rem=0, sum = 0;
	printf("enter a number: ");
	scanf_s("%d", &n);
	k = n;
	while (k > 0)
	{
		rem = k % 10;
		sum = sum + (rem * rem * rem);
		k = k / 10;
	}
	if (sum == n)
		printf("It is an Armstrong number");
	else
		printf("Is is NOT an Armstrong number");
	_getch();
}