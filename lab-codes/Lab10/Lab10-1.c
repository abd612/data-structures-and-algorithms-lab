#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int n;
	printf("Enter the number of elements:\n");
	scanf("%d", &n);
	
	int a[n];
	int i;

	if (n <= 10)
	{
		printf("Enter the elements one by one:\n");
		for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	}
	
	else
		for(i = 0; i < n; i++)
			a[i] = (rand() % n);
	
	int x;
	printf("Enter the key element:\n");
	scanf("%d", &x);
	
	clock_t start1, end1, start2, end2, start3, end3;
	double run_time1, run_time2, run_time3;
	
	start1 = clock ();
	InsertionSort(a, n);
	end1 = clock ();
	run_time1 = (end1 - start1) / ((double) CLOCKS_PER_SEC);
	printf ("The run time of Insertion Sort is %d s\n", run_time1);
	
	start2 = clock ();
	Shellsort(a, n);
	end2 = clock ();
	run_time2 = (end2 - start2) / ((double) CLOCKS_PER_SEC);
	printf ("The run time of Shell Sort is %d s\n", run_time2);
	
	printf("Sorted elements:\n");
	for(i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
	
	start3 = clock ();	
	printf ("Required pairs:\n");
	int j, k = 0;
	for (i = 0; i < n - 1; i++)
		for (j = (i+1); j < n; j++)
			if ((a[i] + a[j]) == x)
				printf ("Pair #%d: %d + %d = %d\n", ++k, a[i], a[j], x);
	
	if (k == 0)
		printf("No pairs found!\n");
		
	end3 = clock ();
	
	run_time3 = (end3 - start3) / ((double) CLOCKS_PER_SEC);
	printf ("The run time of our function is %d s\n", run_time3);
	
	return 0;
}