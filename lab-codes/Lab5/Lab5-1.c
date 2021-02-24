#include <stdio.h>
#include "stackar.h"

void PrintOperator(int op);
int Priority(char c);

int main (void)
{
	Stack operators;
	operators = CreateStack(15);
	
	int i = 0;
	int k = 11;
	
	char *expression = "(a+b)*(c+d)";
	
	while(i<k)
	{
		if(expression[i]!= '(' && expression[i-1]!=')')
			printf("%c", expression[i++]);
			
		if(IsEmpty(operators) || Priority(expression[i])>Top(operators))
			Push(Priority(expression[i]), operators);
		
		else
		{
			if(expression[i]==')')
			{
				while(Top(operators)!=Priority('('))
					PrintOperator(TopAndPop(operators));
				Pop(operators);
			}
			
			else
			{
				while(!IsEmpty(operators) && Priority(expression[i])<=Top(operators) && (Top(operators))!=3)
					PrintOperator(TopAndPop(operators));
				Push(Priority(expression[i]),operators);
			}
		}
		
		i++;
	}
	
	while(!IsEmpty(operators))
		PrintOperator(TopAndPop(operators));
		
	DisposeStack(operators);
	return 0;
}

int Priority(char c)
{
	if(c==')')
		return 0;
	if(c=='+' || c=='-')
		return 1;
	if(c=='*' || c=='/')
		return 2;
	if(c=='(')
		return 3;
	return -1;
}

void PrintOperator(int op)
{
	if(op==1)
		printf("+");
	if(op==2)
		printf("*");
}