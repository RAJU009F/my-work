#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct S 
	{
		int top;
		int size;
		int a[0]; 
	
	};
	
struct S *create(int si)
	{
		struct S *s=(struct S *)malloc(sizeof(struct S));
		
		s->top=-1;
		s->size=si;
		*s->a=(int *)malloc(sizeof(int)*si);
		return s;
	
	}	
	
int isEmpty(struct S *s)
	{
	
		return s->top==-1;
		
	
	}	
	
int isFull(struct S *s)
	{
	
		return s->top==s->size-1;
	
	}	
void push(struct S *s,int d)
	{
		if(isFull(s))
			return;
			
		s->a[++s->top]=d;	
	
	
	
	}	
	
int pop(struct S *s)
	{
		if(isEmpty(s))
			return -1;
			
		return s->a[s->top--];	
	
	
	}	
void insert(struct S *s,int d)
	{
		if(isEmpty(s))
			{
				push(s,d);
				return;
			
			}
		
		int t=pop(s);	
		insert(s,d);
		push(s,t);
	}	
	
void reverse(struct S *s)
	{
		if(!isEmpty(s))
			{
				int t=pop(s);
				
				insert(s,t);
			
			
			
			
			}
	
	
	
	}
	
void print(struct S *s)
	{
		int i=s->top;
		while(s->a[i])
			{
				printf("[%d]\n",s->a[i]);
				--i;
				
			
			
			}
	
	
	
	
	
	}		
	
main()
	{
	
	struct S *s=create(MAX);
	
	int i=0;
	
	for(i=1;i<6;i++)
		{
			push(s,i);
		
		
		}
	print(s);
	reverse(s);
	print(s);
	
	}	
