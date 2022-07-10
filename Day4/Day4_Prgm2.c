//Coded By Eswar Majji(69324)
//RELATIONAL OPERATOR

#include <stdio.h>

int main()
{
    int x=10,y=20,z;
    z= x<y;
    printf("%d\n", z);
    z= x>y;
    printf("%d\n", z);
    z=x<=y;
    printf("%d\n", z);
    z=(x*x-y)>(y*y-x);
    printf("%d\n", z);
    z=(x*x*x)<(y*x*x);
    printf("%d\n", z);
    z=((x*y)!=(y*x));
    printf("%d\n", z);
    z=((x*y)==(y*x));
    printf("%d\n", z);
    
    return 0;
}
