#include <stdio.h>
#include "malloc.h"
#include "tree.h"
#include "stackar.h"

int main (void)
{
	Stack S = CreateStack(10);
	char *expression = "a b * c +";
	int i = 0;
	
	while (expression[i] != '\0')
	{
		printf ("%c", expression[i]);
		i++;
	}
	
	i = 0;
	
	while (expression[i] != '\0')
	{
		if (expression[i] == ' ')
		{
			i++;
			continue;
		}
		
		if (expression[i] != '*' && expression[i] != '/' && expression[i] != '+' && expression[i] != '-')
		{
			SearchTree temp;
			temp = MakeEmptyT(NULL);
			temp = Insert(expression[i], temp);
			Push(temp, S);
		}
		
		else
		{
			SearchTree Operand2;
			Operand2 = MakeEmptyT(NULL);
			Operand2 = TopAndPop(S);
			
			SearchTree Operand1;
			Operand1 = MakeEmptyT(NULL);
			Operand1 = TopAndPop(S);
			
			Push(MergeOperands(Operand1, Operand2, expression[i]), S);
		}
		i++;
	}
	
	SearchTree finaltree;
	finaltree = MakeEmptyT(NULL);
	finaltree = TopAndPop(S);
	printf ("\n\nPost Order:\n");
	PrintPostOrder(finaltree);
	printf ("\n\nIn Order\n");
	PrintInOrder(finaltree);
	printf ("\n\nPre Order:\n");
	PrintPreOrder(finaltree);
	printf ("\n");
	DisposeStack(S);
	MakeEmptyT(finaltree);
	
	return 0;
}