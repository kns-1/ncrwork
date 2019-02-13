#include<stdio.h>
#include<conio.h>
void main()
{
	const char * s[] = { "we will teach you how to ","Move a mountain ","Level a building ","Erase the past ","Make a million " };
	int i, j, count=0, len;
	len = sizeof(s) / sizeof(char *);
	printf("length = %d\n", len);
	for (i = 0; i<len; i++)
	{
		for (j = 0; s[i][j] != '\0'; j++)
		{
			if (s[i][j] == 'e' || s[i][j]=='E')
				count++;
		}
	}
	printf("Count of e's = %d", count);
	_getch();
}