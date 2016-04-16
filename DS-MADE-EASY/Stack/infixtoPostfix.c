#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Stacks
# Problem Statement	: infix to Postfix
# Description		: if its an operand print it, if it is operator check stack pop until find a low priority operator and  then push it.
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
struct SLL *newNode(char data)
{
	struct SLL *node= (struct SLL *)malloc(sizeof(struct SLL));
	if(!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	return node;
	
}
void push(struct SLL **s, char data)
{
	struct SLL *node = newNode(data);
	node->next = *s;
	*s =node;
	
}

int isEmpty(struct SLL *s)
{
	
	return s==NULL;
	//return s==NULL;
	
}
char pop(struct SLL **s)
{
	if(isEmpty(*s))
		return '\0';
	
	char ch = (*s)->data;
	
	struct SLL *node = *s;
	*s = (*s)->next;
	free(node);
	return ch;
	
	
}
void printPostFix(char str[])
{
	
	int i=0;
	struct SLL *S=NULL;
	
	while(str[i] !='\0' )
	{
		if((str[i] >=65 && str[i]<=90) || (str[i] >=97 && str[i]<=122))
			printf("%c",str[i]);
		else if( str[i] == ')')
		{
			while(!isEmpty(S))
			{
				char data = pop(&S);
				printf("%c",data);
			}
		}
		else
		{
			if(str[i]=='*' || str[i]=='+' || str[i] == '-' || str[i] == '(')
			{
				while(!isEmpty(S) &&  S->data !='(')
				{char d = pop(&S);
					printf("%c",d);}
				push(&S, str[i]);
			}
			
			
		}
		i++;
	}
	
	while( !isEmpty(S))
				{char d = pop(&S);
					printf("%c",d);}
	
	
}

int main()
	{
	
		char str[] = "A*B-(c+D)+E";
		printPostFix(str);
	
	return 0;
	}