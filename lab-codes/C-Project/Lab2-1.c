#include <stdio.h>
#include <time.h>

int main (void)
{
    clock_t start, end;
    int i, j;
    int outer_loop_index = 2100;
    int inner_loop_index = 2100;
    double run_time;
    
    start = clock ();
    
    int sumI = 0;
    int sumJ = 0;
    
    for (i = 0; i < outer_loop_index; i++)
    {
        for (j = 0; j < inner_loop_index; j++)
        {
            sumJ += j; 
        }
        
        sumI += i;
    }
    
    printf ("SumI: %d, SumJ: %d\n", sumI, sumJ);
    
    end = clock ();
    
    run_time = (end - start) / ((double) CLOCKS_PER_SEC);
    
    printf ("The run time of the code is %d seconds and %d milliseoconds\n", (int)run_time, ((int)(run_time * 1000) % 1000));
    printf ("The run time of the code is: %g\n", run_time);
    
    return 0;
}