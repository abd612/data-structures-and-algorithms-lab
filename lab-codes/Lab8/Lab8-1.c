#include <stdio.h>
#include "malloc.h"
#include "tree.h"
#include "stackar.h"

int main (void)
{
	SearchTree T;
	T = MakeEmptyT(NULL);
	
	int array[] = {8, 9, 4, 3, 11, 22, 1, 5};
	
	int i;
	
	for( i = 0; i < 8; i++)
        T = Insert( array[i], T );
	
	printf("Ascending Order:\n");
	PrintAscending(T);
	printf("\n\nDescending Order:\n");
	PrintDescending(T);
	printf("\n\nMixed Order:\n");
	PrintMixed(T);
	
	return 0;
}