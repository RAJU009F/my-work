#include<stdio.h>
#include<stdlib.h>


struct SLL
	{
		struct SLL *next;
		int data;
	
	
	};
	
struct SLL *nn(int d)
	{
		struct SLL *h=(struct SLL *)malloc(sizeof(struct SLL) );
		h->next=NULL;
		h->data=d;
		
		return h;
	
	
	}	
	
 struct SLL *add(struct SLL *f,struct SLL *s)
 	{
 	
 		int c=0, sum;
 		struct SLL *res=NULL,*temp,*prev;
 		while(f || s)	
 			{
 				sum=(f?f->data:0)+(s?s->data:0);
 				
 				sum=sum+c;
 				c=sum>=10?1:0;
 				sum=sum%10;	
 				temp=nn(sum);
 				
 				if(!res)
 					{
 					
 						res=temp;
 						prev=res;
 					}	
 				else
 					{
 						prev->next=temp;
 						prev=prev->next;
 					
 					}
 					
 				if(f)
 					f=f->next;
 				if(s)
 					s=s->next;		
 			
 			
 			
 			
 			}
 			
 			if(c)
 				prev->next=nn(c);
 	
 	
 	
 	
 		return res;
 	
 	
 	} 	
void print(struct SLL *h)
	{
		if(h)
			{
				print(h->next);
				printf("%d ",h->data);
			}	
	
	} 	
	
void rev(struct SLL **p)
	{ 
		struct SLL *h,*q=NULL,*r;
		h=*p;
		while(h)
			{
				r=q;
				q=h;
				h=h->next;
				q->next=r;	
				
				
			
			}
			
			*p=q;
			
	
	
	
	}	
void prin(struct SLL *h)
	{
		if(h)
			{
				printf("[%d]--",h->data);
				prin(h->next);
			
			
			}
	
	
	
	}	
	
void rev1(struct SLL **h)
	{
		struct SLL *f;
		struct SLL *r;
		if(!*h)
			 return;
			 
		 f=*h;
		 r=f->next;
		 if(!r)
		 	return;
		 rev1(&r);
		 f->next->next=f;
		 
		 f->next=NULL;
		 
		 
		 *h=r;
		  
	
	
	
	
	}	
	
void R(struct SLL **h,struct SLL *p)
	{
		if(*h)
			{
				struct SLL *t=*h;
				
				R(&(t->next),t);
				
				(*h)->next=p;
			
			
			}
	
		*h=p;
	
	}	
	
main()
	{
	
		struct SLL *h1=nn(3);
			h1->next=nn(2);
			h1->next->next=nn(9);
		struct SLL *h2=nn(5);
		h2->next=nn(5);
		h2->next->next=nn(7);
		
		struct SLL *h=add(h1,h2);
		
		print(h1);
		printf("\n\n");
		print(h2);
		printf("\n\n");
		print(h);
		printf("\n\n");
		
		struct SLL *head=nn(10);
		head->next=nn(9);
		head->next->next=nn(7);
		head->next->next->next=nn(8);
		head->next->next->next->next=nn(6);
		head->next->next->next->next->next=nn(5);
		head->next->next->next->next->next->next=nn(4);
		rev(&head);
		
		prin(head);
		
		printf("\n\n");
		rev1(&head);
		
		prin(head);
		
		printf("\n\n");
		
		R(&head,NULL);
		prin(head);
		
		printf("\n\n");
	
	}	
 	
	
	
