/*Name : Eswar Majji
 * Id : em69324
 *
 *Assume that we have a car with 8 seats, and we are monitoring 8 seat belt status in a variable “G_Msg_switchstatus_Byte[]” as shown in pic1.
 *Assume Each switch status is combination of 2 bits as shown in pic2. Write status of switches into variable “G_Msg_switchstatus_Byte[]” as below.


 SWITCH1, SWITCH7 status is “faulty type 1 in switch”, SWITCH2, SWITCH5 status is ”switch unbuckle”, SWITCH3, SWITCH6 status is “switch buckle”,
 SWITCH4, SWITCH0 status is “faulty type 2 in switch” without disturbing the other bits.
 *
 *
 *
 *
 */
#include <stdio.h>

int main()
{
	int num = 0;
	short option;
	do
	{

		printf("1.faulty type 1 in switch\n2.switch unbuckle\n3.switch buckle\n4.faulty type 2 in switch\n5.stop\nEnter Option : \n");
		fflush(stdout);
		scanf("%hi", &option);
		switch(option)
		{
		//SWITCH1, SWITCH7 status is “faulty type 1 in switch”
		case 1 : num = (num | 0x300003);

				for (int i = 23; i >= 0; i--)
				{

					(1 << i) & num  ? printf("1 ") : printf("0 ");
				    if (i % 8 == 0)
				    {

				        printf("\n");
				    }

				}
				printf("\n");
				num = 0;
				break;
		//SWITCH2, SWITCH5 status is ”switch unbuckle”
		case 2 : num = (num | 0x00C300);

				for (int i = 23; i >= 0; i--)
				{
					(1 << i) & num  ? printf("1 ") : printf("0 ");
					if (i % 8 == 0)
				    {
				        printf("\n");
				    }
				}
				printf("\n");
				num = 0;
				break;
		//SWITCH3, SWITCH6 status is “switch buckle”
		case 3 : num = (num | 0xC03000);

				for (int i = 23; i >= 0; i--)
				{
					(1 << i) & num  ? printf("1 ") : printf("0 ");
					if (i % 8 == 0)
				    {
				        printf("\n");
				    }
				}
				printf("\n");
				num = 0;
				break;
		//	SWITCH4, SWITCH0 status is “faulty type 2
		case 4 : num = (num | 0xC03000);

				for (int i = 23; i >= 0; i--)
				{
					(1 << i) & num  ? printf("1 ") : printf("0 ");
					if (i % 8 == 0)
				    {
				        printf("\n");
				    }
				}
				printf("\n");
				num = 0;
				break;
		}
	}while(option != 5);
}
