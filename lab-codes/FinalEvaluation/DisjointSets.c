#include "hashsep.h"
#include <stdio.h>

#define SIZE 6
void Make_Disjoint  (HashTable temp1, HashTable temp2);

int main( void )
{
    HashTable H1, H2;
	int i;
	
	H1 = InitializeTableS(5);
	H2 = InitializeTableS(5);
	
	int Set_1[] = {23, 24, 25, 27, 29, 34};
	int Set_2[] = {26, 31, 34, 23, 25, 33};
	
	for (i = 0; i < SIZE; i++)
		InsertS(Set_1[i], H1);

	for (i = 0; i < SIZE; i++)
		InsertS(Set_2[i], H2);
	
	Make_Disjoint(H1, H2);
	
	return 0;
}

void Make_Disjoint  (HashTable temp1, HashTable temp2)
{
	printf("Set_1:\n");
	PrintS(temp1);
	printf("\nSet_2:\n");
	PrintS(temp2);
	
	TraverseS(temp1);
	Duplicate(temp1, temp2);
	
	temp1 = Convert (temp1, temp2);
	
	printf("\n\nSet_1 after making disjoint:\n");
	PrintS(temp1);
}