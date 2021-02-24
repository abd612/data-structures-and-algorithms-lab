#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#define N 1

void delay (int n);

int main (void)
{
    clock_t start, end;
    double run_time;
    
    start = clock ();
    
    delay(N);
    
    end = clock ();
    
    run_time = (end - start) / ((double) CLOCKS_PER_SEC);
    printf ("The run time of the code is: %g\n", run_time);
    
    return 0;
}

void delay (int n)
{
	int i, j, amount;
	
	amount = n * (sqrt(80000000 / 3));
	
	printf("<< Delay of %d second(s) with loop limit %d^2 >>\n", n, amount);
	
	for (i = 0; i < amount; i++)
    {
        for (j = 0; j < amount; j++)
        {
			
        }
    }
}