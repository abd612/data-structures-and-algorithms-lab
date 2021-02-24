#include <stdio.h>

#define SIZE 10
#define SUMARRAY(arr, n) for (i = 0; i < n; i++) sum += arr[i];

int main (void)
{
	int i, sum = 0, array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	printf ("Array:\n");
	
	for (i = 0; i < SIZE; i++)
	{
		printf ("%4d", array[i]);
	}
	
	SUMARRAY (array, SIZE);
	
	printf ("\n\nSum of the elements of the array is: %d\n", sum);
	
	return 0;
}