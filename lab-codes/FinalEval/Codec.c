       #include "fatal.h"
       #include "codec.h"
       #include <stdlib.h>

       #define MinTableSize (5)

        struct ListNode
        {
            ElementType Element;
            Position    Next;
        };

        typedef Position List;

        /* List *TheList will be an array of lists, allocated later */
        /* The lists use headers (for simplicity), */
        /* though this wastes space */
        struct HashTbl
        {
            int TableSize;
            List *TheLists;
        };

        /* Return next prime; assume N >= 10 */
        static int
        NextPrime( int N )
        {
            int i;

            if( N % 2 == 0 )
                N++;
            for( ; ; N += 2 )
            {
                for( i = 3; i * i <= N; i += 2 )
                    if( N % i == 0 )
                        goto ContOuter;  /* Sorry about this! */
                return N;
              ContOuter: ;
            }
        }

        /* Hash function for ints */
        Index
        Hash( ElementType Key, int TableSize )
        {
            return Key % TableSize;
        }

/* START: fig5_8.txt */
        HashTable
        InitializeTable( int TableSize )
        {
            HashTable H;
            int i;

/* 1*/      if( TableSize < MinTableSize )
            {
/* 2*/          Error( "Table size too small" );
/* 3*/          return NULL;
            }

            /* Allocate table */
/* 4*/      H = malloc( sizeof( struct HashTbl ) );
/* 5*/      if( H == NULL )
/* 6*/          FatalError( "Out of space!!!" );

/* 7*/      H->TableSize = NextPrime( TableSize );

            /* Allocate array of lists */
/* 8*/      H->TheLists = malloc( sizeof( List ) * H->TableSize );
/* 9*/      if( H->TheLists == NULL )
/*10*/          FatalError( "Out of space!!!" );

            /* Allocate list headers */
/*11*/      for( i = 0; i < H->TableSize; i++ )
            {
/*12*/          H->TheLists[ i ] = malloc( sizeof( struct ListNode ) );
/*13*/          if( H->TheLists[ i ] == NULL )
/*14*/              FatalError( "Out of space!!!" );
                else
/*15*/              H->TheLists[ i ]->Next = NULL;
            }

/*16*/      return H;
        }
/* END */

/* START: fig5_9.txt */
        Position
        Find( ElementType Key, HashTable H )
        {
            Position P;
            List L;

/* 1*/      L = H->TheLists[ Hash( Key, H->TableSize ) ];
/* 2*/      P = L->Next;
/* 3*/      while( P != NULL && P->Element != Key )
                                /* Probably need strcmp!! */
/* 4*/          P = P->Next;
/* 5*/      return P;
        }
/* END */

/* START: fig5_10.txt */
        void
        Insert( ElementType Key, HashTable H )
        {
            Position Pos, NewCell;
            List L;

/* 1*/      Pos = Find( Key, H );
/* 2*/      if( Pos == NULL )   /* Key is not found */
            {
/* 3*/          NewCell = malloc( sizeof( struct ListNode ) );
/* 4*/          if( NewCell == NULL )
/* 5*/              FatalError( "Out of space!!!" );
                else
                {
/* 6*/              L = H->TheLists[ Hash( Key, H->TableSize ) ];
/* 7*/              NewCell->Next = L->Next;
/* 8*/              NewCell->Element = Key;  /* Probably need strcpy! */
/* 9*/              L->Next = NewCell;
                }
            }
        }
/* END */

        ElementType
        Retrieve( Position P )
        {
            return P->Element;
        }

        void
        DestroyTable( HashTable H )
        {
            int i;

            for( i = 0; i < H->TableSize; i++ )
            {
                Position P = H->TheLists[ i ];
                Position Tmp;

                while( P != NULL )
                {
                    Tmp = P->Next;
                    free( P );
                    P = Tmp;
                }
            }

            free( H->TheLists );
            free( H );
        }
		void
			PrintHash(HashTable H)
		{
			int i;
			Position P;
			for(i=0; i<H->TableSize;i++)
			{
				P=H->TheLists[i]->Next;
				while(P!=NULL)
				{
					printf("%d\t",P->Element );
					P=P->Next;
				}
				puts("");
			}
		}
		
		void PrintS(HashTable H) {
		    int i;
			for ( i = 0; i < H->TableSize; i++) {
				printf("Index %d:\t",i);
				PrintListS(H->TheLists[i]);
				puts("");
			}
		}
		void PrintListS(List L) {

			Position P = L->Next;
			if (P != NULL) {
				for (; P != NULL; P = P->Next)
				{
					printf("%d\t", P->Element);
				}
			}
			else {
				printf("Empty");
			}
		}

		void Make_Disjoint(HashTable temp1, HashTable temp2)
		{
			puts("Set_1");
			PrintS(temp1);
			puts("\nSet_2");
			PrintS(temp2);

			int Duplicates[10];
			Position P1, P2, P, TmpCell;
			int i, val, dup = 0;
			
			for(i = 0; i < temp1->TableSize; i++)
			{
				P1 = temp1->TheLists[i]->Next;
				
				while(P1 != NULL)
				{
					val = P1->Element;
					P2 = temp2->TheLists[i];
					P = P2;
					P2 = P2->Next;
					
					while(P2 != NULL)
					{
					if(val == Retrieve(P2))
					{
					Duplicates[dup++] = val;
					
					if( P != NULL )  
					{                     
					TmpCell = P->Next;
					P->Next = TmpCell->Next; 
					free( TmpCell );
					}
					}
					P = P2;
					P2 = P2->Next;
					}

					P1 = P1->Next;
				}
			}

			printf("\nNumber of duplicate elements: %d\n", dup);
			for(i=dup-1; i>=0; i--)
				printf("%d\t", Duplicates[i] );

			puts("\n\nSet_2 after making disjoint:");
			PrintS(temp2);


		}