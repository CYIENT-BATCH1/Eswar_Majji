/******************************************************************************
 * Name : Eswar Majji
 * id : em69324
 *
 * There are 2 sensors
 * 1. Acceleration peripheral sensor
 * 2. Acceleration on board sensor
 *
 * Both sensor data is captured in a 2-dimension array as “ Peri_ensor_Values[ Timestamp_Value][ Sensor _Data]” and
 * “ OnBoard_ensor_Values[ Timestamp_Value][ Sensor _Data]”.
 *
 * Time stamp interval = 10 m s incremental
 * Number of data samples = 20 (20 time stamp samples, 20 data samples)
 * The Sensor_Data is considered as noise if values is < 0x05 and > 0xF0.
 * The Sensor_Values are considered as malfunction/corrupted if data is either 0xFF, 0x00 continuously for 3 samples.
 *
 * Output 1 : Print the time stamp where data is coming as noise for both sensors.
 *
 * Output 2 : Delete the noise data and write valid sensor values to new 2-dimension array
 * “ PeriSensor_noNoice_Value[ Timestamp_Value][ Sensor _Data]”, “ OnboardSensor_noNoice_Value[ Timestamp_Value][ Sensor _Data]” and print them – time stamp and values.
 *
 * Output 3 : Delete the malfunction/corrupted data samples and write valid sensor values to new 2-dimension array “ PeriSensor_Final_Value[ Timestamp_Value][ Sensor _Data]”,
 * “ OnboardPeriSensor_Final_Value[ Timestamp_Value][ Sensor _Data]” and print them – time stamp and values.
 *******************************************************************************/
#include <stdio.h>

int main()
{
	int Peri_ensor_Values[20][2] = {{0,0x01},{10,0x06},{20,0x04},{30,0x00},{40,0x00},{50,0x00},{60,0xAA},{70,0x55},{80,0xFE},{90,0xEF},{100,0xEE},{110,0x02},{120,0x05},{130,0xFF},{140,0xFF},{150,0xFF},{160,0x11},{170,0x33},{180,0x99},{190,0xE9}};
    int OnBoard_sensor_Values[20][2] = {{0,0x01},{10,0x06},{20,0x04},{30,0x00},{40,0x00},{50,0x00},{60,0xAA},{70,0x55},{80,0xFE},{90,0xEF},{100,0xEE},{110,0x02},{120,0x05},{130,0xFF},{140,0xFF},{150,0xFF},{160,0x11},{170,0x33},{180,0x99},{190,0xE9}};

	int Peri_ensor_Values1[20][2] = {{0,0x01},{10,0x06},{20,0x04},{30,0x00},{40,0x00},{50,0x00},{60,0xAA},{70,0x55},{80,0xFE},{90,0xEF},{100,0xEE},{110,0x02},{120,0x05},{130,0xFF},{140,0xFF},{150,0xFF},{160,0x11},{170,0x33},{180,0x99},{190,0xE9}};
    int OnBoard_sensor_Values1[20][2] = {{0,0x01},{10,0x06},{20,0x04},{30,0x00},{40,0x00},{50,0x00},{60,0xAA},{70,0x55},{80,0xFE},{90,0xEF},{100,0xEE},{110,0x02},{120,0x05},{130,0xFF},{140,0xFF},{150,0xFF},{160,0x11},{170,0x33},{180,0x99},{190,0xE9}};

	int PeriSensor_noNoice_Value[20][2] = {0};
	int OnboardSensor_noNoice_Value[20][2] = {0};
	int PeriSensor_Final_Value[20][2] = {0};
	int OnboardPeriSensor_Final_Value[20][2] = {0};

    int x = 0, y = 0,count1 = 0, count2 =0, count3 = 0, count4 = 0, flag1 = 0, flag2 =0, z = 0, z1 = 0;
	//reading array elements
  /*  printf("Enter Peri_ensor_Values[20][2] : ");
	for(int i = 0; i < 1; i++)
	{
		fflush(stdout);
		scanf("%d", &Peri_ensor_Values[i][0]);
		Peri_ensor_Values1[i][0] = Peri_ensor_Values[i][0];
		fflush(stdout);
		scanf("%X", &Peri_ensor_Values[i][1]);
		Peri_ensor_Values1[i][1] = Peri_ensor_Values[i][1];
	}
	//reading array2 elements
    printf("Enter Peri_ensor_Values[20][2] : ");
	for(int i = 0; i < 1; i++)
	{
		fflush(stdout);
		scanf("%d", &OnBoard_sensor_Values[i][0]);
		OnBoard_sensor_Values1[i][0] = OnBoard_sensor_Values[i][0];
		fflush(stdout);
		scanf("%X", &OnBoard_sensor_Values[i][1]);
		OnBoard_sensor_Values1[i][1] = OnBoard_sensor_Values[i][1];
	}*/
	//Print the time stamp where data is coming as noise (noise if values is < 0x05 and > 0xF0)
	printf("Peri_ensor_Values Noise Time stamps   are : ");
	for(int i = 0; i < 20; i++)
	{
		if((Peri_ensor_Values[i][1] < 0x05) ||  (Peri_ensor_Values[i][1] > 0xF0))
		{
			printf("%d ", Peri_ensor_Values[i][0]);
		}
		else
		{
			//assigning values to new array
			PeriSensor_noNoice_Value[x][0] = Peri_ensor_Values[i][0];
			PeriSensor_noNoice_Value[x][1] = Peri_ensor_Values[i][1];
			x++;
		}
	}
	printf("\n");

	//Print the time stamp where data is coming as noise (noise if values is < 0x05 and > 0xF0)
	printf("OnBoard_sensor_Values Noise Time stamps   are : ");
	for(int i = 0; i < 20; i++)
	{
		//OnBoard_sensor_Values
		if((OnBoard_sensor_Values[i][1] < 0x05) ||  (OnBoard_sensor_Values[i][1] > 0xF0))
		{
			printf("%d ", OnBoard_sensor_Values[i][0]);
		}
		else
		{
			//assigning values to new array
			OnboardSensor_noNoice_Value[y][0] = OnBoard_sensor_Values[i][0];
			OnboardSensor_noNoice_Value[y][1] = OnBoard_sensor_Values[i][1];
			y++;
		}
	}
	printf("\n");

	//printing no noise array data
	printf("PeriSensor_noNoice_Value[ Timestamp_Value][ Sensor _Data] : \n");
	for(int i = 0; i < x; i++)
	{
		printf("%d\t\t", PeriSensor_noNoice_Value[i][0]);
		printf("0x%X", PeriSensor_noNoice_Value[i][1]);
		printf("\n");
	}
	printf("OnboardSensor_noNoice_Value[ Timestamp_Value][ Sensor _Data] : \n");
	for(int i = 0; i < y; i++)
	{
		printf("%d\t\t", OnboardSensor_noNoice_Value[i][0]);
		printf("0x%X", OnboardSensor_noNoice_Value[i][1]);
		printf("\n");
	}

	//if data is either 0xFF, 0x00 continuously for 3 samples.Peri_ensor_Values1
	printf("Peri_ensor_Values1 : ");
	for(int i = 0; i < 20; i++)
	{
		if(Peri_ensor_Values1[i][1] == 0x00)
		{
			if (++count1 == 3 && ((flag1 + 1) == i))
			{
				printf("0x00 continuously for 3 samples : ");
				for(int j = i; j >= (i - 2); j--)
				{
					printf("%d ", Peri_ensor_Values1[j][0]);//Printing the time stamps where data is coming as malfunction/corrupted.(0x00)
					Peri_ensor_Values1[j][1] = 0;// Delete the malfunction/corrupted data samples
					Peri_ensor_Values1[j][0] = 0;
				}
				printf("\n");
			}
			flag1 = i;
		}
		if(Peri_ensor_Values1[i][1] == 0xFF)
		{
			if (++count2 == 3 && ((flag1 + 1) == i))
			{
				printf("0xFF continuously for 3 samples : ");
				for(int j = i; j >= (i - 2); j--)
				{
					printf("%d ", Peri_ensor_Values1[j][0]);	//Printing the time stamps where data is coming as malfunction/corrupted.(0x00)
					Peri_ensor_Values1[j][1] = 0;			// Delete the malfunction/corrupted data samples
					Peri_ensor_Values1[j][0] = 0;
				}
				printf("\n");
			}
			flag1 = i;
		}
	}

	//if data is either 0xFF, 0x00 continuously for 3 samples.OnBoard_sensor_Values1
	printf("OnBoard_sensor_Values1 : ");
	for(int i = 0; i < 20; i++)
	{
		if(OnBoard_sensor_Values1[i][1] == 0x00)
		{
			if (++count3 == 3 && ((flag2 + 1) == i))
			{
				printf("0x00 continuously for 3 samples : ");
				for(int j = i; j >= (i - 2); j--)
				{
					printf("%d ", OnBoard_sensor_Values1[j][0]);//Printing the time stamps where data is coming as malfunction/corrupted.(0x00)
					OnBoard_sensor_Values1[j][1] = 0;// Delete the malfunction/corrupted data samples
					OnBoard_sensor_Values1[j][0] = 0;
				}
				printf("\n");
			}
			flag2 = i;
		}
		if(OnBoard_sensor_Values1[i][1] == 0xFF)
		{
			if (++count4 == 3 && ((flag2 + 1) == i))
			{
				printf("0xFF continuously for 3 samples : ");
				for(int j = i; j >= (i - 2); j--)
				{
					printf("%d ", OnBoard_sensor_Values1[j][0]);	//Printing the time stamps where data is coming as malfunction/corrupted.(0x00)
					OnBoard_sensor_Values1[j][1] = 0;			// Delete the malfunction/corrupted data samples
					OnBoard_sensor_Values1[j][0] = 0;
				}
				printf("\n");
			}
			flag2 = i;
		}
	}

	//valid sensor values to new 2-dimension array PeriSensor_Final_Value[ Timestamp_Value][ Sensor _Data]
	for(int i = 0; i < 20; i++)
	{
		if((Peri_ensor_Values1[i][1] != 0x00) &&  (Peri_ensor_Values1[i][0] != 0))
		{
			PeriSensor_Final_Value[z][0] = Peri_ensor_Values1[i][0];
			PeriSensor_Final_Value[z][1] = Peri_ensor_Values1[i][1];
			z++;
		}
	}

	//valid sensor values to new 2-dimension array OnBoard_sensor_Values1[ Timestamp_Value][ Sensor _Data]
	for(int i = 0; i < 20; i++)
	{
		if((OnBoard_sensor_Values1[i][1] != 0x00) &&  (OnBoard_sensor_Values1[i][0] != 0))
		{
			OnboardPeriSensor_Final_Value[z1][0] = OnBoard_sensor_Values1[i][0];
			OnboardPeriSensor_Final_Value[z1][1] = OnBoard_sensor_Values1[i][1];
			z1++;
		}
	}

	//printing PeriSensor_Final_Value array
	printf("PeriSensor_Final_Value array : \n");
	for(int i = 0; i < x; i++)
	{
		printf("%d\t\t",PeriSensor_Final_Value[i][0]);
		printf("0x%X",PeriSensor_Final_Value[i][1]);
		printf("\n");
	}

	//printing OnboardPeriSensor_Final_Value array
	printf("OnboardPeriSensor_Final_Value array : \n");
	for(int i = 0; i < x; i++)
	{
		printf("%d\t\t",OnboardPeriSensor_Final_Value[i][0]);
		printf("0x%X",OnboardPeriSensor_Final_Value[i][1]);
		printf("\n");
	}
}
