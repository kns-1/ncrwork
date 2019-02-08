#include<stdio.h>
#include<conio.h>
void main()
{
	float table[2][3] = { {1.1,1.2,1.3},{2.1,2.2,2.3} };
	//the table is a 2-D array of floating point numbers
	printf("(table+1) = %d\n", (table + 1));
	printf("*(table+1) = %d\n", *(table + 1));
	printf("(*(table+1)+1) = %d\n", (*(table + 1) + 1));
	printf("(*(table)+1) = %d\n", (*(table)+1));
	printf("*(*(table+1)+1) = %d\n", *(*(table + 1) + 1));
	printf("*(*(table)+1) = %d\n", *(*(table)+1));
	printf("*(*(table+1)) = %d\n", *(*(table + 1)));
	printf("*(*(table)+1)+1 = %d", *(*(table)+1) + 1);
	_getch();
}