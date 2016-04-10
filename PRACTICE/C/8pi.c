#include<stdio.h>
#include<stdlib.h>



struct S
	{
		struct S *next;
		char data;
		
	
	
	};

struct S *create()
	{
		return NULL;
		
		
	
	}
	
	
	
void push(struct S **h,char c)
	{
		struct S *t=(struct S *)malloc(sizeof(struct S ));
		t->data=c;
		t->next=*h;
		*h=t;		
		
	
	
	
	
	}	
	
char pop(struct S **h)
	{
		char ch;
		struct S *t;	
		if(!*h)
			return 0;
	
		else
			{
				 t=*h;
				*h=t->next;
				 ch=t->data;
				
				
				free(t);
				return ch;
			
			
			
			
			}
	
	
	
	
	
	}	
	
int isEmpty(struct S *h)
	{
		return h==NULL;
	}	
	
void print_list(struct S *h)
	{
		if(h)
			{
				printf("%c\t",h->data);
				print_list(h->next);
			
			
			}
	
	
	
	
	
	
	}	
	
int matcher(char c,char c2)
	{
		if(c=='[' && c2==']')
			return 1;
		else if(c=='{' && c2=='}')
			return 1;
		else if(c=='(' && c2==')')
			return 1;
		else
			return 0;			
	
	
	
	
	
	}	
	
	
int balanced(char str[])
	{
		struct S *h=NULL;
		
		int i=0;
		while(str[i])
			{
			
				if(str[i]=='(' || str[i]=='[' || str[i]=='{')
					push(&h,str[i]);
				 if(str[i]==')' || str[i]=='}' || str[i]==']' )
					{	
							if(isEmpty(h))
								return 0;
							
							if(!(matcher(pop(&h),str[i])))
								return 0;
									

						
					}
					
					i++;
			
			
			
			
			
			}
			print_list(h);
			printf("\n\n");
			if(!isEmpty(h))
				return 0;
			else
				return 1;	
	
	
	
	
	
	
	
	}	
main()
	{
	
		//struct S *h=create();
		
			char str1[189]="{()}[]";
			
		if(balanced(str1))
			printf("Yes::\n");
		else
			printf("NO :: \n");		
		
			
	
		
	
	
	}	
