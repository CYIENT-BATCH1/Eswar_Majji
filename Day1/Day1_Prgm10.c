/* Coded By Eswar Majji (em69324)*/

//Consider the weights of three people as user input. Find the heaviest among them and print it.
#include <stdio.h>
int main()
{
    int w1, w2, w3;
    //read 3 weights
    printf("Enter three persons weights : ");
    scanf("%d %d %d", &w1, &w2, &w3);
    
    //if w1 is more
    if ( (w1 > w2) && (w1 > w3) )
    {
        printf("1st person heaviest");
    }
    //if w2 is more
    else if ( (w2 > w1) && (w2 > w3) )
    {
        printf("2nd person heaviest");
    }
    //if w3 is more
    else if ( (w3 > w1) && (w3 > w3) )
    {
        printf("3rd person heaviest");
    }
    //if 3 are equal
    else
    {
        printf("3 are Equal in weight");
    }
    return 0;
}
