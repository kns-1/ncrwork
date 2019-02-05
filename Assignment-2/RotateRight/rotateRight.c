#include<stdio.h>
#include<conio.h>
#include<math.h>
void rotate_right(int,int);
void main()
{
	int n, b;
	printf("enter a number and number of positions: ");
	scanf_s("%d%d", &n, &b);
	rotate_right(n, b);
	_getch();
}
void rotate_right(int n, int b)
{
	int a, len, pos;
	len = 1 + floor(log(n) / log(10));
	pos = b % len;
	a = n % (int)pow(10,pos);
	a = a * pow(10, len - pos);
	n = n / pow(10, pos);
	a = a + n;
	printf("After rotation: %d", a);
}