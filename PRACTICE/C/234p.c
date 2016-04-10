#include<stdio.h>
#include<stdlib.h>

struct SLL
	{
		int data;
		
		struct SLL *next;
	
	};
	
struct SLL *nn(int d)
	{
		struct SLL *h=(struct SLL *)malloc(sizeof(struct SLL ));
		h->data=d;
		h->next=NULL;
		
		return h;
	
	
	}	
	
void display(struct SLL *h)
	{
		if(h)
			{
				printf("[%d]\t",h->data);
				display(h->next);
			
			}
	
	}	
	
void rev(struct SLL **h)
	{
		struct SLL *p=NULL,*r,*t=*h;
		while( t)
			{
				r=p;
				p=t;
				t=t->next;
				p->next=r;
				
				
			
			}
			*h=p;
	
	
	}	
	
void rev2(struct SLL *h)
	{
		struct SLL *t,*p=h;
		
		while(p && p->next)
			{
				t=p->next;
				p->next=t->next;
				t->next=p;
				
				p=p->next;
			
			}
	
	
	
	}	
	void getnthnode(struct SLL *h,int n)	
		{
			if(!h)
				return;
				
			struct SLL *p=h;
			int cnt=0;
			while(p)
				{
					if(cnt-n>=0)
						h=h->next;
					p=p->next;
					cnt++;
				
				}
				
			if(h)
				{
					printf(" POS::%d===NODE::[%d]:\n\n",cnt,h->data);
					
					return;
				
				}	
				
			
				
		
		
		
		}
		
void delete(struct SLL *n)
	{
		struct SLL *t=n->next;
		
		n->data=t->data;
		n->next=t->next;
		free(t);
	
	}		
	

void middle(struct SLL *h)

	{
		if(!h)
			return ;
			
		struct SLL *p=h,*q=h;
		
		while(p)
			{
				p=p->next;
				if(p)
					{
					q=q->next;
					p=p->next;
					}
			
			
			
			}	
			
		printf("MID NODE: [%d]\n\n",q->data);	
			
	
	
	
	}
	
void getnthnoder(struct SLL *h,int n)
	{
		static int i=0;
		
		if(!h)
			return;
			
		getnthnoder(h->next,n);
		if(++i==n)
			printf("[%d]\t\n\n",h->data);	
	
	}	
	

void reverse(struct SLL *h,struct SLL *pr)
	{
		if(h)
			{
				
				reverse(h->next,h);
				h->next=pr;
			
			
		
			}
	
		else
			h=pr;	
	
	
	
	}	
	
void revr(struct SLL *h)
	{
		if(h)
			{
			struct SLL 	*t=h->next;
				revr(t);
				h->next=t;
			
			}
	
	
	
	}	
	
main()
	{
		struct SLL *head=nn(1);
		
		int i;
		struct SLL *d;
		for(i=0;i<11;i++)
			{	
				struct SLL *t=nn(i);
				t->next=head;
				head=t;
				if(i==7)
					d=t;
				
			}	
		/*	head->next=nn(2);
			head->next->next=nn(3);
			head->next->next->next=nn(4);
			head->next->next->next->next=nn(5);
			head->next->next->next->next->next=nn(6);*/
			
			display(head);
			printf("-->NULL\n\n");
			
			middle(head);
			
			delete(d);
			revr(head);
			printf("\n\n\nREV:\n");
			
			display(head);
			printf("-->NULL\n\n");
			
			
			getnthnode(head,6);
			getnthnoder(head,6);
			rev(&head);
			display(head);
			printf("-->NULL\n\n");
			
			
			
			
			
			
			
			
		
	
	}	
