#include<stdio.h>
#include<conio.h>

void main()
{
	int s, e, i, j, flag;
	printf("enter start and end numbers: ");
	scanf_s("%d%d", &s, &e);
	printf("Prime numbers are:\n");
	for (i = s; i <= e; i++)
	{
		flag = 0;
		for (j = 2; j <= i / 2; j++)
		{
			if (i%j == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag==0)
		printf("%d\n", i);
	}
	_getch();
}