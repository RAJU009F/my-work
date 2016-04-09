// Stack implemention using Array:

#include<stdio.h>
#include<stdlib.h>

struct Stack {

	int top;
	int capacity;
	int *a;

};

int isEmpty(struct Stack *);
int isFull(struct Stack *);
struct Stack *createStack();
void push(struct Stack *, int);
void printStack(struct Stack *);
int pop(struct Stack *);
void doubleStack(struct Stack *);
void reverseStack(struct Stack *);
void insertAtBottom(struct Stack *, int);
int main()
	{
		struct Stack *s = createStack();
		int i, ele;
		printf("\ttop : %d \n",s->top);
		printf("\t capacity: %d\n", s->capacity);
		for (i=0; i<6; i++)
			{
			push(s, (i+1)*100);
			}
		printf(" \tStsack Elements\n\n");	
		
		printStack(s);
		reverseStack(s);
		printf(" \tStsack Elements after reverse : \n\n");	
		
		printStack(s);
		
			for (i=0; i<6; i++)
			{
			ele= pop(s);
			printf("\nFD stack:%d\n\n",ele);
			}
		printf(" \tStsack Elements\n\n");	
		printStack(s);
		
		
		return 0;
	}
	
void printStack(struct Stack *s)
		{
		
			if(isEmpty(s))
				return;
			int i= s->top;
			while(i>=0)
				{
					printf("\t[%d]\n",s->a[i--]);
				
				}
		
		}
		
void reverseStack(struct Stack *s)
			{
				if(isEmpty(s))
					return;
				int data = pop(s);
				reverseStack(s);
				insertAtBottom(s, data);		
			
			
			}
			
void insertAtBottom(struct Stack *s, int data)
				{
					if (isEmpty(s))
						{
							push(s, data);
							return;
						}
					int ele = pop(s);
					insertAtBottom(s, data);
					push(s,ele);
				
				
				}
struct Stack *createStack()
	{
		struct  Stack *S;
		S = (struct Stack *) malloc(sizeof(struct Stack));
		if(!S)
			{
				return NULL;
			}
		S->top = -1;
		S->capacity = 5;
		
		S->a = malloc(sizeof(int)*S->capacity);	
		
		if (!S->a)
			{
				return NULL;
			}
		return S;	
	
	}
void doubleStack(struct Stack *s)
 {
   s->capacity = s->capacity*2;
	s->a = realloc(s->a, s->capacity);
 
 
 }	
int isEmpty(struct Stack *s)
		{
		
			return (s->top == -1);
		
		}
int isFull(struct Stack *s)
			{
			
			return (s->top == s->capacity-1);
			
			}
void push(struct Stack *s, int data)
				{
				//printf("push");
				if(isFull(s))
					{
					
					printf("stack full");
					doubleStack(s);
					}
					
					//printf("push");
					s->a[++s->top] = data;
					//printf("%d",s->a[s->top]);
					
				
				
				}
int pop(struct Stack *s)
			{
				if(!isEmpty(s))
					{
					return s->a[s->top--];
					
					}
				return -1;	
			
			}

			