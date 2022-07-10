/* Coded By Eswar Majji (em69324)*/
//A message is encoded in the form of numbers and sent to you. Write a program to decode the message. (HINT: A=1, B=2, … so on) 

#include <stdio.h>

int main()
{
    int i = 0;
    char str[100];
    //reading string
    scanf("%[^\n]", str);
    
    //printing letters by using ascii values based on given numbers
    while (str[i] != '\0')
    {
        //eliminating spaceces
        if (str[i] == ' ')
        {
            i++;
            continue;
        }
        printf("%c", str[i] + 48);
        i++;
    }
    return 0;
}
