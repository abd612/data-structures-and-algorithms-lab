/* Interface for separate chaining hash table */
typedef int ElementType;

/* START: fig5_2.txt */
        typedef unsigned int Index;
/* END */

/* START: fig5_7.txt */
        #ifndef _HashSep_H
        #define _HashSep_H

        struct ListNode;
        typedef struct ListNode *Position1;
        struct HashTbl;
		typedef Position1 List;
        typedef struct HashTbl *HashTable;
		void PrintListS(List L);
		void PrintS(HashTable H);
        HashTable InitializeTableS( int TableSize );
		int CollisionsS(HashTable H);
        void DestroyTableS( HashTable H );
        Position1 FindS( ElementType Key, HashTable H );
        void InsertS( ElementType Key, HashTable H );
        ElementType RetrieveS( Position1 P );
		void TraverseS(HashTable H);
		void TraverseListS(List L, HashTable H);
		void Duplicate(HashTable H1, HashTable H2);
		HashTable Convert (HashTable H1, HashTable H2);
        /* Routines such as Delete are MakeEmpty are omitted */

        #endif  /* _HashSep_H */
/* END */
