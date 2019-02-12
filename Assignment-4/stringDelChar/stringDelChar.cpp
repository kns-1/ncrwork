#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
void delchar(char *s, char c)
{
	int i,j;
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] == c)
		{
			for (j = i; j < strlen(s) - 1; j++)
				s[j] = s[j + 1];
			s[j] = '\0';
		}
	}
	printf("The modified string is: %s",s);
}
void main()
{
	char *s = NULL;
	char c;
	printf("enter character to delete: ");
	scanf_s("%c", &c);
	s = (char *)malloc(100 * sizeof(char));
	printf("enter string: ");
	scanf_s(" %[^\n]s", s, 100);
	
	delchar(s, c);
	_getch();
}