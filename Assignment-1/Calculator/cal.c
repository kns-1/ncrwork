#include<stdio.h>
int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);
extern int res;
void main()
{
	int a, b, ch;
	printf("res= %d\n", res);
	res = 100;
	printf("res= %d\n", res);
	while (1)
	{

		printf("enter choice:1.add, 2.sub, 3.mul, 4.div, 5.exit\n ");
		scanf_s("%d", &ch);
		if (ch >= 5)
			break;
		printf("enter a and b : ");
		scanf_s("%d%d", &a, &b);

		switch (ch)
		{
		case 1: printf("%d\n", add(a, b)); break;
		case 2: printf("%d\n", sub(a, b)); break;
		case 3: printf("%d\n", mul(a, b)); break;
		case 4: printf("%d\n", div(a, b)); break;
		default: printf("invalid choice\n");
		}

	}


}