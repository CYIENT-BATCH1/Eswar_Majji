/* Coded By Eswar Majji (em69324)*/

//Find whether a given 10-digit number is palindrome or not.  (HINT: Any number is said to be a palindrome if the original number and the reverse of the original number are the same.)

#include <stdio.h>
int main()
{
    int num, rev = 0, rem, check, count = 0;
    //reading 6 digit num from user
    printf("Enter the 6 digit number :");
    scanf("%d", &num);
    check = num;
    
    while (num != 0)
    {
        rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
        count++;
    }
    //if num is not 10 digits
    if (count != 10)
    {
        printf("given number is not 10 digits");
    }
    //if it is palindrome
    else if (check == rev)
    {
        printf("Entered  number is Palindrome");
    }
    //if num is not palindrome
    else 
    {
        printf("not palindrome");
    }
    return 0;
}
