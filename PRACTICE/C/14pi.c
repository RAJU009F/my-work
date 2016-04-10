#include<stdio.h>
#include<stdlib.h>

struct SLL 
	{
		struct SLL *next;
		int data;
	};
struct SLL *rev(struct SLL **h)	
	{
		struct SLL *first=*h;
		struct SLL *rest=first->next;
		
		if(!first)
			return;
			
		if(!rest)
			return;
			
		rev(&rev);
		first->next->next=first;
		first->next=NULL;
		
		*h=rev;
				
	
	
	
	}




main()
	{
		
	
	
	
	}
