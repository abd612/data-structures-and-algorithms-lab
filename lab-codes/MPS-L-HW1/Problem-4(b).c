#include <stdio.h>
#include <ctype.h>

#define SIZE 80

int main (void)
{
	char string[SIZE];
	
	int i, vowels = 0, consonants = 0, digits = 0, spaces = 0, others = 0, total = 0;
	
	printf ("Enter a string:\n");
	fgets (string, SIZE, stdin);
	
	for (i = 0; string[i] != '\0'; i++)
	{
		if (isalpha(string[i]))
		{
			switch (tolower(string[i]))
			{
				case 'a': case 'e': case 'i':
				case 'o': case 'u':
					vowels++;
					break;
					
				default:
					consonants++;
			}
		}
		
		if (isdigit(string[i]))
			digits++;
			
		if (isspace(string[i]))
			spaces++;
		
		if (ispunct(string[i]))
			others++;
			
		total++;
	}
		printf ("\nVowels: %d\n", vowels);
		printf ("Consonants: %d\n", consonants);
		printf ("Digits: %d\n", digits);
		printf ("Whitespace characters: %d\n", spaces);
		printf ("Other characters: %d\n", others);
		printf ("Total characters: %d\n", total);
		
		return 0;
}