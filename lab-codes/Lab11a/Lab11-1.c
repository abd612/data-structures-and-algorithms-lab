#include <stdio.h>
#include <stdlib.h>
#include "binheap.h"

int main(void)
{
    PriorityQueue H;
    H = Initialize(10);
    int i;
    int array[10];
	
    for(i = 0; i < 10; i++)
        array[i] = 10-i;
	
    for(i = 0; i < 10; i++)
		Insert(array[i], H);
	
	printf("The heap is:\n");
	PrintArray(H);
		
    printf("\nThe maximum value in the heap is %d\n",FindMax(H));
	
	DeleteMax(H);
	
	printf("The modified heap is:\n");
	PrintArray(H);
	
    return 0;
}
