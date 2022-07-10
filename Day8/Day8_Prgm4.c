/*Name : Eswar Majji
 * Id : em69324
 *
 * Realize a function which has 2 arguments and 1 return value. Argument 1 is Byte value, Argument 2 is bit position.
 *  Function has to flip the bit position (as per argument 2) in argument 1 byte value and return complete byte value.
 *
 *  Sudocode :
 *  Read num and bit position
 *
 */

#include <stdio.h>

//function definition
int flip(char *num, int bit)
{
	int n;
	n = *num;
	n = n ^ (1 << (bit - 1)); //setting bits at required position 
	return n;
}

int main()
{
	int byte;
	int bit;
    
    //read bit 
	printf("Enter Bit : ");
	fflush(stdout);
	scanf("%d", &bit);
    //read byte 
	printf("Enter a number less than 256: ");
	fflush(stdout);
	scanf(" %d", &byte);
    //check byte is less than 256 
	if(byte >= 255)
	{
		printf("Entered number is greater than 255");
		return 0;
	}
    //calling function
	byte = flip(&byte, bit);

    

	printf("Flipped Byte is  %d", byte);

}
