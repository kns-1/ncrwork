#include<stdio.h>
#include<conio.h>
#include<iostream>
void delchar2(char *s1, char *s2)
{
	int i,j,k;
	for (i = 0; i < strlen(s1); i++)
	{
		for (j = 0; j < strlen(s2); j++)
		{
			if (s1[i] == s2[j])
			{
				for (k = i; k < strlen(s1) - 1; k++)
					s1[k] = s1[k + 1];
				s1[k] = '\0';
				break;
			}
		}
	}
	printf("The final string is: %s", s1);
}
void main()
{
	char *s1 = NULL, *s2 = NULL;
	s1 = (char *)malloc(100 * sizeof(char));
	s2 = (char *)malloc(100 * sizeof(char));
	printf("enter string s1: ");
	scanf_s(" %[^\n]s", s1, 100);
	printf("enter string s2: ");
	scanf_s(" %[^\n]s", s2, 100);
	delchar2(s1, s2);
	free(s1);
	free(s2);
	_getch();
}