/*Coded by Eswar Majji(69324) */
// GIVEN NUMBER IS POWER OF 2 OR NOT

#include <stdio.h>

int main()
{
    int num1;
    printf("Enter two numbers : ");
    scanf("%d", &num1);
    ((num1 & (num1 - 1)) != 0) ? printf("NO") : printf("YES");
    return 0;
}
