#include<stdio.h>
#include<conio.h>
void main()
{
	int x[8] = {10,20,30,40,50,60,70,80};
	//Here, x is an array of 8 integers
	printf("x = %d\n", x); //x gives base address
	printf("(x+2)= %d\n", (x + 2)); //gives third element address
	printf("*x = %d\n", *x); //gives value in x[0]
	printf("(*x + 2) = %d\n", (*x + 2)); //gives value in x[0]+2
	printf("*(x+2) = %d", *(x + 2)); //gives the third element
	_getch();
}