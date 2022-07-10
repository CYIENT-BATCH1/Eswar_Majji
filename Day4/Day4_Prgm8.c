/*Coded by Eswar Majji(69324) */
//SWAPPING OF TWO NUMBERS WITHOUT USING THIRD VARIABLE

#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Enter two numbers : ");
    scanf("%d %d", &num1, &num2);//5 10
    num1^=num2^=num1^=num2;
    
    //num1 = num1 + num2;//15 10
    //num2 = num1 - num2;//15 5
    //num1 = num1 - num2; // 10 5
    
    printf("After Swaping number are : %d %d", num1, num2);
    return 0;
}
