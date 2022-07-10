/*Name : Eswar Majji
 * Id : em69324
 *
 *
 *6. Set the register T0CON value such a way that bit TMR0ON and PSA bit are set (1), without disturbing the other bits.
      Find out the value of T0PS2, T0PS1, T0PS0 bits in T0CON register if the value of the register is 0xF3
 *
 *
 */

#include <stdio.h>

int main()
{
	//initializing num
	int num;

	//reading num
	printf("Enter Register number : ");
	fflush(stdout);
	scanf("%x", &num);
	//18F458
	int num2 = num;
	//solving 1st requirement
	//setting TMRoON and PSA bits
	num = num | (17 << 3);
	printf("Bits in Register after setting requied bits : ");
	for(int i = 7; i >= 0; i--)
	{
		(num >> i) & 1 ? printf("1 ") :printf("0 ");
	}

	//solving 2nd Requirement
	//value of T0PS2, T0PS1, T0PS0 bits in T0CON register if the value of the register is 0xF3
	if((num2 & 0xFF) == 0xF3)
	{
		num2 = num2 & 0x7;

		printf("\nvalue of T0PS2, T0PS1, T0PS0 bits in T0CON register : ");

		for(int i = 3; i >= 0; i--)
		{
			(num2 >> i) & 1 ? printf("1 ") :printf("0 ");
		}
		printf("\n Decimal  : %d", num2);
	}
	else
	{
		printf("\nvalue of the register is not equal to 0xF3");
	}

	return 0;
}
