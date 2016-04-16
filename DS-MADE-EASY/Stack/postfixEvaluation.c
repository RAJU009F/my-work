#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Stacks
# Problem Statement	:  postfix expression evaluation
# Description		: if operand push into stack, if operator if its a unary pop one item and apply operation push result into stack, if binary operation pop two items apply operation push into stask.
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

struct SLL
{
	int data;
	struct SLL *next;
};
void evaluateExp(char exp[])
{
	int i=0;
	struct SLL *S=NULL;
	while(exp[i] != '\0')
	{
		char e = exp[i];
		if(e>=48 && e<=57)
			push(&S,e-48);
		else 
		{
			int a = pop(&S);
			int b = pop(&S);
			a = b (char)e a;
			push(&S,a);
			
		}
		
	i++;	
		
	}
	
	printf("Result: %d\n",pop(S));
}
int main()
	{
	
	char exp[] = "";
	evaluateExp(exp);
	
	return 0;
	}