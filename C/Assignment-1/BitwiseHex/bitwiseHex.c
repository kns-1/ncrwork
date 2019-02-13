#include<stdio.h>
#include<conio.h>
#include<math.h>
long long int dec2bin(long long int val)
{
	long long int bin = 0, rem, base = 1;
	while (val > 0)
	{
		rem = val % 2;
		bin = bin + (base*rem);
		base = base * 10;
		val = val / 2;
	}
	return bin;
}
void main()
{
	long long int val = 0xCAFE, num = 15, bit_and, bin = 0, rev_byte,temp1,temp2,v;
	printf("Decimal: %lld\n", val);
	
	bin = dec2bin(val);
	printf("Binary: %lld\n",bin);
	bit_and = bin&num;
	bit_and = dec2bin(bit_and);
	printf("%lld\n", bit_and);
	if (bit_and == 1110 || bit_and == 111 || bit_and == 1101 || bit_and == 1011)
		printf("Atleast two of LSBs are ON\n");
	else
		printf("Atleast two of LSBs are NOT ON\n");
	
	//Reversing byte order
	v = dec2bin(val);
	temp1 = v % (int)pow(10,8);
	temp2 = v / (int)pow(10,8);
	rev_byte = temp1 * (int)pow(10, 8) + temp2;
	printf("reversed bytes: %lld\n", rev_byte);
	
	//Rotate four bits;
	v = dec2bin(val);
	temp1 = v % (int)pow(10, 4);
	temp2 = v / (long long int)pow(10, 4);
	printf("temp1: %lld\ntemp2: %lld\n", temp1, temp2);
	rev_byte = temp1 * (long long int)pow(10, 12) + temp2;
	printf("rotated bits: %lld\n", rev_byte);
	_getch();
}