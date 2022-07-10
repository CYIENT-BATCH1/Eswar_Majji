/*Coded by Eswar Majji(69324) */
// POSITIVE OR NEGATIVE NUMBER USING CONDITIONAL OPERATOR

#include <stdio.h>

int main()
{
    int num1;
    printf("Enter two numbers : ");
    scanf("%d", &num1);
    num1 >= 0 ? printf("Positive number") : printf("Negative number");
    return 0;
}
