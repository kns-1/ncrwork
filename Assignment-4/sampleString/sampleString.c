#include<stdio.h>
#include<conio.h>
void main()
{
	char *color[6] = { "red","green","blue","white","black","yellow" };
	//color is a pointer to array of strings
	printf("(color+2) = %d\n", (color + 2));
	printf("*color = %s\n", *color);
	printf("*(color+2) = %s\n", *(color + 2));
	printf("color[5] = %s\n", color[5]);
	printf("*(color+5) = %s\n", *(color + 5));
	_getch();
}