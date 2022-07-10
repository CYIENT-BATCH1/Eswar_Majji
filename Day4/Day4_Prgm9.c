/*Coded by Eswar Majji(69324) */
//BIGGEST OF TWO NUMBERS USING CONDITIONAL OPERATOR

#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Enter two numbers : ");
    scanf("%d %d", &num1, &num2);
    num1>num2 ? printf("Biggest among two numbers : %d",num1) : printf("Biggest among two numbers : %d",num2);
    return 0;
}
