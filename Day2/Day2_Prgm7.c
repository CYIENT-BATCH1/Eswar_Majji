//Coded by Eswar Majji(69324)
//Find the number of leap years in the interval 1990-2022.
#include <stdio.h>

int main()
{
    int year = 1990, count = 0; 
    loop :
    if (year <= 2022)
    {
        if((((year % 4) == 0) && (year % 100) != 0) || ((year % 400) !=  0))
		    {
			      count++;
		    }
		    year++;
		    goto loop;
    }
    printf("no of leap years : %d", count);
    return 0;
}
