#include <stdio.h>

#define SIZE 10

void sorting (int *arayPtr);

int main (void)
{
	int i, array[SIZE] = {3, 5, 2, 9, 1, 10, 6, 8, 7, 4};
	
	printf ("Unsorted array:\n");
	for (i = 0; i < SIZE; i++)
		printf("%4d", array[i]);
		
	sorting (array);
	
	printf ("\n\nSorted array:\n");
	for (i = 0; i < SIZE; i++)
		printf("%4d", array[i]);
		
	puts ("");
	
		return 0;
}

void sorting (int *arrayPtr)
{
	int i, j, temp;
	
	for (i = 0; i < SIZE - 1; i++)
	{
		for (j = 0; j < SIZE - 1; j++)
		{
			if (arrayPtr[j] > arrayPtr[j + 1])
			{
				temp = arrayPtr[j];
				arrayPtr[j] = arrayPtr[j + 1];
				arrayPtr[j + 1] = temp;
			}
		}
	}
}