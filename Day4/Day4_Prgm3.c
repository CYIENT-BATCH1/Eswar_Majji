//Coded By Eswar Majji(69324)
//LOGICAL OPERATOR

#include <stdio.h>

int main()
{
    int i=10,j=20,k;
    k=i&&j;
    printf("k = %d\n", k);
    k=i||j;
    printf("k = %d\n", k);
    
    k=!i;
    printf("k = %d\n", k);
     i=10,j=0,k;
    
    k=i&&(j=20);//i=?,j=?,k=?
    printf("i = %d, j = %d, k = %d\n",i, j, k);
    k=i||(j=20);//i=?,j=?,k=?
    printf("i = %d, j = %d, k = %d\n",i, j, k);

    i=0,j=0,k=30;
    int l;
    l=i||(j=20)&&k; //i=?,j=?,k=?,l=?
    printf("i = %d, j = %d, k = %d, l = %d\n",i, j, k, l);

    i=10,j=10,k=0;
    
    l=i&&j||j&&k;
    printf("i = %d, j = %d, k = %d, l = %d\n",i, j, k, l);
    
    l=(i=2)||j&&i||k;
    printf("i = %d, j = %d, k = %d, l = %d\n",i, j, k, l);
    
    l=i-10+(i=99);
    printf("i = %d, j = %d, k = %d, l = %d\n",i, j, k, l);
    
    return 0;
}
