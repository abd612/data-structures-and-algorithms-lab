#include "hashsep.h"
#include "hashquad.h"
#include <stdio.h>

int main( void )
{
    HashTable H1, H2, H3;
    int CurrentSize;

	H1 = InitializeTableS(CurrentSize = 11);

	InsertS(1, H1);
	InsertS(2, H1);
	InsertS(3, H1);
	InsertS(11, H1);
	InsertS(12, H1);
	InsertS(13, H1);

	printf("** Seperate Chaining **\n");
	PrintS(H1);
	printf("Total Collisions:\t%d\n", CollisionsS(H1));
	
	H2 = InitializeTable(CurrentSize = 11);

	InsertLin(1, H2);
	InsertLin(2, H2);
	InsertLin(3, H2);
	InsertLin(11, H2);
	InsertLin(12, H2);
	InsertLin(13, H2);

	printf("\n** Linear probing **\n");
 	Print(H2);
	printf("Total Collisions:\t%d\n", Collisions(H2));
	
    H3 = InitializeTable( CurrentSize = 11 );

    Insert(1, H3);
	Insert(2, H3);
	Insert(3, H3);
	Insert(11, H3);
	Insert(12, H3);
	Insert(13, H3);
	
	printf("\n** Quadratic probing **\n");
	Print(H3);
	printf("Total Collisions:\t%d\n", Collisions(H3));

	return 0;
}
