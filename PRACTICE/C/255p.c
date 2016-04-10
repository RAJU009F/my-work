#include<stdio.h>
#include<stdlib.h>


struct BT 
	{
		int data;
		struct BT *next;
	
	
	};
struct BT *nn(int d)
	{
		struct BT *h=(struct BT *)malloc(sizeof(struct BT ));
		h->data=d;
		h->next=h;
		return h;
	
	}	
	
void findlucky(struct BT *h,int m,int n)
	{
		int cnt,i;
		for(cnt=n;cnt>1;cnt--)
			{	
				for(i=0;i<m-1;i++)
					h=h->next;	
				h->next=h->next->next;
			
			}
		if(h)
			printf("node is:::[%d]\n\n",h->data);
	
	
	
	}	
	
void loopexist(struct BT *h)
	{
		struct BT *s,*f;
		s=f=h;
		int e=0;
		while(s && s->next)
			{
				f=f->next;
				if(s==f)
					{
						e=1;
						break;
					}			
				f=f->next;
				
				if(!f)
					return ;
				if(f==s)
					{
						e=1;
						break;
					
					
					}	
					
				s=s->next;
				
				if(s==f)
					{
						e=1;
						break;
					
					}	
			
			}
		
		if(e)
			{
				s=h;
				printf("\nnax\n");
				while(s!=f)
					{
						s=s->next;
						f=f->next;
					
					}
					
					printf("loop statrt is:[%d]\n\n\n",f->data);
			
			
			
			}
	
	
	}	
	
	main()
		{
			struct BT *p=NULL,*head=nn(1);
				p=head;
				int M,N;
			printf("Enter N and M :\n\n");
			scanf("%d%d",&M,&N);
			int i;
			for(i=2;i<N;i++)
				{	
					p->next=nn(i);
					p=p->next;
					
					
					
				}	
				
			p->next=head;
			
			findlucky(head,M,N);
			struct BT *t,*p1,*h=nn(100);
			p1=h;
			for(i=0;i<20;i++)
				{
					p1->next=nn(i);
					p1=p1->next;
					if(i==14)
						t=p1;
					

				}	
				
			p1->next=t;
			
		loopexist(h);	
					

		
		
		
		}
