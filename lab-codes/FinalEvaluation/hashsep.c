       #include "fatal.h"
       #include "hashsep.h"
       #include <stdlib.h>

       #define MinTableSize (5)
		#define SIZE 6
        struct ListNode
        {
            ElementType Element;
            Position1    Next;
        };

        typedef Position1 List;

        /* List *TheList will be an array of lists, allocated later */
        /* The lists use headers (for simplicity), */
        /* though this wastes space */
        struct HashTbl
        {
            int TableSize;
            List *TheLists;
			int dup[10];
			int array[];
        };

        /* Return next prime; assume N >= 10 */
        static int
        NextPrimesep( int N )
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
        Hashsep( ElementType Key, int TableSize )
        {
            return Key % TableSize;
        }

/* START: fig5_8.txt */
        HashTable
        InitializeTableS( int TableSize )
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

/* 7*/      H->TableSize = NextPrimesep( TableSize );

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
        Position1
        FindS( ElementType Key, HashTable H )
        {
            Position1 P;
            List L;

/* 1*/      L = H->TheLists[ Hashsep( Key, H->TableSize ) ];
/* 2*/      P = L->Next;
/* 3*/      while( P != NULL && P->Element != Key )
                                /* Probably need strcmp!! */
/* 4*/          P = P->Next;
/* 5*/      return P;
        }
/* END */

/* START: fig5_10.txt */
        void
        InsertS( ElementType Key, HashTable H )
        {
            Position1 Pos, NewCell;
            List L;

/* 1*/      Pos = FindS( Key, H );
/* 2*/      if( Pos == NULL )   /* Key is not found */
            {
/* 3*/          NewCell = malloc( sizeof( struct ListNode ) );
/* 4*/          if( NewCell == NULL )
/* 5*/              FatalError( "Out of space!!!" );
                else
                {
/* 6*/              L = H->TheLists[ Hashsep( Key, H->TableSize ) ];
/* 7*/              NewCell->Next = L->Next;
/* 8*/              NewCell->Element = Key;  /* Probably need strcpy! */
/* 9*/              L->Next = NewCell;
                }
            }
        }
/* END */

        ElementType
        RetrieveS( Position1 P )
        {
            return P->Element;
        }

        DestroyTableS( HashTable H )
        {
            int i;

            for( i = 0; i < H->TableSize; i++ )
            {
                Position1 P = H->TheLists[ i ];
                Position1 Tmp;

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
		void PrintS(HashTable H) {
		    int i;
			for ( i = 0; i < H->TableSize; i++) {
				printf("Index %d:\t",i);
				PrintListS(H->TheLists[i]);
				puts("");
			}
		}
		void PrintListS(List L) {

			Position1 P = L->Next;
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
		int CollisionsS(HashTable H) {
			int coll = 0, i = 0;
			int j;
			for ( j = 0; j < H->TableSize; j++) {
				i = length(H->TheLists[j]);
				if (i > 1) {
					coll+=i-1;
				}

			}
			return coll;

		}

		int length(List L) {
			int l = 0;
			Position1 P = L->Next;
			if(P != NULL) {
				while (P != NULL) {

					l++;
					P = P->Next;
				}

			}
			return l;
		}
	
		//int array[30];
		int k;
		void TraverseS(HashTable H) {
		    int i;
			for ( i = 0; i < H->TableSize; i++) {
				TraverseListS(H->TheLists[i], H);
			}
			
			//printf("Array:\n");
			//for (i = 0; i < 6; i++)
			//	printf("%d\t", H->array[i]);
		}
		
		void TraverseListS(List L, HashTable H) {

			Position1 P = L->Next;
			if (P != NULL) {
				for (; P != NULL; P = P->Next)
				{
					H->array[k++] = P->Element;
				}
			}
		}
		
		void Duplicate(HashTable H1, HashTable H2)
		{
			int i, j = 0;
			
			printf("\nDuplicate Elements:\n");
			for (i = 0; i < SIZE; i++)
				if (FindS(H1->array[i], H2) != NULL)
				{
					printf("%d\t", H1->array[i]);
					H1->dup[j++] = H1->array[i];
				}
				
			printf("\nNumber of duplicate elements: %d\n", j);
		}
		
		HashTable Convert (HashTable H1, HashTable H2)
		{
			HashTable H3;
			H3 = InitializeTableS(5);
			int i, j;
			//TraverseS(H1);
			//TraverseS(H2);
			for (i = 0; i < SIZE; i++)
				for (j = 0; j < 3; j++)
					if (H1->array[i] != H1->dup[j])
						InsertS(H1->array[i], H3);
			
			Print(H3);
			
			puts(" ");
			for (i = 0; i < SIZE; i++)
				printf("%d ", H1->array[i]);
			puts(" ");
			for (i = 0; i < 3; i++)
				printf("%d ", H1->dup[i]);
			puts(" ");
			
			return H3;
		}

