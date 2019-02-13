#include<stdio.h>
#include<conio.h>
void main()
{
	int bin,dec=0,rem,base=1,i=0,j;
	int hex[100];
	printf("enter binary number: ");
	scanf_s("%d", &bin);
	if (bin == 0)
	{
		printf("Hex: 0\n");
		printf("Decimal: 0");
		_getch();
		exit(0);
	}
	while (bin > 0)
	{
		rem = bin % 10;
		dec = dec + (base*rem);
		base = base * 2;
		bin = bin / 10;
	}

	printf("decimal: %d\n", dec);
	while (dec > 0)
	{
		hex[i] = dec % 16;
		dec /= 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		printf("%d", hex[j]);
	printf("\n");
	printf("Hex: ");
	
	for (j = i - 1; j >=0; j--)
	{
		if (hex[j] >= 10)
			printf("%c", (char)(hex[j] + 55));
		else
			printf("%d", hex[j]);
	}
	printf("\nBinary: ");
	for (j = i - 1; j >= 0; j--)
	{
		switch (hex[j])
		{
		case 0: printf("0000"); break;
		case 1: printf("0001"); break;
		case 2: printf("0010"); break;
		case 3: printf("0011"); break;
		case 4: printf("0100"); break;
		case 5: printf("0101"); break;
		case 6: printf("0110"); break;
		case 7: printf("0111"); break;
		case 8: printf("1000"); break;
		case 9: printf("1001"); break;
		case 10: printf("1010"); break;
		case 11: printf("1011"); break;
		case 12: printf("1100"); break;
		case 13: printf("1101"); break;
		case 14: printf("1110"); break;
		case 15: printf("1111"); break;
		}
	}
	_getch();
}