#include<stdio.h>
#include<conio.h>
void main()
{
	int n, rem, count = 0;
	printf("enter an 8 bit binary number: ");
	scanf_s("%d", &n);
	while (n > 0)
	{
		rem = n % 10;
		if (rem == 1)
			count++;
		n = n / 10;
	}
	printf("Number of 1's is: %d", count);
	_getch();
}