//Coded by Eswar Majji(69324)
/*Write a program to achieve below statements.

Collect 15 elements (8 integers, 7 float) as i/p from user.

Calculate and Print the sum, average and mean of integers

Calculate and Print the sum, average of all float values

Divide sum in statement ‘b’ with statement ‘c’ sum and print the value.

Divide average in statement ‘b’ with statement ‘c’ average and print the value.

Convert all 7 float values to integers and print them.*/
#include <stdio.h>
int main()
{
	int inti[8];
	int sum1 = 0, sum2 = 0;
	float avg1, avg2;
	float num[7];
	printf("Enter integers :");
	for(int i = 0; i < 8; i++)
	{
		fflush(stdout);
		scanf("%d", &inti[i]);
	}
	printf("Enter float numbers :");
	for(int i = 0; i < 7; i++)
	{
		fflush(stdout);
		scanf("%f", &num[i]);
	}

	for(int i = 0; i < 8; i++)
	{
		sum1 += inti[i];
	}
	printf("sum of integers is %d\n", sum1);
	printf("Average of integers %0.2f\n", avg1  = sum1/(float)8);

	for(int i = 0; i < 7; i++)
	{
		sum2 += num[i];
	}
	printf("sum of float numbers is %d\n", sum2);
	printf("average of float numbers %0.2f\n", avg2 = sum2/(float)7);

	printf("division of sums is %02f", sum1/(float)sum2);
	printf("average of float numbers %0.2f\n", avg1/(float)avg2);

	for(int i = 0; i < 7; i++)
	{
		printf("integers are %0.0f\n", num[i]);
	}
	return 0;

}
