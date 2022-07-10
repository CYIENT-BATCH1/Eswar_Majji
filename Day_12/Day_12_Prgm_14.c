/*Name : Eswar Majji
 * Id : em69324
Find common elements in three sorted arrays, 3 array values are given as input to program.
 */
#include <stdio.h>
int main()
{
	int size1, size2, size3;
	printf("Enter size1 of the array1: ");
	fflush(stdout);
    scanf("%d", &size1);

    //array declaration and initialization
    int array1[size1];
	printf("Enter sorted array1 elements : ");
    for (int i = 0; i < size1; i++)
    {
    	fflush(stdout);
        scanf("%d", &array1[i]);
    }


    printf("Enter size2 of the array2: ");
    fflush(stdout);
    scanf("%d", &size2);

    //array declaration and initialization
    int array2[size2];
  	printf("Enter sorted array2 elements : ");
  	for (int i = 0; i < size2; i++)
  	{
      	fflush(stdout);
      	scanf("%d", &array2[i]);
  	}

  	printf("Enter size3 of the array3: ");
    fflush(stdout);
    scanf("%d", &size3);

    //array declaration and initialization
    int array3[size3];
    printf("Enter sorted array3 elements : ");
    for (int i = 0; i < size3; i++)
    {
     	fflush(stdout);
     	scanf("%d", &array3[i]);
    }

    //finding common element
    printf("Common Elements are : ");
    for(int i = 0; i < size1; i++)
    {
    	for(int j = 0; j < size2; j++)
    	{
    		for(int k = 0; k < size3; k++)
    		{
    			if((array1[i] == array2[j]) && (array1[i] == array3[k]))
    			{
    				printf("%d ", array3[k]);
    			}
    		}
    	}
    }
    return 0;
}
