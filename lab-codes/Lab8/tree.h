        typedef char ElementTypeT;

/* START: fig4_16.txt */
        #ifndef _Tree_H
        #define _Tree_H

        struct TreeNode;
        typedef struct TreeNode *Position;
        typedef struct TreeNode *SearchTree;

        SearchTree MakeEmptyT( SearchTree T );
        Position Find( ElementTypeT X, SearchTree T );
        Position FindMin( SearchTree T );
        Position FindMax( SearchTree T );
        SearchTree Insert( ElementTypeT X, SearchTree T );
        SearchTree Delete( ElementTypeT X, SearchTree T );
        ElementTypeT Retrieve( Position P );
		SearchTree MergeOperands(SearchTree T1, SearchTree T2, char c);
		void PrintPostOrder(SearchTree T);
		void PrintInOrder(SearchTree T);
		void PrintPreOrder(SearchTree T);

        #endif  /* _Tree_H */

/* END */
