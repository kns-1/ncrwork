#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

void main()
{
	char text[80];
	int i, letter_count = 0, digit_count = 0, blank_count = 0, tab_count = 0;
	printf("enter elements: ");
	scanf_s("%[^\n]s", text, 80); //80 is the buffer. If not entered, exception is generated
	
	for (i = 0; i< strlen(text) ; i++)
	{
		if (isalpha(text[i]))
			letter_count++;
		else if (isdigit(text[i]))
			digit_count++;
		else if (text[i] == ' ')
			blank_count++;
		else if (text[i] == '\t')
			tab_count++;
		else
			continue;
	}
	printf("Alphabets = %d\nDigits = %d\nBlanks = %d\nTabs = %d", letter_count, digit_count, blank_count, tab_count);
	_getch();
}