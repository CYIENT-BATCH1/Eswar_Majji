//Coded By Eswar Majji(69324)
//RELATIONAL OPERATOR

#include <stdio.h>
int main()
{
	int i=10,j=2,k;
	k = i << j;
	printf("%d\n", k);

    k = i >> j;
    printf("%d\n", k);
    
    k = (i&&j) << j;
    printf("%d\n", k);
    
    k = (i||j) >> j;
    printf("%d\n", k);

    k = (i&j) << i;
    printf("%d\n", k);
    
    k = (i||j&&i);
    printf("%d\n", k);
    
    return 0;
}
