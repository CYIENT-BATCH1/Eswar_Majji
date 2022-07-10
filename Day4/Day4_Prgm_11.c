/*Coded by Eswar Majji(69324) */
//EVEN AND ODD NUMBER USING CONDITIONAL OPERATOR

#include <stdio.h>

int main()
{
    int num1;
    printf("Enter two numbers : ");
    scanf("%d", &num1);
    (num1%2) == 0 ? printf("Even number") : printf("odd number");
    return 0;
}
