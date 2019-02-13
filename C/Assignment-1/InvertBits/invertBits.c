#include<stdio.h>
#include<conio.h>
#include<math.h>
void invertponwards(int, int, int);

void main()
{
	int n, p, b;
	printf("enter number, position, bits: ");
	scanf_s("%d%d%d", &n, &p, &b);
	invertponwards(n, p, b);
	_getch();
}

void invertponwards(int n, int p, int b)
{
	int bin = 0, base = 1,len, rem, arr1[100],arr2[100],j,i;
	while (n > 0)
	{
		rem = n % 2;
		bin = bin + (base*rem);
		base = base * 10;
		n = n / 2;
	}
	printf("Binary=%d\n", bin);
	
	len = 1 + floor(log(bin) / log(10));
	for (i = 0; i < len; i++)
	{
		rem = bin % 10;
		arr1[i] = rem;
		bin = bin / 10;
	}
	printf("Before inversion: ");
	for (i = len-1; i >= 0; i--)
		printf("%d", arr1[i]);
	printf("\n");
	for (i = 0, j = len - 1; i < len, j >= 0; i++, j--)
		arr2[i] = arr1[j];
	b = (p + b)-1;

	for (i = p; i <=b; i++)
	{
		if (arr2[i] == 1)
			arr2[i] = 0;
		if(arr2[i]==0)
			arr2[i] = 1;
	}
	printf("After inversion: ");
	for (i = 0; i<len; i++)
		printf("%d", arr2[i]);
}