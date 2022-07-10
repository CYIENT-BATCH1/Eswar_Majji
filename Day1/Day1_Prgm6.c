/* Coded By Eswar Majji (em69324)*/
//Students with roll numbers 1-9 are seated in ascending order in an examination hall. There has been a slight mistake in their seating arrangement where two consecutive roll numbers have been swapped. Choose these two consecutive numbers as per your choice and swap them back in their right places according to ascending order.

#include <stdio.h>
int main()
{
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, temp;
    printf("Enter 9 students roll numbers : ");
    scanf("%d %d %d %d %d %d %d %d %d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9);
    
    loop:
    if (n1 > n2)
    {
        temp = n1;
        n1 = n2;
        n2 = temp;
        goto loop;
    }
    if (n2 > n3)
    {
        temp = n2;
        n2 = n3;
        n3 = temp;
        goto loop;
    }
    if (n3 > n4)
    {
        temp = n3;
        n3 = n4;
        n4 = temp;
        goto loop;
    }
    if (n4 > n5)
    {
        temp = n4;
        n4 = n5;
        n5 = temp;
        goto loop;
    }
    if (n5 > n6)
    {
        temp = n5;
        n5 = n6;
        n6 = temp;
        goto loop;
    }
    if (n6 > n7)
    {
        temp = n6;
        n6 = n7;
        n7 = temp;
        goto loop;
    }
    if (n7 > n8)
    {
        temp = n7;
        n7 = n8;
        n8 = temp;
        goto loop;
    }
    if (n8 > n9)
    {
        temp = n8;
        n8 = n9;
        n9 = temp;
        goto loop;
    }
    printf("After swapping : %d %d %d %d %d %d %d %d %d", n1, n2, n3, n4, n5, n6, n7, n8, n9);
    return 0;
}
