#include <stdio.h>

#include <stdlib.h>

int assign_data(int ** PR, int ** PC, int ** PL, int ** F_P_Data, int row)
{
  int flag = 1, z = 0;
  //assign PR data from 0 each time index is increasing 15
  for (int i = 0; i <= row; i = i + 5)
  {
    if (flag == 1)//PR data allocation
    {
      if (( * ( * (F_P_Data + i) + 1) < 0x05) || ( * ( * (F_P_Data + i) + 1) > 0xF5))//allocating ony valid
      {
        *( * (F_P_Data + z) + 0) = * ( * (PR + i) + 0);
        *( * (F_P_Data + z) + 1) = * ( * (PR + i) + 1);
        z++;
        flag++;
        continue;
      } 
      else 
      {
        continue;
      }
    }

    if (flag == 2)//PC data
    {
      if (( * ( * (F_P_Data + i) + 1) < 0x05) || ( * ( * (F_P_Data + i) + 1) > 0xF5))//allocating ony valid
      {
        *( * (F_P_Data + z) + 0) = * ( * (PC + i) + 0);
        *( * (F_P_Data + z) + 1) = * ( * (PC + i) + 1);
        z++;
        flag++;
        continue;
      } 
      else 
      {
        continue;
      }
    }
    if (flag == 3)//PL data
    {
      if (( * ( * (F_P_Data + i) + 1) < 0x05) || ( * ( * (F_P_Data + i) + 1) > 0xF5)) //allocating ony valid
      {
      {
        *( * (F_P_Data + z) + 0) = * ( * (PL + i) + 0);
        *( * (F_P_Data + z) + 1) = * ( * (PL + i) + 1);
        z++;
        flag = 1;
      }
      else 
      {
        continue;
      }
    }
    if ((15 - i) < 5)
    {
      break;
    }

  }
    /*
  for(int i = 0; i < 4; i++)
  {
   printf("%d\t\t",F_P_Data[i][0]);
   printf("0X%x\n",F_P_Data[i][1]);
  }*/

  return 0;
}
int main() {
  int row, col = 2;

  printf("Enter no of time stamps : ");
  fflush(stdout);
  scanf("%d", & row);

  int ** F_P_Data = (int ** ) malloc(sizeof(int * ) * row);
  for (int i = 0; i < row; i++)
    F_P_Data[i] = (int * ) malloc(sizeof(int) * col);

  int ** PR = (int ** ) malloc(sizeof(int * ) * row);
  for (int i = 0; i < row; i++) {
    PR[i] = (int * ) malloc(sizeof(int) * col);
  }
  //read the pressure sensor data from user for PR
  printf("Enter the PR data :\n");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < 2; j++) 
    {
      if (j == 0) 
      {
        fflush(stdout);
        //reading time stamp values
        scanf("%d", & PR[i][j]);
      }
      else
      {
        fflush(stdout);
        //reading the data in hexa format
        scanf("%x", & PR[i][j]);
      }
    }

  }
  int ** PC = malloc(sizeof(int * ) * row * col);
  for (int i = 0; i < row; i++)
  {
    PC[i] = (int * ) malloc(sizeof(int) * col);
  }
  //read the pressure sensor data from user for PC
  printf("Enter the PC data :\n");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      if (j == 0)
      {
        fflush(stdout);
        //reading time stamp values
        scanf("%d", & PC[i][j]);
      } 
      else 
      {
        fflush(stdout);
        //reading the data in hexa format
        scanf("%x", & PC[i][j]);
      }
    }

  }
  int ** PL = malloc(sizeof(int * ) * row * col);
  for (int i = 0; i < row; i++)
  {
    PL[i] = (int * ) malloc(sizeof(int) * col);
  }
  //read the pressure sensor data from user for PL
  printf("Enter the PL data :\n");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      if (j == 0)
      {
        fflush(stdout);
        //reading time stamp values
        scanf("%d", & PL[i][j]);
      } 
      else
      {
        fflush(stdout);
        //reading the data in hexa format
        scanf("%x", & PL[i][j]);
      }
    }

  }
  printf("\n");

  //printing the pressure sensor data from user for PR
  printf("Printing  the PR data :\n");
  printf("\nPR time stamp\t\tPR data\n");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      if (j == 0)
      {
        //printing time stamp values
        printf("%d\t\t\t", PR[i][j]);
      }
      else
      {
        //Printing the data in hexa format
        printf("0X%x", PR[i][j]);
      }
    }
    printf("\n");

  }

  //printing the pressure sensor data from user for PC
  printf("Printing  the PC data :\n");
  printf("\nPC time stamp\t\tPC data\n");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      if (j == 0) 
      {
        //printing time stamp values
        printf("%d\t\t\t", PC[i][j]);
      } 
      else 
      {
        //Printing the data in hexa format
        printf("0X%x", PC[i][j]);
      }
    }
    printf("\n");

  }

  //printing the pressure sensor data from user for PL
  printf("Printing  the PL data :\n");
  printf("\nPL time stamp\t\tPL data\n");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      if (j == 0) 
      {
        //printing time stamp values
        printf("%d\t\t\t", PL[i][j]);
      } 
      else
      {
        //Printing the data in hexa format
        printf("0X%x", PL[i][j]);
      }
    }
    printf("\n");

  }

  //removing noise and assigning to new array from PR PC PL
  assign_data(PR, PC, PL, F_P_Data, row);
  for (int i = 0; i < 4; i++) 
  {
    printf("%d\t\t", F_P_Data[i][0]);
    printf("0X%x\n", F_P_Data[i][1]);
  }

}
/*
//Hard coded the inputs
#include <stdio.h>
int row = 15, size = 3;
int PR[25][2] = { { 0, 0x00 }, { 1, 0x00 }, { 2, 0x0F }, { 3, 0xFF },
		{ 4, 0xFF }, { 5, 0x8f }, { 6, 0xAA }, { 7, 0x55 }, { 8, 0xFE }, { 9,
				0x00 }, { 10, 0x00 }, { 11, 0x00 }, { 12, 0xFF }, { 13, 0xFF },
		{ 14, 0xFF }, { 15, 0xFF }, { 16, 0x11 }, { 17, 0x33 }, { 18, 0x99 }, {
				19, 0xE9 } };
int PC[25][2] = { { 0, 0x00 }, { 1, 0x00 }, { 2, 0x0F }, { 3, 0xFF },
		{ 4, 0xFF }, { 5, 0x56 }, { 6, 0xAA }, { 7, 0x55 }, { 8, 0xFE }, { 9,
				0x00 }, { 10, 0x00 }, { 11, 0x00 }, { 12, 0xFF }, { 13, 0xFF },
		{ 14, 0xFF }, { 15, 0x7f }, { 16, 0x11 }, { 17, 0x33 }, { 18, 0x99 }, {
				19, 0xE9 } };
int PL[26][2] = { { 0, 0x00 }, { 1, 0x00 }, { 2, 0x0F }, { 3, 0xFF },
		{ 4, 0xFF }, { 5, 0x05 }, { 6, 0xAA }, { 7, 0x55 }, { 8, 0xFE }, { 9,
				0x00 }, { 10, 0x00 }, { 11, 0x00 }, { 12, 0xFF }, { 13, 0xFF },
		{ 14, 0xFF }, { 15, 0xFF }, { 16, 0x11 }, { 17, 0x33 }, { 18, 0x99 }, {
				19, 0xE9 }, { 20, 0xFF }, { 21, 0x11 }, { 22, 0x33 },
		{ 23, 0x99 }, { 24, 0xE9 }, { 25, 0x7F } };
int F_P_Data[4][2];
int air[5];
int z = 0;
int flag = 1;
int assign_data() {
	//assign PR data from 0 each time index is increasing 15
	for (int i = 0; i <= 25; i = i + 5) {
		static int z = 0;
		if ((flag == 1)) {
			if (PR[i][1] >= 0x05 && PR[i][1] <= 0xF5) {
				F_P_Data[z][0] = PR[i][0];
				F_P_Data[z][1] = PR[i][1];
				z++;
				flag++;
				continue;
			} else {
				continue;
			}
		}
		if (flag == 2) {
			if ((PC[i][1] >= 0x05) && PC[i][1] <= 0xF5) {
				F_P_Data[z][0] = PC[i][0];
				F_P_Data[z][1] = PC[i][1];
				z++;
				flag++;
				continue;
			} else {
				continue;
			}
		}
		if (flag == 3) {
			if ((PL[i][1] >= 0x05) && PL[i][1] <= 0xF5) {
				F_P_Data[z][0] = PL[i][0];
				F_P_Data[z][1] = PL[i][1];
				z++;
				flag = 1;
			} else {
				continue;
			}
		}
		if ((15 - i) < 5) {
			break;
		}

	}

	for (int i = 0; i < 3; i++) {
		printf("%d\t\t", F_P_Data[i][0]);
		printf("0X%x\n", F_P_Data[i][1]);
	}

	return 0;
}

int air_bag() {
	int count = 0;
	int flag = 0;

	for (int i = 0; i < size; i++) {

		if (F_P_Data[i][1] > 0x55) {
			if ((++count) == 3 && ((flag + 1) == i)) //check 3times or not and prev value is also 0 or not
					{
				int k;
				k = i;
				for (int j = 0; j < 3; j++) {
					air[j] = F_P_Data[k][1];
					k--;
				}
				return 1;
			}
		}
		flag = i;
	}

	return 0;
}

int main() {
	//printing the pressure sensor data from user for PR
	printf("Printing  the PR data :\n");
	printf("\nPR time stamp\t\tPR data\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				//printing time stamp values
				printf("%d\t\t\t", PR[i][j]);
			} else {
				//Printing the data in hexa format
				printf("0X%x", PR[i][j]);
			}

		}
		printf("\n");

	}

	//printing the pressure sensor data from user for PC
	printf("Printing  the PC data :\n");
	printf("\nPC time stamp\t\tPC data\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				//printing time stamp values
				printf("%d\t\t\t", PC[i][j]);
			} else {
				//Printing the data in hexa format
				printf("0X%x", PC[i][j]);
			}
		}
		printf("\n");

	}

	//printing the pressure sensor data from user for PL
	printf("Printing  the PL data :\n");
	printf("\nPL time stamp\t\tPL data\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				//printing time stamp values
				printf("%d\t\t\t", PL[i][j]);
			} else {
				//Printing the data in hexa format
				printf("0X%x", PL[i][j]);
			}
		}
		printf("\n");

	}
	//removing noise and assigning to new array from PR PC PL
	assign_data();
	for (int i = 0; i < size; i++) {
		printf("%d\t\t", F_P_Data[i][0]);
		printf("0X%x\n", F_P_Data[i][1]);
	}
	//checking air bag deploy condition
	if (air_bag() == 1) {
		printf("Air Bag is opened");
	}

	for (int i = 0; i < 3; i++) {
		printf("\n0x%x", air[i]);
	}
}*/
