//Coded By Eswar Majji(69324)
//BITWISE OPERATOR

#include <stdio.h>

int main()
{
    int i=10,j=20,m=5,k;
    k=i&j; //k=?
    printf("k = %d\n", k);
    k=i|j;
    printf("k = %d\n", k);
    k=i^j;
    printf("k = %d\n", k);
    k=i&&j|m&&j;
    printf("k = %d\n", k);
    k=j&m&&i ||(i=2);
    printf("k = %d i = %d\n", k, i);
    k=i&j|j||m;
    printf("k = %d\n", k);
    i=10,j=20,k=30;
    k=i&&j&k;
    printf("k = %d\n", k);
    k=i&j|k&&i;
    printf("k = %d\n", k);
    k=i||j&j;
    printf("k = %d\n", k);
    k=i||j&(j&&k);
    printf("k = %d\n", k);

    return 0;
}
