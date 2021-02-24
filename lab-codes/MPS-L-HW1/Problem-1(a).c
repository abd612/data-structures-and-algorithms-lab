#include <stdio.h>

#define N 50000

int main (void)
{
	int i, x = 1, y = 2, z, sum = 0;
	
	printf ("Fibonacci Sequence upto %d:\n", N);
	
	for(i = 1; x <= N; i++)
	{
		printf ("%d\t", x);
		
		if (i % 10 == 0)
			printf ("\n");
		
		if (x % 2 == 0)
			sum += x;
		
		z = x + y;
		x = y;
		y = z;
	}
	
	printf ("\n\nSum of even terms of Fibonacci Sequence upto %d is: %d\n", N, sum);
	
	return 0;
}