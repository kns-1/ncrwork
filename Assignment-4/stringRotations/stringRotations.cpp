#include<stdio.h>
#include<conio.h>
#include<iostream>
void main()
{
	char *s = NULL;
	int i,k;
	s = (char *)malloc(100 * sizeof(char));
	printf("enter string: ");
	scanf_s("%s", s, 100);
	printf("String rotations are: \n");
	for (i = 0; i < strlen(s); i++)
	{
		for (k = i; k < strlen(s); k++)
			printf("%c", s[k]);
		for (k = 0; k < i; k++)
			printf("%c", s[k]);
		printf("\n");
	}
	free(s);
	_getch();
}