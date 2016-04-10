#include<stdio.h>
#include<stdlib.h>

struct SLL 
	{
	
		struct SLL *next;
		struct SLL *prev;
		int data;
	
	
	};
	
struct SLL *partition(struct SLL *l,struct SLL *h)
	{
		int x=h->data;
		
		struct SLL *i=l->prev;
		for(struct SLL *j=l;j!=h;j=j->next)	
			{
				if(j->data<=x)
					{
						i=(i==NULL)?l:i->next;
						swap(&(i->data),&(j->data));
					
					
					}
					
					i=(i==NULL)?l:i->next;
					swap(&(i->data),&(h->data));
					return i;
			
			
			
			}
	
	
	
	}	
	
	
void _quicksort(struct SLL *l,struct SLL *h)
	{
		if(h && h!=l && l!=h->next)
			{
				struct SLL *p=partition(l,h);
				_quicksort(l,p->pre);
				_quicksosrt(p->next,h);
			
			
			}
	
	
	
	}	

void quicksort(struct SLL *h)
	{
		struct SLL *p=lastnode(h);
		
		_quicksort(h,p);
		
	
	
	
	}	
	
