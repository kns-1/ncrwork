#include<stdio.h>
#include<conio.h>
void main()
{
	int bs, gr, da, hra;
	printf("enter basic salary: ");
	scanf_s("%d", &bs);
	if (bs <= 4000)
	{
		da = 50;
		hra = 10;
}
	else if (bs >= 4001 && bs <= 8000)
	{
		da = 60; 
		hra = 20;
	}
	else if (bs >= 8001 && bs <= 12000)
	{
		da = 70;
		hra = 25;
	}
	else
	{
		da = 70;
		hra = 30;
	}
	gr = bs + (bs*da / 100) + (bs*hra / 100);
	printf("Gross Salary = %d", gr);
	_getch();
}