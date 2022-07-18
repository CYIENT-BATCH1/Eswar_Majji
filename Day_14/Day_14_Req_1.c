/******************************************************************************
 * Name : Eswar Majji
 * id : em69324
 *
 *
 * Acceleration sensor data is captured in a 2-dimension array as “ Sensor_Values[ Timestamp_Value][ Sensor _Data]”.
 * Time stamp interval = 10 ms incremental
 * Number of data samples = 20 (20 time stamp samples, 20 data samples)
 * The Sensor_Data is considered as noise if values is < 0x05 and > 0xF0.
 *
 * Output 1 : Print the time stamp where data is coming as noise.
 * Output 2 : Delete the noise data and write valid sensor values
 * to new 2-dimension array “ Sensor_noNoice_Value[ Timestamp_Value][ Sensor _Data]” and print them – time stamp and values.
 *
 *******************************************************************************/
#include <stdio.h>

int main()
{
	int Sensor_Values[20][2] = {{0,0x00},{10,0x00},{20,0x0F},{30,0xFF},{40,0xFF},{50,0x05},{60,0xAA},{70,0x55},{80,0xFE},{90,0x00},{100,0x00},{110,0x00},{120,0xFF},{130,0xFF},{140,0xFF},{150,0xFF},{160,0x11},{170,0x33},{180,0x99},{190, 0xE9}};; //initailizing 2d array for 20 time stamp samples, 20 data samples
    int Sensor_noNoice_Value[20][2] = {0};
    int x = 0;
	//reading array elements
  /*  printf("Enter Sensor_Values[20][2] : ");
	for(int i = 0; i < 20; i++)
	{
		fflush(stdout);
		scanf("%d", &Sensor_Values[i][0]);
		fflush(stdout);
		scanf("%X", &Sensor_Values[i][1]);
	}*/
/*********************************************************output - 1**********************************************************************/

	//Print the time stamp where data is coming as noise (noise if values is < 0x05 and > 0xF0)
	printf("Noise Time stamps are : ");
	for(int i = 0; i < 20; i++)
	{
		if((Sensor_Values[i][1] < 0x05) ||  (Sensor_Values[i][1] > 0xF0))
		{
			printf("%d ", Sensor_Values[i][0]);
		}
/**********************************************************output - 2********************************************************************/
		else
		{
			//assigning values to new array
			Sensor_noNoice_Value[x][0] = Sensor_Values[i][0];
			Sensor_noNoice_Value[x][1] = Sensor_Values[i][1];
			x++;
		}
	}
	printf("\n");

	//printing no noise array data
	printf("Sensor_noNoice_Value[ Timestamp_Value][ Sensor _Data] : \n");
	for(int i = 0; i < x; i++)
	{
		printf("%d\t\t", Sensor_noNoice_Value[i][0]);
		printf("0x%X", Sensor_noNoice_Value[i][1]);
		printf("\n");
	}
}
