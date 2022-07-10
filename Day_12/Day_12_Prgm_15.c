/*Name : Eswar Majji
 * Id : em69324
Find empty strings in an array of strings (Array of strings will be given as input to program) and
print the position of array where empty string is present.
 And replace the empty string array element as “CYIENT”
 */
#include <stdio.h>
#include <string.h>
int main()
{

	int num;

	printf("Enter no of Company names : ");
	fflush(stdout);
	scanf("%d", &num);
	//int i = 0;

	char companies[num][100];
	//char check[100];

	printf("Enter Company names [for empty string enter 0 ] :\n");
	for(int i = 0; i < num; i++)
	{
		fflush(stdout);

		scanf(" %s", *(companies + i));
	}

	for(int i = 0; i < num; i++)
	{
		if (strcmp(*(companies + i), "0") == 0)
		{
			strcpy(*(companies + i), "CYIENT");
		}
	}

	for(int i = 0; i < num; i++)
	{
		printf("%s\n", *(companies + i));
	}
	return 0;
}
