//Coded By Eswar Majji(em69324)

//Write a program to convert a data stream from Little Endian to Big Endian (you can take any 8 bit value or use 0b110101110)?


#include <stdio.h>

int main()
{
    int num;
    printf("Enter Little Endian number : ");
    fflush(stdout);
    scanf("%X", &num);

    int b01, b23;

    b01 = (num & 0x0F) << 4;
    b23 = (num & 0xF0) >> 4;
    num = b01 | b23 ;

    printf("Big Endian number : %X", num);

    return 0;
}
