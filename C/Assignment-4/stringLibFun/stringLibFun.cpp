#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string.h>
char* stringReverse(char *s)
{
	int i,j=0;
	char *temp = NULL;
	temp = (char *)malloc(100 * sizeof(char));
	for (i = strlen(s) - 1; i >= 0; i--)
		temp[j++] = s[i];
	temp[j] = '\0';
	return temp;
}
char* stringCopy(char *s, char *temp)
{
	int i;
	for (i = 0; i < strlen(temp); i++)
		s[i] = temp[i];
	s[i] = '\0';
	return s;
}
char* stringConcat(char *s, char *temp)
{
	int i, j = strlen(s);
	for (i = 0;i<strlen(temp); i++)
		s[j++] = temp[i];
	s[j] = '\0';
	return s;
}
int stringCompare(const char *s, const char *temp)
{
	int i;
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] != temp[i])
			return s[i]-temp[i];
	}
	return 0;
}

void main()
{
	char *s=NULL, *temp=NULL;
	int n,ch;
	s = (char *)malloc(100 * sizeof(char));
	temp = (char *)malloc(100 * sizeof(char));
	printf("enter string: ");
	scanf_s(" %[^\n]s", s, 100);
	do
	{
		printf("Enter choice: 1.strrev, 2.strcpy, 3.strcat, 4.strcmp, 5.exit\n");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:printf("\nReverse is: %s", stringReverse(s));
			break;
		case 2: printf("enter a string to copy: ");
			scanf_s(" %[^\n]s", temp, 100);
			stringCopy(s, temp);
			printf("\nCopied string is: %s", s);
			break;
		case 3: printf("enter a string to concat: ");
			scanf_s(" %[^\n]s", temp, 100);
			stringConcat(s, temp);
			printf("\nConcatenated string is: %s", s);
			break;
		case 4: printf("enter a string to compare: ");
			scanf_s(" %[^\n]s", temp, 100);
			printf("\nComparison: %d", stringCompare(s, temp));
			break;
		default: printf("invalid choice");
		}
		printf( "enter -1 to stop: ");
		scanf_s("%d",&ch);
	} while (ch != -1);
	free(temp);
	free(s);
	_getch();
}