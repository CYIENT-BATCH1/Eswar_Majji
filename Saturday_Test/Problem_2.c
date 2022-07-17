/******************************************************************************
 * Name : Eswar Majji
 * id : em69324
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int count_0;
//function definition

int CAN_arbitration(int* id_messages, int no_of_messages)
{
	int num = 0;
	int count = 0;
	unsigned int arbitration_winner = 0;
	for(int i = 0; i < no_of_messages; i++)
	{
	    if(*(id_messages + i) == 0x0)//if 0x0 id is given more than 1 time
	    {
    		count_0++;
    	}
	}
	if(count_0 == 1)//if only single 0x0
	{
        return 0;
    }
    else if (count_0 > 1)// more 0x0s
    {
        return 0;
    }
    //lopping to check each bit
	for(int i = 3; i >= 0; i--)
	{
		num = num | 1 << i;//shifting  1 to ith position
        //checking each id at ith position
		for(int j = 0; j < no_of_messages; j++)
		{
    		if(((num & *(id_messages + j)) >> i) == 1)//if all ids have dominant at ith position
		    {
			    count++;
		    }
			    if(*(id_messages + j) != 0b1111111111111111)
			    {
				    if(((num & *(id_messages + j)) >> i) == 1)//making  all 1s wherever get dominant
				    {
					    arbitration_winner = *(id_messages + j);//the last dominant is the arbitration winner
					    *(id_messages + j) = 0b1111111111111111;
				    }
			    }

		}
		if(count == no_of_messages)
		{
		    //printf("There is no message to win arbitration12\n");
		    return 0;
		}
		count= 0;
	}

    return arbitration_winner;
}
int main()
{
	unsigned int no_of_messages, arbitration_winner = 0;
	int* id_messages;
	int choice;
	while(1)
	{
        printf("\n1.standard frame \n2.Extended frame\n3.Exit\nchoose option : ");
        fflush(stdout);
        scanf("%d", &choice);
        if(choice == 1)
        {
	        //reading no of messages
	        printf("Enter no of Messages : ");
	        fflush(stdout);
	        scanf("%d", &no_of_messages);
	        //checking no of messages are less than 0x7FF or not
	        if(no_of_messages > 2047)
    	    {
	    	    printf("You Entered greater than 0x7FF and we considering only 0x7FF messages");
		        no_of_messages = 0x7FF;
	        }
	        //initializing array with given size
	        id_messages = (int*) calloc(no_of_messages , sizeof(int));

	        //read message id's
	        printf("Enter Message Id's : ");
	        for(int i = 0; i < no_of_messages; i++)
	        {
		        fflush(stdout);
		        scanf("%X", (id_messages+i));
	        }
	        //calling function to find arbitration winner

	        arbitration_winner = CAN_arbitration(id_messages, no_of_messages);
            if(arbitration_winner != 0)
            {
	            printf("arbitration_winner : 0x%X", arbitration_winner);
            }
            else
            {
                if(count_0 == 1)
                {
                    printf("arbitration_winner1 : 0x00");
                }
                else
                {
                    printf("There is no message id to win arbitration\n");
                }
            }
        }
        else if (choice == 2)
        {
	        //reading no of messages
	        printf("Enter no of Messages : ");
	        fflush(stdout);
	        scanf("%d", &no_of_messages);
	        //checking no of messages are less than 0x1FFFFFFF or not
	        if(no_of_messages > 0x1FFFFFFF)
    	    {
	    	    printf("You Entered greater than 0x7FF and we considering only 0x7FF messages");
		        no_of_messages = 0x1FFFFFFF;
	        }
	        //initializing array with given size
	        id_messages = (int*) calloc(no_of_messages , sizeof(int));

	        //read message id's
	        printf("Enter Message Id's : ");
	        for(int i = 0; i < no_of_messages; i++)
	        {
		        fflush(stdout);
		        scanf("%X", (id_messages+i));
	        }
	        //calling function to find arbitration winner

	        arbitration_winner = CAN_arbitration(id_messages, no_of_messages);
            if(arbitration_winner != 0)
            {
	            printf("arbitration_winner : 0x%X", arbitration_winner);
            }
            else
            {
                if(count_0 == 1)
                {
                    printf("arbitration_winner1 : 0x00");
                }
                else
                {
                    printf("There is no message id to win arbitration\n");
                }
            }
        }
        else
        {
            break;
        }
    }
}
