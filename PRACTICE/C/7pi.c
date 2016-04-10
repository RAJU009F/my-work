#include<stdio.h>
#include<stdlib.h>


struct SLL 
	{
		struct SLL *next;
		char data;
		
	
	
	};
	
void push(struct SLL **h,char d)
	{
	
		struct SLL *t=(struct SLL *)malloc(sizeof(struct SLL ));
		t->data=d;
		
		t->next=*h;
		*h=t;
	
			
	
	
	
	
	
	}	
void print_list(struct SLL *h)
	{
		if(h)
			{
				printf("[%c]\t",h->data);
				print_list(h->next);
			
			
			}
	
	
	
	
	
	
	}
	
void vowel(struct SLL *h)
	{
		struct SLL *t=NULL,*p,*prev,*cur;
		
	
		while(cur)
			{
				
				if(cur->data=='a'||cur->data=='e'||cur->data=='i'||cur->data=='o'||cur->data=='u')
				{	
					if(!t)
						{
							p=cur;
							t=p;
						
						
						}
					t->next=cur;
					t=cur;
					
					
					prev->next=cur->next;
				cur=cur->next;	
					
				}	
				
						
			
			
			
			
			
			
			}
	
	
	
	
	
	
	
	
	
	}		
	
main()
	{
		struct SLL *h=NULL;
	
		int i;char ch;	
		for(i=0;i<10;i++)
			{
				scanf("%c",&ch);
				
				push(&h,ch);
			
			}
		print_list(h);
		
		printf("\n\n");
		
	vowel(h);
	print_list(h);
	
	printf("\n\n");
	
	
	
	
	}	
