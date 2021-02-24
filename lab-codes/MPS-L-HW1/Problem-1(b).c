#include <stdio.h>
#include <math.h>

#define MAX 5000

int prime (int n);

int main (void)
{
	int i, sum = 0, c = 0;
	
	printf ("Prime numbers upto 5000:\n");
	
	for (i = 2; i <= MAX; i++)
		if (prime(i))
		{
			printf ("%d\t", i);
			c++;
			
			if (c % 7 == 0)
				printf ("\n");
				
			sum += i;
		}
	
	printf ("\n\nSum of prime numbers between 1 and 5000 is: %d\n", sum);
	
	return 0;
}

int prime (int n)
{
	int j;
	
	for (j = 2; j <= (int) sqrt (n); j++)
		if (n % j == 0)
			return 0;
			
	return 1;
}