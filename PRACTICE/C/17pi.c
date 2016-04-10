#include<stdio.h>
#include<stdlib.h>


struct LL 
	{
		struct LL *npx;
		int data;
	
	};
	
struct LL *XOR(struct LL *a,struct LL *b)
	{
		return (struct LL *)((unsigned int)(a)^(unsigned int )(b));
	
	}	
void print(struct LL *h)
	{
		struct LL *c=h;
		struct LL *p=NULL;
		struct LL *next;
		
		while(c)
			{
				printf("[%d]---",c->data);
				next=XOR(p,c->npx);
				p=c;
				c=next;
			
			
			}
	
	}	
	
void insert(struct LL **h,int d)
	{
		struct LL *nn=(struct LL *)malloc(sizeof(struct LL));
		nn->data=d;
		nn->npx=XOR(*h,NULL);
		if(*h)
			{
				struct LL *next=XOR((*h)->npx,NULL);
				(*h)->npx=XOR(nn,next);
			
			
			}
			
			*h=nn;
	
	
	
	
	}	
	
	
main()
	{
	struct LL *h=NULL;
	insert(&h,110);
	insert(&h,11430);
	insert(&h,1310);
	insert(&h,114340);
	insert(&h,113440);
	insert(&h,1140);
	print(h);
	
	
	
	}	
