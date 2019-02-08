#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;
void main()
{
	char **s=NULL, *temp=NULL;
	int m, i,j;
	printf("enter m: ");
	scanf_s("%d",&m);
	s = (char **)malloc(m * sizeof(char *)); //allocating memory for 2D Array
	
	printf("enter strings: \n");
	for (i = 0; i < m; i++)
	{		
		temp = (char *)malloc(100 * sizeof(char));
		scanf(" %[^\n]s", temp);//space is mandatory
		s[i] = (char *)malloc((strlen(temp)+1) * sizeof(char));
		strcpy(s[i], temp);
	}
	
	for (i = 0; i < m; i++)
	{
		for (j = i+1; j < m; j++)
		{
			if (strcmp(s[i], s[j]) > 0)
			{
				strcpy(temp, s[i]);
				strcpy(s[i], s[j]);
				strcpy(s[j], temp);

			}
		}
	}
	printf("Sorted strings are: ");
	for (i = 0; i < m; i++)
	{
		printf("%s", s[i]);
		printf("\n");
	}
	
	free(s);

	_getch();
}