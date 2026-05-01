/*
*******************************************************************************************************
                                        Week_8_post-workshop_task_description
*******************************************************************************************************
The main() function of the following C program calls a user-defined function filter_ascending()
utilizing the following input arguments:
1. A pointer to the first node of a linked list containing nodes of type struct node 
2. The count of nodes in the linked list

The function filters the nodes within the linked list in ascending order by deleting the nodes that 
do not meet this requirement.

For example:

If the original linked list passed into the filter_ascending() function is:
10->2->3->1->17->25->7->8->35->NULL

The modified linked list after executing the function should be as follows:
10->17->25->35->NULL

1. The definition of the function filter_ascending() is however missing two lines of code. You must 
write these two missing lines of code within the function definition and verify that the program
provides the correct output utilizing your own test cases. 

2. In the process of correcting the program, you are allowed to only add the missing two lines of code 
within the definition of the filter_ascending() function. In case the program is subjected to any 
other changes, no marks will be awarded.

2. You are required to submit your solution as a single .c file with the name <studentID>.c such that 
<studentID> is replaced with your unique student ID, for example 12345678.c. Note that a penalty will 
apply for not following these instructions or the naming conventions.
*******************************************************************************************************
*/

#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node* nextPtr;
};

void filter_ascending(struct node *startPtr, int count_nodes);

int main()
{
	struct node* startPtr = NULL;
	struct node* curPtr = NULL;
	struct node* printPtr = NULL;
	int temp = 0;
    int i = 0;
	printf("Enter the value of the new data member (-99 to terminate): \n");
	scanf("%d", &temp);
	for (i = 0; temp != -99; i++)
	{
		if (startPtr == NULL)
		{
			startPtr = (struct node*)malloc(sizeof(struct node));
			startPtr->data = temp;
			startPtr->nextPtr = NULL;
			curPtr = startPtr;
		}
		else
		{
			curPtr->nextPtr = (struct node*)malloc(sizeof(struct node));
			curPtr->nextPtr->data = temp;
			curPtr->nextPtr->nextPtr = NULL;
			curPtr = curPtr->nextPtr;
		}
		scanf("%d", &temp);
	}
    printf("Original linked list:\n");
	printPtr = startPtr;
	while (printPtr != NULL)
	{
		printf("%d->", printPtr->data);
		printPtr = printPtr->nextPtr;
	}
	printf("NULL\n");

    filter_ascending(startPtr,i);

    printf("Modified linked list:\n");
    printPtr = startPtr;
	while (printPtr != NULL)
	{
		printf("%d->", printPtr->data);
		printPtr = printPtr->nextPtr;
	}
	printf("NULL\n");
	return 0;
}

void filter_ascending(struct node *startPtr, int count_nodes)
{
    struct node* prevPtr = NULL;
    struct node* curPtr = NULL;
	prevPtr = startPtr;
	curPtr = startPtr->nextPtr;
    for (int i = 0; i < count_nodes; i++)
    {
        while (curPtr != NULL)
        {
            if (prevPtr->data > curPtr->data)
            {
                prevPtr->nextPtr = curPtr->nextPtr;
                free(curPtr);
				curPtr = prevPtr->nextPtr;
				continue;
			}
            prevPtr = prevPtr->nextPtr; 
            curPtr = prevPtr->nextPtr;
        }
    }
}