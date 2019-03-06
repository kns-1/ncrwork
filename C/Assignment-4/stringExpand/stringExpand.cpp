#include<stdio.h>
#include<ctype.h>
#include<iostream>
#define MAX 100
void expand(char *s1, char *s2)
{
	int i=0,j=0,k=0;
	if('-' == s1[0])
	{
		printf("Invalid string entry: The string must contains '-' in the beginning\n");
		system("pause");
		exit(0);
	}
	for (i = 0; i < strlen(s1); i++)
	{
		if ('-' != s1[i])	 
		{
			if (!isalpha(s1[i]))
			{
				if (!isdigit(s1[i]))
				{
					printf("Invalid string entry: The string must contain only alphabets, digits or '-'\n");
					system("pause");
					exit(0);
				}
				continue;
			}
			continue;
		}

		if ('-' == s1[i])
		{
			
			if ( (isalpha(s1[i - 1]) && isalpha(s1[i + 1])) || (isdigit(s1[i - 1]) && isdigit(s1[i + 1])) )
			{
				if (s1[i - 1] >= s1[i + 1])
				{
					printf("Invalid string entry: The expansion part of the input string must be in ascending order\n");
					system("pause");
					exit(0);
				}
				continue;
			}
				
			else
			{
				printf("Invalid string entry\n");
				system("pause");
				exit(0);
			}
		}


	}
	for (i = 0; i < strlen(s1); i++)
	{
		if ('-' == s1[i + 1])
		{
			for (k = s1[i]; k < s1[i + 2]; k++)
				s2[j++] = k;
		}
		else
		{
			if ('-' == s1[i])
				continue;
			s2[j++] = s1[i];
		}
		
	}
	s2[j] = '\0';
	printf("The final string is: %s\n", s2);
}
void main()
{
	char *s1 = NULL, *s2 = NULL;
	s1 = (char *)malloc(MAX * sizeof(char));
	s2 = (char *)malloc(MAX * sizeof(char));
	printf("enter string : ");
	scanf_s(" %[^\n]s", s1, MAX);
	expand(s1, s2);
	free(s1);
	free(s2);
	system("pause");
}