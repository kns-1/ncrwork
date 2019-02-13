#include<stdio.h>
#include<conio.h>
#include<iostream>
void stringReverse(char *s)
{
	if (*s)
	{
		stringReverse(s+1);
		printf("%c", *s);
	}
}
void main()
{
	char *s=NULL;
	printf("enter string: ");
	s = (char *)malloc(100 * sizeof(char));
	scanf_s(" %[^\n]s", s, 100);
	printf("Reversed string is: ");
	stringReverse(s);
	free(s);
	_getch();
}