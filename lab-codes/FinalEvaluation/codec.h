/* Interface for separate chaining hash table */
typedef int ElementType;

/* START: fig5_2.txt */
        typedef unsigned int Index;
/* END */

/* START: fig5_7.txt */
        #ifndef _HashSep_H
        #define _HashSep_H

        struct ListNode;
        typedef struct ListNode *Position;
        struct HashTbl;
        typedef struct HashTbl *HashTable;

        HashTable InitializeTable( int TableSize );
        void DestroyTable( HashTable H );
        Position Find( ElementType Key, HashTable H );
        void Insert( ElementType Key, HashTable H );
        ElementType Retrieve( Position P );
		void
			PrintHash(HashTable H);
		void Make_Disjoint(HashTable h1,HashTable h2);
        /* Routines such as Delete are MakeEmpty are omitted */

        #endif  /* _HashSep_H */
/* END */
