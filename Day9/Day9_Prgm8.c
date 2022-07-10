/*Name : Eswar Majji
 * Id : em69324
 *
 * Write program to set (1) bits CIS, C2OUT, C1OUT in register “CMCON” if bits CHS3, CHS2, CHS1 bits are set to 0x06 in register “ADCON0”
 *
 *
 */
#include <stdio.h>

int main()
{
	//initializing num
	int num, num2;
	int b1, b2;

	//reading num
	printf("Enter ADCON0 Register number : ");
	fflush(stdout);
	scanf("%x", &num);

	//solving 1st requirement
	//Extracting CHS3, CHS2, CHS1 bits are set to 0x06 in register “ADCON0”
	num = ((num | 0x38) >> 3);

	//checking num is equal to 0x06
	if(num == 0x06)
	{
		printf("Enter CMCON Register number : ");
		fflush(stdout);
		scanf("%x", &num2);
		//set (1) bits CIS, C2OUT, C1OUT in register “CMCON”
		b1 = ((1 << 3) | num2) >> 1;
		b2 = ((3 << 6) | num2) >> 6;
		num2 = b1 | b2;
		printf("\nCIS, C2OUT, C1OUT in register “CMCON” bits are : ");
		for(int i = 7; i >= 0; i--)
		{
			(num2 >> i) & 1 ? printf("1 ") :printf("0 ");
		}
	}
	else
	{
		printf("\nExtracted bits from ADCON0 Register is not Equal to 0x06");
	}
}
