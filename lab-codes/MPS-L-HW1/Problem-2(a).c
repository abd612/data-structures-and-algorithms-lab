#include <stdio.h>

#define MINIMIUM2(a, b) a < b ? a : b

int main (void)
{
	int x, y;
	
	x = 15;
	y = 12;
	
	printf ("Minimum of %d and %d is: %d\n", x, y, MINIMIUM2 (x, y));
	
	x = 27;
	y = 55;
	
	printf ("\nMinimum of %d and %d is: %d\n", x, y, MINIMIUM2 (x, y));
	
	return 0;
}