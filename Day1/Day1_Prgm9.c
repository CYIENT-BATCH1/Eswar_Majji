/* Coded By Eswar Majji (em69324)*/

//Implement basic logic gates using C (AND, OR, NOT). Consider the inputs: 0,0

   			0,1

  			1,0

   			1,1. 
#include <stdio.h>
int main()
{
    int ip1, ip2, op;
    //AND gate
    printf("AND gate\n");
    for(int i = 0; i < 4; i++)
    {
        printf("Enter two inputs :");
        scanf("%d %d", &ip1, &ip2);
        op = ip1 & ip2;
        printf("%d", op);
        printf("\n");
    }    
    //OR gate
    printf("OR gate\n");
    for(int i = 0; i < 4; i++)
    {
        printf("Enter two inputs :");
        scanf("%d %d", &ip1, &ip2);
        op = ip1 |ip2;
        printf("%d", op);
        printf("\n");
    }
    
    //NOT gate
    printf("NOT gate\n");
    for(int i = 0; i < 2; i++)
    {
        printf("Enter inputs :");
        scanf("%d", &ip1);
        op = !ip1;
        printf("%d", op);
        printf("\n");
    }
    
    
    return 0;
}
