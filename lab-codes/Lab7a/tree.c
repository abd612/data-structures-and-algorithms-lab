        #include "tree.h"
        #include <stdlib.h>
        #include "fatal.h"

        struct TreeNode
        {
            ElementTypeT Element;
            SearchTree  Left;
            SearchTree  Right;
        };

/* START: fig4_17.txt */
        SearchTree
        MakeEmptyT( SearchTree T )
        {
            if( T != NULL )
            {
                MakeEmptyT( T->Left );
                MakeEmptyT( T->Right );
                free( T );
            }
            return NULL;
        }
/* END */

/* START: fig4_18.txt */
        Position
        Find( ElementTypeT X, SearchTree T )
        {
            if( T == NULL )
                return NULL;
            if( X < T->Element )
                return Find( X, T->Left );
            else
            if( X > T->Element )
                return Find( X, T->Right );
            else
                return T;
        }
/* END */

/* START: fig4_19.txt */
        Position
        FindMin( SearchTree T )
        {
            if( T == NULL )
                return NULL;
            else
            if( T->Left == NULL )
                return T;
            else
                return FindMin( T->Left );
        }
/* END */

/* START: fig4_20.txt */
        Position
        FindMax( SearchTree T )
        {
            if( T != NULL )
                while( T->Right != NULL )
                    T = T->Right;

            return T;
        }
/* END */

/* START: fig4_22.txt */
        SearchTree
        Insert( ElementTypeT X, SearchTree T )
        {
/* 1*/      if( T == NULL )
            {
                /* Create and return a one-node tree */
/* 2*/          T = malloc( sizeof( struct TreeNode ) );
/* 3*/          if( T == NULL )
/* 4*/              FatalError( "Out of space!!!" );
                else
                {
/* 5*/              T->Element = X;
/* 6*/              T->Left = T->Right = NULL;
                }
            }
            else
/* 7*/      if( X < T->Element )
/* 8*/          T->Left = Insert( X, T->Left );
            else
/* 9*/      if( X > T->Element )
/*10*/          T->Right = Insert( X, T->Right );
            /* Else X is in the tree already; we'll do nothing */

/*11*/      return T;  /* Do not forget this line!! */
        }
/* END */

/* START: fig4_25.txt */
        SearchTree
        Delete( ElementTypeT X, SearchTree T )
        {
            Position TmpCell;

            if( T == NULL )
                Error( "Element not found" );
            else
            if( X < T->Element )  /* Go left */
                T->Left = Delete( X, T->Left );
            else
            if( X > T->Element )  /* Go right */
                T->Right = Delete( X, T->Right );
            else  /* Found element to be deleted */
            if( T->Left && T->Right )  /* Two children */
            {
                /* Replace with smallest in right subtree */
                TmpCell = FindMin( T->Right );
                T->Element = TmpCell->Element;
                T->Right = Delete( T->Element, T->Right );
            }
            else  /* One or zero children */
            {
                TmpCell = T;
                if( T->Left == NULL ) /* Also handles 0 children */
                    T = T->Right;
                else if( T->Right == NULL )
                    T = T->Left;
                free( TmpCell );
            }

            return T;
        }
/* END */

        ElementTypeT
        Retrieve( Position P )
        {
            return P->Element;
        }
		
SearchTree MergeOperands(SearchTree T1, SearchTree T2, char c)
{
	SearchTree T;
	T = malloc( sizeof( struct TreeNode ) );
	T->Element = c;
	T->Left = T1;
	T->Right = T2;
	
	return T;
}

void PrintPostOrder(SearchTree T)
{
	if (T != NULL)
	{
		PrintPostOrder(T->Left);
		PrintPostOrder(T->Right);
		printf ("%c", T->Element);
	}
}

void PrintInOrder(SearchTree T)
{
	if (T != NULL)
	{
		PrintInOrder(T->Left);
		printf ("%c", T->Element);
		PrintInOrder(T->Right);
	}
}

void PrintPreOrder(SearchTree T)
{
	if (T != NULL)
	{
		printf ("%c", T->Element);
		PrintPreOrder(T->Left);
		PrintPreOrder(T->Right);
	}
}
