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
		h->data=d;
		h->next=NULL;
		
		return h;
		
	
	
	}	
void push(struct SLL **h,int d)
	{
		struct SLL *n=(struct SLL *)malloc(sizeof(struct SLL));
				n->data=d;
				n->next=*h;
				*h=n;
		
	}	
	
void print(struct SLL *h)
	{
		if(h)
			{
				printf("%d ",h->data);
				print(h->next);
			
			
			
			}
	
	
	}	

int size(struct SLL *h)
	{
		int cnt=0;
		while(h)
			{
				h=h->next;
				++cnt;
			
			}
		return cnt;	
	
	
	
	}
void swap(struct SLL **f1,struct SLL **f2)
	{
		struct SLL *t=*f1;
		*f1=*f2;
		*f2=t;
	
	
	
	
	}	
	
void remain(struct SLL *f,struct SLL *cur,int *c,struct SLL **r)
	{
		int sum;
		if(f!=cur)
			{
				remain(f->next,cur,c,r);
				sum=f->data+*c;
				*c=sum/10;
				sum%=10;
				push(r,sum);
				
				
			
			
			}
	
	
	}	
	
struct SLL *add1(struct SLL *f,struct SLL *s,int *c)
	{
		if(!f)
			return NULL;
			
		int sum;
		struct SLL *r=(struct SLL *)malloc(sizeof(struct SLL));
		r->next=add1(f->next,s->next,c);
		sum=f->data+s->data+ *c;
		
		*c=sum/10;
		sum=sum%10;
		r->data=sum;
		
		return r;
		
		
			
	
	
	
	
	
	}	
	
void add(struct SLL *f,struct SLL *s,struct SLL **r)

	{
		int s1=size(f);
		int s2=size(s);
		int c=0;
		
		if(!f)
			{	
				*r=s;
				return;
			}
		if(!s)
			{	
				*r=f;
				return;
			}		
		
		struct SLL *cur;
		if(s1==s2)
			{
				*r=add1(f,s,&c);
			
			
				//printf("nn");
			
			}
		else
			{
				int diff=abs(s1-s2);
				
				if(s2>s1)
					swap(&f,&s);
					
				for(cur=f;diff--;cur=cur->next);
				*r=add1(cur,s,&c);
				
				remain(f,cur,&c,r);	
					
			
			
			}	
			
		if(c)
			push(r,c);	
			
			
		
				
	
	
	
	}	
struct SLL *R(struct SLL *h,int k)
	{
		struct SLL *n;
		struct SLL *prev=NULL;
		struct SLL *cu=h;
		int count=0;
		int i;
		struct SLL *cur=cu;
		for(i=0;cur&&i<k;i++,cur=cur->next);
		if(k==i)
		{
		
		while(cu && count<k)
			{
				n=cu->next;
				cu->next=prev;
				prev=cu;
				cu=n;
			
			count++;	
			
			
			}
			
		if(n)
			h->next=R(n,k);	
		
		return prev;	
			
		}
	else
		return cu;	
	
	
	}	
	
struct SLL *kAlter(struct SLL *h,int k)	
	{
		struct SLL *cur=h,*prev=NULL;
		struct SLL *t,*n;
		int count=0;
		while(cur && count<k)
			{
				n=cur->next;
				cur->next=prev;
				prev=cur;
				cur=n;
			
			count++;
			
			
			}
		if(h)
			h->next=cur;	
		count=0;
		while(count<k-1 && cur )
			{
				cur=cur->next;
				count++;
			
			}
		if(cur)
			cur->next=kAlter(cur->next,k);
			
		return prev;		
	
	
	
	
	
	
	}
	
main()
	{
		struct SLL *f=NULL;
		struct SLL *s=NULL;
		struct SLL *r=NULL;
		int a1[]={9,9,9};
		int a2[]={1,8};
		
		int sz,i;
		sz=sizeof(a1)/sizeof(a1[0]);
		for(i=sz-1;i>=0;--i)
			push(&f,a1[i]);
		sz=sizeof(a2)/sizeof(a2[0]);
		for(i=sz-1;i>=0;--i)
			push(&s,a2[i]);	
		print(f);
		printf("\n\n");	
		print(s);
		printf("\n\n");
		add(f,s,&r);
		print(r);
		
		struct SLL *head=NULL;
		for(i=1;i<18;i++)
			push(&head,i);
		printf("\n\n\n");	
		//head=R(head,5);
		print(head);	
		printf("\n\n");
		
		head=kAlter(head,2);
			
		print(head);	
		printf("\n\n");
	
	
	}	
	
