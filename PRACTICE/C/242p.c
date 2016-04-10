#include<stdio.h>
#include<stdlib.h>

struct SLL
	{
		struct SLL *next;
		int data;
	
	};

	
struct SLL *nn(int d)
	{
	
		struct SLL *temp=(struct SLL *)malloc(sizeof(struct SLL));
		temp->next=NULL;
		temp->data=d;
		
		return temp;
	
	
	}
	
void dis(struct SLL *s)
	{
		while(s)
			{
				printf("[%d]\t",s->data);
			
				s=s->next;
			
			}
	
	
	}	
void push(struct SLL **s,int d)
	{
		
			struct SLL *temp=nn(d);
			
			temp->next=*s;
			*s=temp;		
	
	}		
	
void display(struct SLL *s)	
	{
		if(s)	
			{
				printf("[%d]\t",s->data);
				display(s->next);
			
			}
	
	}
	
int pop(struct SLL *s)
	{
		if(isEmpty())
			return 0;
			
		struct SLL *temp=s;
		int item=temp->data;
		s=s->next;
		free(temp);
		return item;	
			
	
	}	
	
int isEmpty(struct SLL *s)
	{
		return s==NULL;
	
	}		
main()
	{
		struct SLL *s=NULL;
		int i;
		for(i=0;i<11;i++)
			push(&s,i+103);	
			
			
			
		display(s);	
			
		printf("\n\n");	
		for(i=0;i<5;i++)
			{
				int t=pop(s);
				printf("[%d]\t",t);
		
			}
			
		printf("\n\n");	
		display(s);	
		
		printf("%d\n\n",isEmpty(s));
	
		
	}
	
	
	
	
