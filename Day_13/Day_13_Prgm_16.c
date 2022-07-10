/*Name : Eswar Majji
 * Id : em69324
 *
 *
 * Requirement 1:
 * Acceleration sensor data is captured in a 2-dimension array as “Sensor_Values[Timestamp_Value][ Sensor_Data]”.
 * Time stamp interval = 10 ms incremental
 * Number of data samples = 20 (20 time stamp samples, 20 data samples)
 * The Sensor_Data is considered as noise if values is < 0x05 and > 0xF0.
 * Output 1 : Print the time stamp where data is coming as noise.
 * Output 2 : Delete the noise data and write valid sensor values to new 2-dimension array “Sensor_noNoice_Vlaue[Timestamp_Value][ Sensor_Data]” and print them – timestamp and values.
 *
 *
 * Requirement 2:
 * Along with the “Requirement 1”, The Sensor_Values are considered as malfunction/corrupted if data is either 0xFF, 0x00 continuously for 3 samples.
 * Output 1 : Print the time stamps where data is coming as malfunction/corrupted.
 * Output 2 : Delete the malfunction/corrupted data samples and write valid sensor values to new 2-dimension array “Sensor_Final_Vlaue[Timestamp_Value][ Sensor_Data]” and print them – timestamp and values.
 *
 *
 */

#include <stdio.h>
//req1
int sense[20][2]={{0,0x00},{10,0x00},{20,0x0F},{30,0xFF},{40,0xFF},{50,0x05},{60,0xAA},{70,0x55},{80,0xFE},{90,0x00},{100,0x00},{110,0x00},{120,0xFF},{130,0xFF},{140,0xFF},{150,0xFF},{160,0x11},{170,0x33},{180,0x99},{190, 0xE9}};
int Sensor_noNoice_Vlaue[20][2];
//re2
int sense2[20][2]={{0,0x01},{10,0x06},{20,0x04},{30,0x00},{40,0x00},{50,0x00},{60,0xAA},{70,0x55},{80,0xFE},{90,0xEF},{100,0xEE},{110,0x02},{120,0x05},{130,0xFF},{140,0xFF},{150,0xFF},{160,0x11},{170,0x33},{180,0x99},{190,0xE9}};
int Sensor_Final_Vlaue[20][10];

//printf table for req1
void prt(int i)
{

        int j = 0;
	    printf(" %d\t\t", sense[i][j]);
	    j = 1;
	    printf("0x%x", sense[i][j]);
	    printf("\n");

}

//assigning non noise values to array
void assign_to_array(int i)
{
    for (int j = 0; j < 2; j++)
    {
        if (j == 0)
        {
            Sensor_noNoice_Vlaue[i][j] = sense[i][j] ;
        }
        else
        {
            Sensor_noNoice_Vlaue[i][j] = sense[i][j];
        }
    }
}

int main()
{
    int i, j, count =0, count2 = 0;
    int flag = 0;
    int flag2 = 0;

    /* for(i = 0; i < 20; i++)
    {
        for (j = 0; j <1; j++)
        {
            scanf("%x", &sense[i][j]);
        }
    }*/

    //Requirement1
    //output1
    //Noise table
    printf("Noise table : \n");
    for(i = 0; i < 20; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (j == 1)
            {
                if ((sense[i][j] < 0x05) || (sense[i][j] > 0xF0))
                {
                    //printing noise values
                    prt(i);
                }
            }
        }
    }
    //output2
    //No Noise table
    printf("Noise less table : \n");
    for(i = 0; i < 20; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (j == 1)
            {
                if ((sense[i][j] >= 0x05) && (sense[i][j] <= 0xF0))
                {
                    assign_to_array(i);
                    prt(i);
                }
            }
        }
    }
   /* //after assigning
    for(int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 2; j++)
		{
		    (j == 0) ? printf(" %d\t\t", Sensor_noNoice_Vlaue[i][j]): printf("0x%x", Sensor_noNoice_Vlaue[i][j]);

		}
		printf("\n");

	}*/

    //Requirement 2:
    //output1
    //malfunction
    printf("time stamps where data is coming as malfunction/corrupted : \n");
    for(int i = 0; i < 20; i++)
    {
        int j = 1;
        if (sense2[i][j] == 0x00)//checking for 0s
        {
            if((++count) == 3 && ((flag + 1) == i))//check 3times or not and prev value is also 0 or not
            {
                for (int j = i; j >= (i - 2); j--)
                {
                    printf("%d ", sense2[j][0]);
                    sense2[j][0] = 0;//making time stamp 0
                    sense2[j][1] = 0;//making value 0

                }
                printf("\n");
            }
        }
        flag = i;
        if (sense2[i][j] == 0xFF)//checking for 0xFFs
        {
            if((++count2) == 3 && ((flag2 + 1) == i))//check 3times or not and prev value is also 0 or not
            {
                for (int j = i; j >= (i - 2); j--)
                {
                    printf("%d ", sense2[j][0]);
                    sense2[j][0] = 0;//making time stamp 0
                    sense2[j][1] = 0;//making value 0
                }
                printf("\n");
            }
        }
        flag2 = i;
    }

    //assigning non zero values to array
    for(int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                if(sense2[i][j] != 0)
                {
                    Sensor_Final_Vlaue[i][j] = sense2[i][j];
                }
            }
            else
            {
                if(sense2[i][j] != 0)
                {
                    Sensor_Final_Vlaue[i][j] = sense2[i][j];
                }
            }
        }
    }
    //after assigning printing array
    printf("after removing malfunction/corrupted data : \n");
    for(int i = 0; i < 20; i++)
	{
	    int j = 0;
	    if((Sensor_Final_Vlaue[i][0] == 0) && (Sensor_Final_Vlaue[i][1] == 0))
	    {
	        continue;
	    }
	    printf(" %d\t\t", Sensor_Final_Vlaue[i][j]);
	    j = 1;
	    printf("0x%x", Sensor_Final_Vlaue[i][j]);
	    printf("\n");
	}
}

