//Coded by Eswar Majji(69324)
//Convert decimal number 204 to hex value, binary value and print the same

#include <stdio.h>
int main()
{
	int num;
	printf("Enter number : ");
	fflush(stdout);
	scanf("%d", &num);
	printf("Hexa Decimal number is %X\n", num);
	for(int i = 31; i >= 0; i--)
	{
		(num >> i)& 1 ? printf("1 ") :printf("0 ");
	}
	return 0;
}
