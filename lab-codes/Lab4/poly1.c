/* This code doesn't really do much */
/* Thus I haven't bothered testing it */

#include "fatal.h"
#include "Math.h"

#define MaxDegree 100

static int
Max( int A, int B )
{
    return A > B ? A : B;
}

/* START: fig3_18.txt */
        typedef struct
        {
            int CoeffArray[ MaxDegree + 1 ];
            int HighPower;
        } *Polynomial;
/* END */

/* START: fig3_19.txt */
        void
        ZeroPolynomial( Polynomial Poly )
        {
            int i;

            for( i = 0; i <= MaxDegree; i++ )
                Poly->CoeffArray[ i ] = 0;
            Poly->HighPower = 0;
        }
/* END */

/* START: fig3_20.txt */
        void
        AddPolynomial( const Polynomial Poly1, const Polynomial Poly2,
                       Polynomial PolySum )
        {
            int i;

            ZeroPolynomial( PolySum );
            PolySum->HighPower = Max( Poly1->HighPower,
                                      Poly2->HighPower );

            for( i = PolySum->HighPower; i >= 0; i-- )
                PolySum->CoeffArray[ i ] = Poly1->CoeffArray[ i ]
                                               + Poly2->CoeffArray[ i ];
        }
/* END */

/* START: fig3_21.txt */
        void
        MultPolynomial( const Polynomial Poly1,
                        const Polynomial Poly2, Polynomial PolyProd )
        {
            int i, j;

            ZeroPolynomial( PolyProd );
            PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

            if( PolyProd->HighPower > MaxDegree )
                Error( "Exceeded array size" );
            else
                for( i = 0; i <= Poly1->HighPower; i++ )
                    for( j = 0; j <= Poly2->HighPower; j++ )
                        PolyProd->CoeffArray[ i + j ] +=
                                Poly1->CoeffArray[ i ] *
                                Poly2->CoeffArray[ j ];
        }
/* END */

#if 0
/* START: fig3_23.txt */
        typedef struct Node *PtrToNode;

        struct Node
        {
            int Coefficient;
            int Exponent;
            PtrToNode Next;
        };

        typedef PtrToNode Polynomial;  /* Nodes sorted by exponent */
/* END */
#endif

void
PrintPoly( const Polynomial Q )
{
    int i;

    for( i = Q->HighPower; i > 0; i-- )
        printf( "%dx^%d + ", Q->CoeffArray[ i ], i );
    printf( "%d\n", Q->CoeffArray[ 0 ] );
}

Polynomial polypowerN (const Polynomial P, int N)
{
	Polynomial PolyResult;
	PolyResult = malloc(sizeof (*PolyResult));
	Polynomial PolyResult1;
	PolyResult1 = malloc(sizeof (*PolyResult1));
	
	if (N == 0)
	{
		ZeroPolynomial(P);
		P->CoeffArray[ 0 ] = 1;
		return P;
	}
		
	if (N == 1)
		return P;
		
	else if (N % 2 == 0)
	{
		MultPolynomial(polypowerN(P, N/2), polypowerN(P, N/2), PolyResult);
		return PolyResult;
	}
	
	else
	{
		MultPolynomial(polypowerN(P, N/2), polypowerN(P, N/2), PolyResult);
		MultPolynomial(PolyResult, P, PolyResult1);
		return PolyResult1;
	}
}

int EvalPoly (const Polynomial P, int x)
{
	int i, sum = 0, pow = 1;
	
	for (i = 0; i <= P->HighPower; i++)
	{
		sum += (P->CoeffArray[i] * pow);
		pow *= x;
	}
	
	return sum;
}

int main( void )
{
    Polynomial P, Q;

    P = malloc( sizeof( *P ) );
    Q = malloc( sizeof( *Q ) );

    P->HighPower = 1; P->CoeffArray[ 0 ] = 1; P->CoeffArray[ 1 ] = 1;
	printf("P:\n");
	PrintPoly( P );
	Q = polypowerN(P, 2);
	printf("Q = P ^ 2:\n");
	PrintPoly( Q );
	printf("Value of function Q at X = 2:\n");
	printf("%d", EvalPoly(Q, 2));
	
    return 0;
}
