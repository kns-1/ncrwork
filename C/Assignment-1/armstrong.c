#include<stdio.h>
int main()
{
	int n,k,rem,sum=0;
	printf("enter a number: ");
	scanf("%d", &n);
	k = n;
	while (k > 0)
	{
		rem = k % 10;
		sum = sum + (rem*rem*rem);
		k = k / 10;
	}
	printf("%d", sum);
	return 0;
}