/* Coded By Eswar Majji (em69324)*/

//5 balls are numbered with random 1-digit number each. Assign these numbers using user input. Print whether each ball is assigned odd or even number.
#include <stdio.h>
int main()
{
    int b1, b2, b3, b4, b5;
    //reading 5 intigers from user
    printf("Enter 5 random 1 digit numbers :");
    scanf("%d %d %d %d %d", &b1, &b2, &b3, &b4, &b5);
  
    //checking each number is even or odd
    ((b1 % 2) == 0) ? printf("1st ball num even\n") : printf("1st ball num odd\n");
    ((b2 % 2) == 0) ? printf("2nd ball num even\n") : printf("2nd ball num odd\n");
    ((b3 % 2) == 0) ? printf("3rd ball num even\n") : printf("3rd ball num odd\n");
    ((b4 % 2) == 0) ? printf("4th ball num even\n") : printf("4th ball num odd\n");
    ((b5 % 2) == 0) ? printf("5th ball num even\n") : printf("5th ball num odd\n");
    return 0;
}
