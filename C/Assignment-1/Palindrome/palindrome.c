#include<stdio.h>
#include<conio.h>
void main()
{
	int n, rem = 0, k = 0, rev = 0;
	printf("enter a number: ");
	scanf_s("%d", &n);
	k = n;
	while (k > 0)
	{
		rem = k % 10;
		rev = (rev * 10) + rem;
		k = k / 10;
	}
	if (rev == n)
		printf("The number is a Palindrome");
	else
		printf("The number is NOT a Palindrome");
	_getch();
}