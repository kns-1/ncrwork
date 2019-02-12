#include<stdio.h>
#include<conio.h>
#include<iostream>
void expand(char *s1, char *s2)
{
	int i,j=0,k;
	for (i = 0; i < strlen(s1); i++)
	{
		if (s1[i + 1] == '-')
		{
			for (k = s1[i]; k < s1[i + 2]; k++)
				s2[j++] = k;
		}
		else
		{
			if (s1[i] == '-')
				continue;
			s2[j++] = s1[i];
		}
		
	}
	s2[j] = '\0';
	printf("The final string is: %s", s2);
}
void main()
{
	char *s1 = NULL, *s2 = NULL;
	s1 = (char *)malloc(100 * sizeof(char));
	s2 = (char *)malloc(100 * sizeof(char));
	printf("enter string : ");
	scanf_s(" %[^\n]s", s1, 100);
	expand(s1, s2);
	free(s1);
	free(s2);
	_getch();
}