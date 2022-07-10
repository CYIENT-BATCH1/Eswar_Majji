//Eswar Majji (em69324)
//Write a code to swap even bits with odd bits in unsigned long variable(uint64).
#include <stdio.h>

int main()
{
    //initialize long int varaible
    long int num;
    printf("Enter long int number : ");
    fflush(stdout);//read number
    scanf("%ld", &num);
    unsigned long int i,n=1;
    //loop 32 times 
    for(i = 0; i < 64; i += 2 )
    {
        if (((n << i) & num) != 0)//check that bit is 1 or not 
        {
            if((n << (i + 1) & num) == 0)//check preceeding bit is 0 or not
            {
                num = num & (~(n << i)); // clear current bit
            }
            num = num | (n << (i + 1));//set preceeding bit
        }
        else//if bit 0
        {
            if(((n << (i + 1)) & num) != 0)//check preceeding bit is 0 or not
            {
                num = num | (n << i);//set current bit
            }
            num = num & (~(n << (i + 1)));//set preceeding bit
        }
    }
    printf("Number After Swapping : %ld", num);

    return 0;
}
