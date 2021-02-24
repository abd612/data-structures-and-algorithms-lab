#include <stdio.h>
#include "tree.h"
#include "stackar.h"

SearchTree MergeOperands(SearchTree T1, SearchTree T2, char c);
PrintPostOrder(SearchTree T);
PrintInOrder(SearchTree T);
PrintPreOrder(SearchTree T);

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
			temp MakeEmptyT(NULL);
			Insert(expression[i], temp);
			Push(temp, S);
		}
		
		else
		{
			SearchTree Operand2;
			Operand2 = MakeEmpty(NULL);
			Operand2 = TopAndPop(S);
			
			SearchTree Operand1;
			Operand1 = MakeEmpty(NULL);
			Operand1 = TopAndPop(S);
		
			Push(MergeOperands(Operand1, Operand2, expression[i]), S);
		}
		i++;
	}
	
	SearchTree finaltree;
	finaltree = MakeEmpty(NULL);
	finaltree = TopAndPop(S);
	
	PrintPostOrder(finaltree);
	PrintInOrder(finaltree);
	PrintPreOrder(finaltree);
	
	DisposeStack(S);
	MakeEmptyT(finaltree);
	
	return 0;
}

SearchTree MergeOperands(SearchTree T1, SearchTree T2, char c);
{
	SearchTree T;
	T = MakeEmpty(NULL);
	T = TopAndPop(S);
	T->Element = c;
	T->Left = T1;
	T->Right = T2;
	
	return T;
}

PrintPostOrder(SearchTree T)
{
	if (T != NULL)
	{
		PrintPostOrder(T->Left);
		PrintPostOrder(T->Right);
		printf ("%c", T->Element);
	}
}

PrintInOrder(SearchTree T)
{
	if (T != NULL)
	{
		PrintInOrder(T->Left);
		printf ("%c", T->Element);
		PrintInOrder(T->Right);
	}
}

PrintPreOrder(SearchTree T)
{
	if (T != NULL)
	{
		printf ("%c", T->Element);
		PrintPreOrder(T->Left);
		PrintPreOrder(T->Right);
	}
}

/*PrintPostOrder(SearchTree T)
{
	do
	{
		while (T->Left != NULL)
		{
			T = T->Left;
		}
		printf("%c", T->Element);
		
		T = T->Right;
	}
	while (T->Right != NULL)
		
	printf("%c", T->Element);
	
}
PrintInOrder(SearchTree T);*/