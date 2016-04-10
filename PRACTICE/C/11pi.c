#include<stdio.h>
#include<stdlib.h>


struct SLL 

	
	{
		struct SLL *next;
		int data;
	
	
	
	};
	
void push(struct SLL **h,int d)
	{
		struct SLL *t=(struct SLL *)malloc(sizeof(struct SLL));
		t->data=d;
		t->next=*h;
		*h=t;
	
	
	}	
struct SLL *sort(struct SLL *h1, struct SLL *h2)
	{
		struct SLL *r;
		if(!h1)
			return h2;
		if(!h2)
			return h1;
			
		if(h1->data>h2->data)
			{
				r=h2;
				r->next=sort(h1,h2->next);
			}
			
		else
			{
					r=h1;
				r->next=sort(h1->next,h2);
			
			
			}				
	
	
		return r;
	
	
	}	
void print(struct SLL *h)
	{
		if(h)
			{
				printf("[%d]--",h->data);
				print(h->next);
			
			
			}
	
	
	}	
	
void deletenth(struct SLL **h,int n)
	{
		struct SLL *f=*h,*s=*h;
		struct SLL *r=*h;
		//print(s);
		int count=0;
		while( s)
			{
				if(count-(n)>0)
					f=f->next;
				s=s->next;
				count++;
			
			}
			print(f);
			struct SLL *t=f->next;
			f->next=t->next;
			//free(t);	
	
		//*h=r;
	
	
	
	
	
	
	}	
	
void FBsplit(struct SLL *h,struct SLL **a,struct SLL **b)
	{
		struct SLL *f;
		struct SLL *s;
		
		if(!h || (!(h->next)))
			{
				*a=h;
				*b=NULL;
			
			}
		else
			{
				f=h->next;
				s=h;
				
				while(f)	
					{
						f=f->next;
						if(f)
							{
								f=f->next;
								s=s->next;
							
							
							
							}
					
					
					
					
					
					
					
					
					}
					*a=h;
					*b=s->next;
					s->next=NULL;
			
			
			
			
			
			}	
	
	
	
	
	
	
	
	}	
	
void mergesort(struct SLL **h)
	{
		struct SLL *h1=*h;
		
		struct SLL *a;
		struct SLL *b;
		if(!*h || !((*h)->next))
			return;
		FBsplit(h1,&a,&b);
		
		mergesort(&a);
		mergesort(&b);
		
		*h=sort(a,b);	
	
	
	
	
	
	
	
	
	}	
	
main()
	{
		struct SLL *h1=NULL;
		int i;
		for(i=10;i>0;i-=2)
			{
				push(&h1,i);
			
			}
		struct SLL *h2=NULL;	
		for(i=11;i>0;i-=2)	
			{
				push(&h2,i);
			
			
			}
			
		print(h1);	
			
		struct SLL *h=sort(h1,h2);	
		
		printf("\n\nREsult::\n\n");
		print(h);
	
		printf("\n\nREsult::\n\n");
	
		deletenth(&h,4);
		printf("\n\nREsult::\n\n");
		print(h);
		printf("\n\nREsult::\n\n");
//		
	
		struct SLL *head=NULL;
		for(i=100;i>1;i-=9)
			{
				push(&head,((i*i+1)/9)%100);
			
			
			}
		mergesort(&head);
		print(head);
	
	
	}	
