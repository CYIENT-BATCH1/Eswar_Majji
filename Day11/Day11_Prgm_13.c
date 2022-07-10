/*Name : Eswar Majji
 * Id : em69324
 Write a program to do binary search in a sorted array. Program should take input of sorted values and search value. (Make number of elements as configurable value)
 How binary search works is explained below.
 */

#include <stdio.h>
/*
int main()
{
	int size, search_num;
	printf("Enter size of the array: ");
	fflush(stdout);
    scanf("%d", &size);

    //array declaration and initialization
    int array[size];
	printf("Enter sorted array elements : ");
    for (int i = 0; i < size; i++)
    {
    	fflush(stdout);
        scanf("%d", &array[i]);
    }


    printf("Enter the number you want to search : ");
    fflush(stdout);
    scanf("%d", &search_num);

    if (search_num == array[((size - 1)/2)])
    {
    	printf("given number is at %d index position\n", (size/2) );
    }
    else if (search_num < array[((size - 1)/2)])
    {
    	for (int i = 0; i < ((size - 1) / 2); i++)
    	{
    		if (array[i] == search_num)
    		{
    			printf("given number is at %d index position\n", i);
    			return 0;
    		}
    	}
    }
    else if (search_num > array[((size - 1)/2)])
    {
    	for (int i = ((size - 1) / 2); i < size; i++)
    	{
       		if (array[i] == search_num)
       		{
       			printf("given number is at %d index position\n", i);
    	   		return 0;
    		}f
    	}

    }
    else
    {
    	printf("given number is not founded\n");
    }
}
*/
/*
int main()
{
	int size, search_num, mid = 0, high = 0, low = 0, check = 0;
	printf("Enter size of the array: ");
	fflush(stdout);
    scanf("%d", &size);

    //array declaration and initialization
    int array[size];
	printf("Enter sorted array elements : ");
    for (int i = 0; i < size; i++)
    {
    	fflush(stdout);
        scanf("%d", &array[i]);
    }

    printf("Enter the number you want to search : ");
    fflush(stdout);
    scanf("%d", &search_num);

    while (search_num != check)
    {
    	high = (size - 1);
    	low = 0;
    	mid = (high + low) / 2;
    	if( array[mid] == search_num )
    	{
    		printf("Given number found at %d", mid );
    		return 0;
    	}
    	else if(search_num < array[mid])
    	{
    		//left side
    		high = mid - 1;
    		mid = (low + high) / 2;
    		if(search_num == array[mid])
    		{
    			printf("Given number found at %d", mid );
    			return 0;
    			//check = search_num;
    		}
    	}
    	else if(search_num > array[mid])
    	{
    		//right side
    		low = mid + 1;
    		mid = (low + high) / 2;
    		if(search_num == array[mid])
    		{
    			printf("Given number found at %d", mid );
    			//check = search_num;
    			return 0;
    		}
    	}
    }

}
*/
int main()
{
	int size, search_num, mid = 0, high = 0, low = 0, check = 0;
	printf("Enter size of the array: ");
	fflush(stdout);
    scanf("%d", &size);

    //array declaration and initialization
    int array[size];
	printf("Enter sorted array elements : ");
    for (int i = 0; i < size; i++)
    {
    	fflush(stdout);
        scanf("%d", &array[i]);
    }

    printf("Enter the number you want to search : ");
    fflush(stdout);
    scanf("%d", &search_num);

    while (search_num != check)
    {
    	high = (size - 1);
    	low = 0;
    	mid = (high + low) / 2;
    	if( array[mid] == search_num )
    	{
    		printf("Given number found at %d", mid );
    		return 0;
    	}
    	else if(search_num < array[mid])
    	{
    		//left side
    		high = mid - 1;
    		mid = (low + high) / 2;
    		if(search_num == array[mid])
    		{
    			printf("Given number found at %d", mid );
    			return 0;
    			//check = search_num;
    		}
    	}
    	else if(search_num > array[mid])
    	{
    		//right side
    		low = mid + 1;
    		mid = (low + high) / 2;
    		if(search_num == array[mid])
    		{
    			printf("Given number found at %d", mid );
    			//check = search_num;
    			return 0;
    		}
    	}
    }

}
