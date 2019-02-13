#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string.h>
void match(char **s1, char **s2, int m, int n)
{
	int i,j,flag=0;
	printf("String-1 indices are: ");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (!strcmp(s1[i], s2[j]))
			{
				flag = 1;
				printf("%d ", i);
				break;
			}
		}
	}
	if (flag == 0)
		printf("NO MATCH");

}
void main()
{
	char **s1=NULL, **s2=NULL;
	int m,n,i;
	printf("enter number of strings in s1 and s2: ");
	scanf_s("%d%d", &m, &n);
	printf("enter first string array: ");
	s1 = (char **)malloc(m * sizeof(char *));
	for (i = 0; i < m; i++)
	{
		s1[i] = (char *)malloc(100 * sizeof(char));
		scanf_s(" %[^\n]s", s1[i]);
	}
	printf("enter second string array: ");
	s2 = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
	{
		s2[i] = (char *)malloc(100 * sizeof(char));
		scanf_s(" %[^\n]s", s2[i]);
	}
	match(s1, s2, m, n);
	free(s1);
	free(s2);
	_getch();
}