#include "codec.h"
#include <stdio.h>

#define SIZE 6

int main( void )
{
    HashTable H1, H2;
	int i;
	
	H1 = InitializeTable(5);
	H2 = InitializeTable(5);
	
	int Set_1[] = {23, 24, 25, 27, 29, 34};
	int Set_2[] = {26, 31, 34, 23, 25, 33};
	
	for (i = 0; i < SIZE; i++)
		Insert(Set_1[i], H1);

	for (i = 0; i < SIZE; i++)
		Insert(Set_2[i], H2);
	
	Make_Disjoint(H1, H2);
	
	return 0;
}