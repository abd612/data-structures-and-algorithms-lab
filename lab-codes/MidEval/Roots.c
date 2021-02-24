/* This code doesn't really do much */
/* Thus I haven't bothered testing it */

#include "fatal.h"
#include <stdio.h>

static int
Max( int A, int B )
{
    return A > B ? A : B;
}

/* START: fig3_23.txt */
        typedef struct Node *Position;

        struct Node
        {
            int Coefficient;
            int Exponent;
            Position Next;
        };

        typedef Position Polynomial;  /* Nodes sorted by exponent */
/* END */

void
        Insert( int X, int N, Polynomial L, Position P )
        {
            Position TmpCell;

/* 1*/      TmpCell = malloc( sizeof( struct Node ) );
/* 2*/      if( TmpCell == NULL )
/* 3*/          FatalError( "Out of space!!!" );

/* 4*/      TmpCell->Coefficient = X;
			TmpCell->Exponent = N;
/* 5*/      TmpCell->Next = P->Next;
/* 6*/      P->Next = TmpCell;
        }
		
		Polynomial
        MakeEmpty( Polynomial L )
        {
            if( L != NULL )
                DeleteList( L );
            L = malloc( sizeof( struct Node ) );
            if( L == NULL )
                FatalError( "Out of memory!" );
            L->Next = NULL;
            return L;
        }
		
		int IsLast( Position P, Polynomial L )
        {
            return P->Next == NULL;
        }

		Position
        Header( Polynomial L )
        {
            return L;
        }

        Position
        First( Polynomial L )
        {
            return L->Next;
        }

        Position
        Advance( Position P )
        {
            return P->Next;
        }

        int
        RetrieveCoefficient( Position P )
        {
            return P->Coefficient;
        }
		
		int
        RetrieveExponent( Position P )
        {
            return P->Exponent;
        }

void
PrintPoly( const Polynomial L )
{
    Position P = Header( L );

    if( IsEmpty( L ) )
        printf( "Empty list\n" );
    else
    {
		P = Advance( P );
		printf( "%d + ", RetrieveCoefficient( P ));
        do
        {
            P = Advance( P );
            printf( "%dx^%d + ", RetrieveCoefficient( P ), RetrieveExponent( P ) );
        } while( !IsLast( P, L ) );
        printf( "\n" );
    }
}

main( )
{
    Polynomial L;
    Position P;
    int i;

    L = MakeEmpty( NULL );
    P = Header( L );
    PrintPoly( L );

	char array[] = {"Muhammad Abdullah"};
	
    for( i = 0; array[i] != '\0'; i++ )
    {
        Insert( array[i], L, P );
        PrintList( L );
        P = Advance( P );
    }
	
    DeleteList( L );

    return 0;
}
