#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Stacks
# Problem Statement	: check parenthesis 
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

struct SLL
{
	char data;
	struct SLL *next;
};

struct SLL *newNode(char data)
{
	
	struct SLL *node = (struct SLL *)malloc(sizeof(struct SLL));
	if (!node)
		return NULL;
	node->data = data;
	node->next  = NULL;
	
	return node;
}

void push(struct SLL **s, char data)
{
	struct SLL *temp = newNode(data);
	temp->next = *s;
	*s= temp;
	
}
int isEmpty(struct SLL *s)
{
	return s==NULL;
	
}
char pop(struct SLL **s)
{
	struct SLL *node;
	char ch;
	if(isEmpty(*s))
	{printf("% empty \n");
		return '\0';}
	node = *s;
	*s= (*s)->next;
	ch = node->data;
	free(node);
	return ch;
	
}

int isBalanced(char *str)

{
	struct SLL *top=NULL;
	while(*str != '\0')
	{
		if( (*str == '}' || *str == ')' || *str == ']'))
		{
			if(isEmpty(top))
				return 0;
			
		char ch = top->data;
		pop(&top);
		printf(" 1:: %c %c \n",ch , *str);
		if((*str =='}' && ch == '{') || (*str==')' && ch == '(') || (*str==']' && ch == '[') )
			{
				str++;
				continue;
			}
		else
		{
			return 0;
		}
		}		
		if(*str == '{' || *str == '(' || *str == '[')
			{
				
				push(&top, *str);
				//printf("fsfdf");
				if(!isEmpty(top))
					printf(" 2:: %c \n",top->data);
				str++;
			}
		else
			
			{
				str++;
				
				
				}
		
	}
	
	
	if(!isEmpty(top))
	{
		//printf("3::%c \n",top->data);
		return 0;
		}
	
	return 1;
}


int main()
	{
	
	char *str="{(){}-A-[X-Y*(I+2)]-F}";
	
	char *str1="{(A+(B-O)*{A*B}-A)-[X-Y*(I+2)-F}";
	
	if(isBalanced(str))
			printf("Exp: %s Balanced\n",str);
	else
			printf("Exp: %s Not Balanced\n",str);
		
	if(isBalanced(str1))
			printf("Exp: %s Balanced\n",str1);
	else
			printf("Exp: %s Not Balanced\n",str1);
	return 0;
	}