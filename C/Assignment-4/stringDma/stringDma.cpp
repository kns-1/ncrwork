#include<stdio.h>
#include<conio.h>
#include<iostream>

void main()
{
	char **s = NULL;
	int n,i;
	printf("enter number of strings: ");
	scanf_s("%d", &n);
	s = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
	{
		s[i] = (char *)malloc(100 * sizeof(char));
		scanf_s(" %[^\n]s", s[i]);
	}
	printf("The strings are:\n");
	for (i = 0; i < n; i++)
		printf("%s\n", s[i]);
	free(s);
	_getch();
}