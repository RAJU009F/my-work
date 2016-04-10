#include<stdio.h>
#include<stdlib.h>

struct S
	{
		int ch;
		struct S *next;
	
	
	};
	
	
struct S *createS()
	{
		struct S *s=(struct S *)malloc(sizeof(struct S));
		s=NULL;
		return s;
	
	
	
	}	
	
struct S *nn(int x)
	{
		struct S *s=(struct S *)malloc(sizeof(struct S));
		s->ch=x;
		s->next=NULL;
	
		return s;
	}	
	
void push(struct S **s,int x)
	{
		
		struct S *t=nn(x);
		t->next=*s;
		*s=t;
	
	
	}	
	
int isEmpty(struct S *s)
	{
		return (s==NULL);
	
	
	}	
int pop(struct S *s)
	{
		if(isEmpty(s))
			return '\0';	
		int t=s->ch;
		//struct S *t=s;
			s=s->next;
			//free(t);
		return t;
	}	
	
int ispalindrome(int *str)
	{
		
		struct S *s=createS();
		int i=0;
		while(str[i]!='y')
			{
				push(&s,str[i]);
				i++;
			
			}
			i++;
			
			while(str[i] && !isEmpty(s) )
					{
						if(str[i]!=pop(s))
							{
								return 0;
							
							
							}
							
							i++;
							
					
					
					}	
					
				return (isEmpty(s));		
	
	
	}
void insert(struct S *s,int c)
	{
		if(isEmpty(s))
			{push(&s,c);
			return ;}
		else
			{
			
				int t=pop(s);
				insert(s,c);
				
				push(&s,t);
			
			
			}	
	
	
	
	
	
	}	
	
void reverse(struct S **s)
	{
		if(!isEmpty(*s))
			{
				int c=pop(*s);
				insert(*s,c);
			
			
			
			
			
			}
	
	
	
	
	}		
	
	void printstack(struct S *s)
		{
			while(s)
				{
				
					printf("%c\n",s->ch);
					
					s=s->next;
				
				}
		
		
		
		
		}
	main()
		{
		
		//int str[]={1,2,3,4,3,2,1};
		
		
		
		
		//if(ispalindrome(str))
		//	printf("yes:\n\n");
		//else
		//	printf("No::\n\n");	
			
			int i;
			struct S *s=createS();
			for(i=0;i<6;i++)
				push(&s,i);
				
			printstack(s);	
			reverse(&s);
			printf("\n\n after\n\n");
			printstack(s);
		
		
		
		
		
		}
