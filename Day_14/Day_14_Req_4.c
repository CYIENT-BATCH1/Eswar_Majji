/******************************************************************************
 * Name : Eswar Majji
 * id : em69324
 *
 * (No continuation to Requirement 3)
 * There are 2 sensors
 * 1.       Acceleration peripheral sensor
 * 2.       Acceleration onboard sensor
 * Both sensor data is captured in a 2-dimension array as “Peri_ensor_Values[Timestamp_Value][ Sensor_Data]” and “OnBoard_ensor_Values[Timestamp_Value][ Sensor_Data]”.
 * Time stamp interval = 10 ms incremental
 * Number of data samples = 20 (20 time stamp samples, 20 data samples)
 * The Sensor_Data is considered as noise if values is < 0xA1
 * “Acceleration onboard sensor” is used as plausibility sensor (Means this sensor data is mandatory to take any decision along with the “Acceleration peripheral sensor”).
 * Example: if Onboard sensor data and Peripheral sensor data is valid then only decision is taken to take respective actions. If any sensor data is noise then that data is not considered for any decision.
 * If both “Acceleration onboard sensor” and “Acceleration peripheral sensor” are having valid values at a given time stamp we will allow driver to accelerate the vehicle speed.
 * Where ever valid sensor data is there, store the data into one more array “AfterPlausi_Final_Value[Timestamp_Value][ Sensor_Data]”
 * Output 1: Print the time stamp where both sensor values are valid.
 *******************************************************************************/
#include <stdio.h>

int main()
{
	int Peri_ensor_Values[20][2] = {{0,0x01},{10,0x06},{20,0x04},{30,0x00},{40,0x00},{50,0x00},{60,0xAA},{70,0x55},{80,0xFE},{90,0xEF},{100,0xEE},{110,0x02},{120,0x05},{130,0xFF},{140,0xFF},{150,0xFF},{160,0x11},{170,0x33},{180,0x99},{190,0xE9}};
    int OnBoard_sensor_Values[20][2] = {{0,0x01},{10,0x06},{20,0x04},{30,0x00},{40,0x00},{50,0x00},{60,0xAA},{70,0x55},{80,0xFE},{90,0xEF},{100,0xEE},{110,0x02},{120,0x05},{130,0xFF},{140,0xFF},{150,0xFF},{160,0x11},{170,0x33},{180,0x99},{190,0xE9}};
    int AfterPlausi_Final_Value[20][2];
    int y = 0;
	//reading array elements
/*    printf("Enter Peri_ensor_Values[20][2] : ");
	for(int i = 0; i < 1; i++)
	{
		fflush(stdout);
		scanf("%d", &Peri_ensor_Values[i][0]);

		fflush(stdout);
		scanf("%X", &Peri_ensor_Values[i][1]);

	}
	//reading array elements
    printf("Enter Peri_ensor_Values[20][2] : ");
	for(int i = 0; i < 1; i++)
	{
		fflush(stdout);
		scanf("%d", &OnBoard_sensor_Values[i][0]);

		fflush(stdout);
		scanf("%X", &OnBoard_sensor_Values[i][1]);

	} 	*/
	//assigning values
	for(int i = 0; i < 20; i++)
	{
		//OnBoard_sensor_Values
		if((OnBoard_sensor_Values[i][1] >= 0xA1))
		{
			//assigning values to new array
			AfterPlausi_Final_Value[y][0] = OnBoard_sensor_Values[i][0];
			AfterPlausi_Final_Value[y][1] = OnBoard_sensor_Values[i][1];
			y++;
		}
		if ((Peri_ensor_Values[i][1] >= 0xA1))
		{
			//assigning values to new array
			AfterPlausi_Final_Value[y][0] = Peri_ensor_Values[i][0];
			AfterPlausi_Final_Value[y][1] = Peri_ensor_Values[i][1];
			y++;
		}
	}
	//printing After Plausi_Final_Value array
	printf("After Plausi_Final_Value array : \n");
	for(int i = 0; i < y; i++)
	{
		printf("%d\t\t",AfterPlausi_Final_Value[i][0]);
		printf("0x%X",AfterPlausi_Final_Value[i][1]);
		printf("\n");
	}

	printf("\n");
}
