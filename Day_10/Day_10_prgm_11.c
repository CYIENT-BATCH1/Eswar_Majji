/*Name : Eswar Majji
 * Id : em69324
 Write a program to Implement ”Selection Sort” using Recursion for given elements (Number elements will vary, so make it as configurable item)
 How Selection sort works is explained below.
 */
#include <stdio.h>
void sort_array(int *array, int size, int i, int j)
{
	int temp;
	//to end recursion
	if (i  == ( size - 1 ))
	{
		return;
	}
	else
	{
		//checking less than or not
		//if true swap
		if(array[j] < array[i])
		{
			temp = *(array + j);
			*(array + j) = *(array + i);
			*(array + i) = temp;
		}
		//after j reaches to size -1
		//increment i
		if(j == (size - 1))
		{
			i++;
			j = i;
		}
		//calling function
		sort_array(array, size, i, ++j);
	}
}

int main()
{
	int size;
	static int i = 0;
	static int j = 1;
	printf("Enter size of the array: ");
	fflush(stdout);
    scanf("%d", &size);

    //array declaration and initialization
    int array[size];
	printf("Enter array elements : ");
    for (int i = 0; i < size; i++)
    {
    	fflush(stdout);
        scanf("%d", &array[i]);
    }
    //printing unsorted array
    for (int i = 0; i < size; i++)
    {
    	printf("%d ", array[i]);
    }
    printf("\n");
    sort_array(array, size, i, j);

    //printing sorted array
    for (int i = 0; i < size; i++)
    {
       	printf("%d ", array[i]);
    }

}
