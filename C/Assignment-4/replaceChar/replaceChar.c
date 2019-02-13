#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
int replace(char *s)
{
	int n=0, i;
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ')
		{
			s[i]='-';
			n++;
		}
	}
	printf("String is: %s\n", s);
	return n;
}
void main()
{
//	char *cat = "The cat sat"; //gives error
	char *cat = NULL, s[100]= "The cat sat";
	int n;
	cat = (char *)malloc(sizeof(char *));
	strcpy(cat,s);
	n = replace(cat);
	printf("Number of replacements = %d", n);
	_getch();
}