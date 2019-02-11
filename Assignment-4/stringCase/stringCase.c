#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
void main()
{
	char ch[100];
	int i;
	printf("enter string: ");
	scanf_s("%[^\n]s", ch, 100);
	for (i = 0; i<strlen(ch); i++)
	{
		if (isupper(ch[i]))
			ch[i] += 32;
		else if (islower(ch[i]))
			ch[i] -= 32;
		else
			continue;
	}
	printf("After convertion: %s", ch);
	_getch();
}