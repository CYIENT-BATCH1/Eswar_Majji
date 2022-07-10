/* Coded By Eswar Majji (em69324)
A message ID is required to send data via CAN communication between ECU’s. Accept a random 2-digit message ID from the user to send data.
Keep in mind that the given ECU only accepts binary form of the message ID. Write a program to convert the 2-digit ID to binary form.*/


#include <stdio.h>

int main()
{
    short num, digit = 0, num2, rem, i = 31;
    printf("Enter Two digit number : ");\
    scanf("%hd", &num);
    num2 = num;
    //checking num is two digit or not
    loop : 
    if(num != 0)
    {
        rem = num % 10;
        num = num / 10;
        digit++;
        goto loop;
    }
    //printing binary numbers when digits is equal to 2
   
    if(digit == 2)
    {
        loop2 :
        if(i >= 0)
        {
            (1 << i) & num2 ? printf("1 ") : printf("0 ");
            i--;
            goto loop2;
        }
    }
    else
    {
        printf("Entered number is not a two digit number \n");
    }
    return 0;
}
