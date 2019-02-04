#include<stdio.h>
#include<conio.h>
void main()
{
	int n, rem=0, sum=0, base=1;
	printf("enter a binary number: ");
	scanf_s("%d", &n);
	while (n > 0)
	{
		rem = n % 10;
		sum = sum + (base*rem);
		base = base * 2;
		n = n / 10;
	}
	printf("Decimal number is: %d\n", sum);
	n = sum;
	sum = 0; base = 1;
	while (n > 0)
	{
		rem = n % 2;
		sum = sum + (base*rem);
		base = base * 10;
		n = n / 2;
	}
	printf("Binary number is: %d\n", sum);
	_getch();
}