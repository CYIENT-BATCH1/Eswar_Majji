/* Coded By Eswar Majji (em69324)*/

//The entire area of a circular garden is to be covered with grass by a Gardener. The radius of the garden is given by the user input. Calculate the area that has to be covered.
#include <stdio.h>
int main()
{
    float num;
  
    //Reading num from user
    printf("Enter the Radius of the Garden :");
    scanf("%f", &num);
    
    //22/7 = 3.14
    printf("Area is %f", 3.14*num*num);
    return 0;
}
