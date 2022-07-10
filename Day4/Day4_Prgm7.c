/*Coded by Eswar Majji(69324) */
//SWAPPING OF TWO NUMBERS WITH USING THIRD VARIABLE

#include <stdio.h>

int main()
{
    int num1, num2, temp;
    printf("Enter two numbers : ");
    scanf("%d %d", &num1, &num2);
    temp = num1;
    num1 = num2;
    num2 = temp;
    
    printf("After Swaping number are : %d %d", num1, num2);
    return 0;
}
