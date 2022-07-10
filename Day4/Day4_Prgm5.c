//Coded By Eswar Majji(69324)
//INCREMENT AND DECREMENT

#include <stdio.h>

int main()
{
    int i=10,j=50,k;
    k=++i+j++//i=?,j=?,k=?
    printf("k = %d\n", k);
    
    k=i++-++j;//i=?,j=?,k=?
    printf("k = %d\n", k);
    
    k=--i+j++ * i++ -j--; //i=?,j=?,k=?
    printf("k = %d\n", k);
    
    k=(i--+ j++);//i=?,j=?,k=?
    printf("k = %d\n", k);

    return 0;
}
