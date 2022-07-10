//Eswar Majji(em69324)
// Write program to clear(0) bits CIS, CM2, CM1, CM0 in register “CMCON” if bits CHS3, CHS2, CHS1, CHS0 bits are set to 0x07 in register “ADCON0”

#include <stdio.h>

int main()
{
    int num1;
    int num2;
    //reading ADCON0 reagister
    printf("Enter number to check 1s in ADCON0 register : ");
    fflush(stdout);
    scanf("%d", &num1);
    //reading CMON reagister
    printf("Enter number to set 1s in CMCON : ");
    fflush(stdout);
    scanf("%d", &num2);
    
    //28 -> 0001 1100 -> 4 3 2 bits are equal to 0x07
    if((28 & num1 ) == 28 )
    {
    	num2 = num2 & 0xF0;
    	printf("number after clearing 1s at required positions : %d", num2);
    }
    else
    {
    	printf("CHS3, CHS2, CHS1, CHS0 bits are not equal to 0x7 ");
    }

    return 0;
}
