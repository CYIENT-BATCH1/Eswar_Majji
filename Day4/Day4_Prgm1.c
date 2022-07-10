//Coded by Eswar Majji(69324)
//ARITHMATICAL OPERATOR

#include <stdio.h>

int main()
{
    int x=30, y=20, z=10 , k;
    k = x + y * z / 4 % 2 - 1 ;
    printf("%d\n", k);
    k= x% y+z*z;
    printf("%d\n", k);
    
    k=  x*x-y/z;
    printf("%d\n", k);
    
    k= x+y/z-y; 
    printf("%d\n", k);
    y=x+y-(x=y); //y=?
    printf("%d\n", y);
    //y=x+y-x=y ;   //y=?
    //printf("%d", y);


    return 0;
}
