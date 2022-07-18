/******************************************************************************
 * Name : Eswar Majji
 * id : em69324
 *
 * Along with the “Requirement 1”, The Sensor_Values are considered as malfunction/corrupted
 * if data is either 0xFF, 0x00 continuously for 3 samples.
 * Output 1 : Print the time stamps where data is coming as malfunction/corrupted.
 * Output 2 : Delete the malfunction/corrupted data samples and write valid sensor values to new 2-dimension array
 * “ Sensor_Final_Value[ Timestamp_Value][ Sensor _Data]” and print them – time stamp and values.
 *******************************************************************************/
#include <stdio.h>

int main()
{
	int Sensor_Values[20][2] = {{0,0x01},{10,0x06},{20,0x04},{30,0x00},{40,0x00},{50,0x00},{60,0xAA},{70,0x55},{80,0xFE},{90,0xEF},{100,0xEE},{110,0x02},{120,0x05},{130,0xFF},{140,0xFF},{150,0xFF},{160,0x11},{170,0x33},{180,0x99},{190,0xE9}};
	int  Sensor_Final_Value[20][2];
	int flag1 = 0, count1 = 0, count2 = 0, x = 0;
	//reading array elements
	//printf("Enter Sensor_Values[20][2] : ");
	/*for(int i = 0; i < 20; i++)
	{
		fflush(stdout);
		scanf("%d", &Sensor_Values[i][0]);
		fflush(stdout);
		scanf("%X", &Sensor_Values[i][1]);
	}*/

	//if data is either 0xFF, 0x00 continuously for 3 samples.
	for(int i = 0; i < 20; i++)
	{
		if(Sensor_Values[i][1] == 0x00)
		{
			if (++count1 == 3 && ((flag1 + 1) == i))
			{
				printf("0x00 continuously for 3 samples : ");
				for(int j = i; j >= (i - 2); j--)
				{
					printf("%d ", Sensor_Values[j][0]);//Printing the time stamps where data is coming as malfunction/corrupted.(0x00)
					Sensor_Values[j][1] = 0;// Delete the malfunction/corrupted data samples
					Sensor_Values[j][0] = 0;
				}
				printf("\n");
			}
			flag1 = i;
		}
		if(Sensor_Values[i][1] == 0xFF)
		{
			if (++count2 == 3 && ((flag1 + 1) == i))
			{
				printf("0xFF continuously for 3 samples : ");
				for(int j = i; j >= (i - 2); j--)
				{
					printf("%d ", Sensor_Values[j][0]);	//Printing the time stamps where data is coming as malfunction/corrupted.(0x00)
					Sensor_Values[j][1] = 0;			// Delete the malfunction/corrupted data samples
					Sensor_Values[j][0] = 0;
				}
				printf("\n");
			}
			flag1 = i;
		}
	}
	//removing noise to satisfy along with req1 condition
	for(int i = 0; i < 20; i++)
	{
		if((Sensor_Values[i][1] < 0x05) ||  (Sensor_Values[i][1] > 0xF0))
		{
			Sensor_Values[i][0] = 0;
			Sensor_Values[i][1] = 0;
		}
	}
	//valid sensor values to new 2-dimension array Sensor_Final_Value[ Timestamp_Value][ Sensor _Data]
	for(int i = 0; i < 20; i++)
	{
		if((Sensor_Values[i][1] != 0x00) &&  (Sensor_Values[i][0] != 0))
		{
			 Sensor_Final_Value[x][0] = Sensor_Values[i][0];
			 Sensor_Final_Value[x][1] = Sensor_Values[i][1];
			 x++;
		}
	}

	//printing Sensor_Final_Value array
	printf("Sensor_Final_Value array : \n");
	for(int i = 0; i < x; i++)
	{
		printf("%d\t\t",Sensor_Final_Value[i][0]);
		printf("0x%X",Sensor_Final_Value[i][1]);
		printf("\n");
	}

}
