//Coded by Eswar Majji(69324)

//Write a program to calculate the sum of the first and the second last digit of a 5-digit number entered from the keyboard.
#include <stdio.h>
int main()
{
	int num, num2, sum = 0;
	printf("Enter 5 digit number :");
	fflush(stdout);
	scanf("%d", &num);

	for(int i = 0; i < 5; i++)
	{
		num2 = num % 10;
		if((i== 1) || (i == 4))
		{
			sum = sum + num2;
		}
		num = num / 10;
	}
	printf("sum is %d", sum);
}
