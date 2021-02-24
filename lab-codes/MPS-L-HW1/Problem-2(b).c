#include <stdio.h>

#define MINIMIUM2(a, b) a < b ? a : b
#define MINIMIUM3(a, b, c) a < b ? MINIMIUM2(a, c) : MINIMIUM2(b, c)

int main (void)
{
	int x, y, z;
	
	printf ("Enter three numbers:\n");
	scanf ("%d %d %d", &x, &y, &z);
	
	printf ("\nMinimum of %d, %d, %d is: %d\n", x, y, z, MINIMIUM3 (x, y, z));
	
	return 0;
}