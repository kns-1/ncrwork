#include<stdio.h>
#include<conio.h>
#include<iostream>
void stringToken(char *s, char t)
{
	int i;
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] == t)
		{
			printf("\n");
			continue;
		}
		printf("%c", s[i]);
	}
}
void main()
{
	char *s=NULL;
	char t;
	s = (char *)malloc(100 * sizeof(char));
	printf("enter token: ");
	scanf_s("%c", &t);
	printf("enter string with token: ");
	scanf_s(" %[^\n]s", s, 100);
	stringToken(s, t);
	free(s);
	_getch();
}