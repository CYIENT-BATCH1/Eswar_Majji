/* Coded By Eswar Majji (em69324)*/

//Take a 6-digit number as input from the user and reverse the number. Make sure that the number does not include a ‘0’ in any of its digits.
#include <stdio.h>
int main()
{
    int num, rev = 0, rem;
    printf("Enter the 6 digit number :");
    scanf("%d", &num);
    while (num != 0)
    {
        rem = num % 10;
        if ( rem == 0 )
        {
            printf("you entered number with zero\n");
        }
        rev = rev * 10 + rem;
        num = num / 10;
    }
    printf("Reversed number is %d", rev);
    return 0;
}
