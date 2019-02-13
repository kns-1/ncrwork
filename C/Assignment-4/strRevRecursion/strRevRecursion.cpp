#include<stdio.h>
#include<conio.h>
#include<iostream>
char* stringReverse(char *s)
{
	if (s==NULL)
		return s;
	else
		return stringReverse(s++);
}
void main()
{
	char *s=NULL;
	printf("enter string: ");
	s = (char *)malloc(100 * sizeof(char));
	scanf_s(" %[^\n]s", s, 100);
	printf("Reversed string is: %s", stringReverse(s));
	free(s);
	_getch();
}