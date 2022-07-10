/*Name : Eswar Majji
 * Id : em69324
 *
 *
I). Set the register SSPSTAT value such a way that bit CKE, P and S bit are cleared (0), without disturbing the other bits.

II). Find out the value of UA, BF, SMP bits in SSPSTAT register if the value of the register is 0x55
 *
 *
 */
#include <stdio.h>
int main()
{
	int num, num2;
	char b1, b2, b3;
	char b;
	printf("Enter SSPSTAT Register Value which must be less than 255: ");
	fflush(stdout);
	scanf("%X", &num);
	num2 = num;
	//set CKE, P and S bit

	if(num > 256)
	{
		printf("Unable to proceed Because number is greater than 255 \n");
		return 0;
	}
	num = num | 0x58;
	printf("Register Value After setting bits in Binary Form : ");
	for(int i = 7; i >= 0; i--)
	{
		(1 << i) & num ? printf("1 ") : printf("0 ");
	}
	printf("\nRegister Value After setting bits in Hexa Decimal Form :%X", num);

	//UA, BF, SMP bits in SSPSTAT register

	b1 = ((1 << 1) & num2) << 1;
	b2 = ((1 << 0) & num2) << 1;
	b3 = ((1 << 7) & num2) >> 7;

	b = b1 | b2 | b3;
	printf("\nvalue of UA, BF, SMP bits in SSPSTAT register in Binary Form : ");
	for(int i = 2; i >= 0; i--)
	{
		(1 << i) & b ? printf("1 ") : printf("0 ");
	}
	printf("\nvalue of UA, BF, SMP bits in SSPSTAT register in Hexa Decimal Form :%X", b);

}
