/*Name : Eswar Majji
 * Id : em69324
 *
 * Write a program in C to sort an array using Pointer. The sample output must be as below.
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *arr, n;
	printf("enter size :");
	fflush(stdout);
	scanf("%d", &n);

	arr = (int *)malloc(n * sizeof(int));
	printf("<---------------Sorting an Array using Pointer--------------->");

	printf("Input %d elements of an array\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Element - %d : ", i);
		fflush(stdout);
		scanf("%d", arr+i);
	}
	
	int temp;
	
	//sorting
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			
			if(*(arr + j) < *(arr + i))
			{
				temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp;
			}
		}
	}

	printf("\nElements in array after sorting :\n");
	for (int i = 0; i < n; i++)
	{
		printf("element - %d : %d \n", i, *(arr+i));
	}
}
