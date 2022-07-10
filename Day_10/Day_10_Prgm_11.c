/*Name : Eswar Majji
 * Id : em69324
 *Write a function to store "G_Str_SteeringAngle_sint" to "G_Msg_SteeringInformation_Byte" as shown below.
 *Write signed int G_Str_SteeringAngle_sint = -60;
 *Write unsigned char G_Msg_SteeringInformation_Byte[3u];"

 */


#include <stdio.h>
unsigned char G_Str_SteeringAngle_sint(unsigned char *arr)
{
	int G_Str_SteeringAngle_sint = -60;
	//for message byte 0
	arr[0] = arr[0] |  ((G_Str_SteeringAngle_sint & 768) >> 8);

	//message byte1
	arr[1] = arr[1] |  ((G_Str_SteeringAngle_sint & 964) >> 2);

	//message byte2
	arr[2] = arr[2] |  (G_Str_SteeringAngle_sint & 1);

	return 0;
}//1111 1100 0100
int main()
{
	//declaring and intialising array
	unsigned char G_Msg_SteeringInformation_Byte[3] = {0};

	G_Str_SteeringAngle_sint(G_Msg_SteeringInformation_Byte);

	//printing array
	for(int i = 0; i < 3; i++)
	{
		printf("Message Byte %d		", i);
		for(int j = 7; j >= 0; j--)
		{

			G_Msg_SteeringInformation_Byte[i] & (1 << j) ? printf("1 ") : printf("0 ");
		}
		printf("\n");
	}

}
