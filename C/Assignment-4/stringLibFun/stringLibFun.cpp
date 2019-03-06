#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string.h>
#define MAX 100

char* stringReverse(char *str)
{
	int i=0,j=0;
	char *temp = NULL;
	temp = (char *)malloc(MAX * sizeof(char));
	for (i = strlen(str) - 1; i >= 0; i--)
		temp[j++] = str[i];
	temp[j] = '\0';
	return temp;
}
char* stringCopy(char *str, char *temp)
{
	int i=0;
	for (i = 0; i < strlen(temp); i++)
		str[i] = temp[i];
	str[i] = '\0';
	return str;
}
char* stringConcat(char *str, char *temp)
{
	int i=0, j = strlen(str);
	for (i = 0;i<strlen(temp); i++)
		str[j++] = temp[i];
	str[j] = '\0';
	return str;
}
int stringCompare(const char *str, const char *temp)
{
	int i=0, retValue=0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] != temp[i])
			retValue = str[i]-temp[i];
	}
	if (0 == retValue)
		return 1;
	return 0;
}

void main()
{
	char *str=NULL, *temp=NULL;
	int case_n=0,choice=0;
	str = (char *)malloc(MAX * sizeof(char));
	temp = (char *)malloc(MAX * sizeof(char));
	printf("enter string: ");
	scanf_s(" %[^\n]s", str, MAX);
	do
	{
		printf("Enter choice: 1.strrev, 2.strcpy, 3.strcat, 4.strcmp, 5.exit\n");
		scanf_s("%d", &case_n);
		switch (case_n)
		{
		case 1:printf("\nReverse is: %s\n", stringReverse(str));
			break;
		case 2: printf("enter a string to copy: ");
			scanf_s(" %[^\n]s", temp, MAX);
			stringCopy(str, temp);
			printf("\nCopied string is: %s\n", str);
			break;
		case 3: printf("enter a string to concat: ");
			scanf_s(" %[^\n]s", temp, MAX);
			stringConcat(str, temp);
			printf("\nConcatenated string is: %s\n", str);
			break;
		case 4: printf("enter a string to compare: ");
			scanf_s(" %[^\n]s", temp, MAX);
			if (stringCompare(str, temp))
				printf("The strings are similar\n");
			else
				printf("The strings are NOT similar\n");
			break;
		}
		printf( "enter -1 to stop: ");
		scanf_s("%d",&choice);
	} while (choice != -1);
	free(temp);
	free(str);
	_getch();
}