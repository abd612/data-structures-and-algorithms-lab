#include <stdio.h>
#include "list.h"

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
            printf( "%c ", Retrieve( P ) );
        } while( !IsLast( P, L ) );
        printf( "\n" );
    }
}

main( )
{
    List L;
    Position P;
    int i;

    L = MakeEmpty( NULL );
    P = Header( L );
    PrintList( L );

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
