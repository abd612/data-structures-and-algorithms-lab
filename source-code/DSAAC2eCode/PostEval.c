#include <stdio.h>
#include "stackli.h"

int main (void)
{
	stk = CreateStack();
	
	char arr[] = "ab+cd-*";
	
	int x, y;
	
	while (arr[i] != '\0')
	{
		if (arr[i] != '+' && arr[i] != '-' && arr[i] != '*' && arr[i] != '/')
		{
			Push(Value(arr[i]), stk);
		}
		
		else
		{
			x = Value(Top(stk));
			Pop(stk);
			y = Value(Top(stk));
			Pop(stk);
			
			switch (arr[i])
			{
				case '+': Push(x+y, stk);
				case '-': Push(x-y, stk);
				case '*': Push(x*y, stk);
				case '/': Push(x/y, stk);
			}
		}
	}
	
	printf("Answer: %d\n", Top(stk));
	
	return 0;
}

int Value (char c)
{
	switch (c)
	{
		case 'a': return 2;
		case 'b': return 3;
		case 'c': return 4;
		case 'd': return 5;
		default: return 0;
	}
}