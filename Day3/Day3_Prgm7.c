//Coded by Eswar Majji(69324)
//Write program to calculate the age of a person based on year, month as i/p
#include<stdio.h>

int main()
{
	int month, year;
	float age, monthf, yearf;
  printf("Enter the Year : ");
  scanf("%d", &year);
  printf("Enter the Month : ");
  scanf("%d",&month);
  yearf = (2022 - year) * 12;
  monthf = (7 - month);
  age = (yearf + monthf) / 12;
  printf("Age of the Person is %0.2f", age);
	return 0;
}
