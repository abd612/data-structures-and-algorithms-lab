#include <stdio.h>
#include "list.h"

List Union_of_List (List L1, List L2);
List Intersection_of_List (List L1, List L2);

void
PrintList( const List L )
{
    Position P = Header( L );

    if( IsEmpty( L ) )
        printf( "Empty list\n" );
    else
    {
        do
        {
            P = Advance( P );
            printf( "%d ", Retrieve( P ) );
        } while( !IsLast( P, L ) );
        printf( "\n" );
    }
}

int main (void)
{
	int Array1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int Array2[] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
 
    List L1, L2;
    Position P1, P2;
    int i, j;

    L1 = MakeEmpty( NULL );
	L2 = MakeEmpty( NULL );
	
    P1 = Header( L1 );
	P2 = Header( L2 );

    for( i = 0; i < 10; i++ )
    {
        Insert( Array1[i], L1, P1 );
        P1 = Advance( P1 );
    }
	
	printf("List1:\n");
    PrintList( L1 );
	
	for( j = 0; j < 10; j++ )
    {
        Insert( Array2[j], L2, P2 );
        P2 = Advance( P2 );
    }
	
	printf("\nList2:\n");
	PrintList( L2 );

	printf("\nUnion:\n");
	PrintList(Union_of_List (L1, L2));
	printf("\nIntersection:\n");
	PrintList(Intersection_of_List (L1, L2));
	
    DeleteList( L1 );
	DeleteList( L2 );
	
    return 0;
}

List Union_of_List (List L1, List L2)
{
	List L3;
	Position P3;

    L3 = MakeEmpty( NULL );
    P3 = Header( L3 );
	
	Position P1 = Header( L1 );
	Position P2 = Header( L2 );
	
	while (Advance (P1) != NULL)
	{
		P1 = Advance( P1 );
		Insert( Retrieve ( P1 ), L3, P3);
		P3 = Advance( P3 );
	}
	
	while(Advance (P2) != NULL)
	{
		P2 = Advance( P2 );
		if (Find (Retrieve( P2 ), L3) == NULL)
		{
			Insert( Retrieve ( P2 ), L3, P3);
			P3 = Advance( P3 );
		}
	}
	
	return L3;
}

List Intersection_of_List (List L1, List L2)
{
	List L3;
	Position P3;

    L3 = MakeEmpty( NULL );
    P3 = Header( L3 );
	
	Position P2 = Header( L2 );
	
	while(Advance (P2) != NULL)
	{
		P2 = Advance( P2 );
		if (Find (Retrieve( P2 ), L1) != NULL)
		{
			Insert( Retrieve ( P2 ), L3, P3);
			P3 = Advance( P3 );
		}
	}
	
	return L3;
}
