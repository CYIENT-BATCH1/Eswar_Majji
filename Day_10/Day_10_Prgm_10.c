/*Name : Eswar Majji
 * Id : em69324
 *
 * Write a function to store "G_Eng_EngineTemperature_uchar" and "G_Eng_EngineRpm_uint" into " G_Msg_EngineInformation_Byte[5u]" as shown below.
 * unsigned char G_Eng_EngineTemperature_uchar = 50u ;
 * unsigned int G_Eng_EngineRpm_uint = 1000u;
 * unsigned char G_Msg_EngineInformation_Byte[5u];
 *
 */

#include <stdio.h>

int main()
{
	//combination of different data types in single array not possible
	//so, here for int and char taken different arrays
	unsigned char G_Eng_EngineTemperature_uchar[1] = {50};//1 bye
	unsigned int G_Eng_EngineRpm_uint[1] = {1000};//4 bytes

	//Initializing and declaring an array with 5 elements with 1 byte
	unsigned char output_registers[5] = {0};

	//according to table
	//copy 12 to 9 position bits of RPM element to last 4bits of 1st element (reg 0)

	output_registers[0] = (G_Eng_EngineRpm_uint[0] & (0xF << 9)) >> 9;

	//copy 8 to 1 position  bits of RPM element to entire byte of 2nd element
	output_registers[1] = (G_Eng_EngineRpm_uint[0] & (0xF4 << 1)) >> 1;

	//copy 0 position bit of RPM element to 7 bit position of 3rd element
	output_registers[2] = (G_Eng_EngineRpm_uint[0] & (0x1)) << 7;

	//copy temp array element to 4th element
	output_registers[3] = G_Eng_EngineTemperature_uchar[0];

	//null for last element
	output_registers[4] = 0;


	printf("Message Byte	Bit 7	Bit 6	Bit 5	Bit 4	Bit 3	Bit 2	Bit 1	Bit 0\n\n");
	for(int i = 0; i < 5; i++)
	{
		printf("	%d	", i);
		for (int j = 7; j >= 0; j--)
		{
			(1 << j) & output_registers[i] ? printf("  1     ") : printf("  0     ");
		}
		printf("\n\n");
	}
	return 0;

}
