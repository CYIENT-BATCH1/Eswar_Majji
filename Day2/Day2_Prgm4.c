//Coded by Eswar Majji(69324)
//Kishore bought ‘n’ number of lottery tickets. His lucky number is 3 so he wants to separate all the tickets that have the number 3 in them. Find how many such lucky tickets are found in the ‘n’ number of tickets purchased by Kishore.
#include <stdio.h>
int main()
{
    int count = 0, num, i, last,num2;
    printf("Enter number : ");
    fflush(stdout);
    scanf("%d", &num);
    for(i = 1; i <= num; i++)//looping upto given number
    {
        num2 = i;//copying num to another variablr
        while(num2 != 0)//looping to take each digit
        {
            last = num2 % 10;//extract last digit
            if (last == 3)//check itr is equal to 3 or not
            {
                count++;//counting no of threes
                break;
            }
            num2 = num2 / 10;
        }
    }

    printf("number of threes in given number : %d", count);
    return 0;
}
