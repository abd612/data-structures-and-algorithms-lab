#include <stdio.h>

#define SIZE 80

void reverse (char *stringPtr);

int main (void)
{
	char string[SIZE];
	
	printf ("Enter a string:\n");
	fgets (string, SIZE, stdin);
	
	printf ("\nThe original string:\n%s", string);
	
	printf ("\nThe reversed string:");
	reverse (string);
	puts("");
	
	return 0;
}

void reverse (char *stringPtr)
{
	if (stringPtr[0] == '\0')
		return;
	else
	{
		reverse (&stringPtr[1]);
		putchar (stringPtr[0]);
	}
}