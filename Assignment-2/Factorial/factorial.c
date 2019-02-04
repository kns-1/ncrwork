#include<stdio.h>
#include<conio.h>
int fact(int);
void main()
{
	int n;
	printf("enter a number: ");
	scanf_s("%d", &n);
	printf("Factorial = %d\n", fact(n));
	_getch();
}
int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n*fact(n - 1);
}