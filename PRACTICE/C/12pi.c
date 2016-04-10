#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct S
	{
		int top;
		int a[MAX];
	
	};
void push(struct S *s,int d)
	{
		if(s->top==MAX-1)
			{
			
				printf("Error\n");
				return;
			
			}
		else
			{
			
				s->a[++s->top]=d;
				
			
			}	
	
	
	
	
	}
	
int isEmpty(struct S *s)
	{
	
		return s->top==-1;
	
	}	
int pop(struct S *s)
	{
		int t;
		if(isEmpty(s))
			return -1;	
	
		else
			{
				return s->a[s->top--];
			
			}
	
	}
	
void printNGE(int a[],int n)
	{
		int next,element;
		
		int i,j;
		struct S s;
		s.top=-1;
		push(&s,a[0]);
		for(i=1;i<n;i++)
			{
				next=a[i];
				if(!isEmpty(&s))
					{
						element=pop(&s);
						while(element<next)
							{
								printf("\nnext of %d is:%d\n\n",element,next);
								if(isEmpty(&s))
									break;
								element=pop(&s);
							}
						if(element>next)
							push(&s,element);
					
					
					}			
				push(&s,next);
			
			
			
			}
			
			while(!isEmpty(&s))
				{
					element=pop(&s);
					next=-1;
					printf("\nnext of %d is:%d\n\n",element,next);
				
				
		}
	}	
	

main()
	{
	
		int a[]={3,45,6,7,12,45};
		
		int i,j,next;
		for(i=0;i<6;i++)
			{	next=-1;
				for(j=i+1;j<6;j++)
					{
						if(a[i]<a[j])
							{
								next=a[j];
								break;
							}	
							
							
					}
				printf("\nNext Greater of %d is::%d\n\n",a[i],next);
						
				
				
				
				
				
			
			
			}
			
		printNGE(a,6);	
		
	}
