#include<stdio.h>
#include<stdlib.h>

struct H
	{
		int *a;
		int count;
		int cap;
	
	
	};
	
struct H *create()
	{
		struct H *h=(struct H *)malloc(sizeof(struct H ));
		h->cap=1;
		h->count=0;
		h->a=(int *)malloc(sizeof(int)*1);
		
		return h;
	
	
	}	
	
void resize(struct H *h)
	{
		int *A=h->a;
		//int size=h->cout;
		h->cap=2*h->cap;
		h->a=(int *)realloc(h->a,h->cap);
	
	}	
	
void insert(struct H *h,int d)
	{
		if(h->cap==h->count)
			resize(h);
			h->count++;
		int i=h->count;
		i=i-1;
		
				if(i==0)
					{
						h->a[i]=d;
						return;
						
					}	
		while(i>=0&&d>h->a[(i-1)/2])
			{
				
				if(i==0)
					{
						h->a[i]=d;
						break;
					}	
				h->a[i]=h->a[(i-1)/2];
				i=(i-1)/2;
				
			
			}
		h->a[i]=d;	
		
	
	
	}	
	
void display(struct H *h)
	{
		int i;
		for(i=0;i<h->count;i++)
			{
				printf("[%d]\t",h->a[i]);
			
			}
	
	
	}	
void insertatlast(struct H *h,int d)
	{
		if(h->count==h->cap)
			resize(h);
			
		h->count++;
		h->a[h->count-1]=d;	
	
	
	
	}	
	
int left(struct H *h,int i)
	{
		int left=2*i+1;
		if(left<=0 || left>=h->count)
				return -1;
		else
			return left;		
	
	}	
	
int right(struct H *h,int i)
	{
		int rt=2*i+2;
		if(rt<=0||rt>=h->count)
			return -1;
		else
			return rt;	
	
	}	
	
void pdown(struct H *h,int i)
	{
		if(i>=h->count)
			return;
		int max;
		
		int l=left(h,i);
		int r=right(h,i);
		
		if(l!=-1 && h->a[i]<h->a[l])
			max=l;
		else
			max=i;
		if(r!=-1 && h->a[max]<h->a[r])
			max=r;
			
		if(max!=i)
			{
				int t=h->a[max];
				h->a[max]=h->a[i];
				h->a[i]=t;
							
			pdown(h,max);	
			
			}	
	else
		return;		
	
	
	
	
	}	
void delete(struct H *h)
	{
		int d;
		if(h->count==0)
			return ;
			
		h->a[0]=h->a[h->count-1];
		h->count--;
		
		pdown(h,0);	
	
	
	
	}	
	
void build(struct H *h,int A[],int n)
	{
		if(h==NULL)
			return;
		printf("\nnax\n");	
		while(h->cap<n)
			resize(h);
			int i;
		for(i=0;i<n;i++)
			h->a[i]=A[i];
		h->count=n;
		for(i=((n-1)/2);i>=0;i--)
			pdown(h,i);		
	
	
	}	
void buildH(struct H *th, int A[],int n)	
	{
	
		if(th==NULL)
			return;
		while(n>th->cap)
			resize(th);
		int i;
		for(i=0;i<n;i++)
			th->a[i]=A[i];
		th->count=n;
		for(i=(n-1)/2;i>=0;i--)
			pdown(th,i);			
	
	
	
	
	}
	
	
	
	
	main()
		{
			struct H *h=create();
			
			
			
			int A[17]={12,34,5,6,7,89,34,56,78,89,234,34,456,3453,232,232323,34};
			//struct H *h=create();
			buildH(h,A,17);
			printf("\n\n");
			display(h);
			
			
			
			
			insert(h,10);
			insert(h,67);
			int i;
			for(i=100;i>1;i/=2)
				insert(h,i);	
			
			
			insertatlast(h,2434);
		pdown(h,0);
			
			display(h);
			delete(h);
			printf("\n\n");	
			display(h);
			delete(h);
			printf("\n\n");	
			display(h);
			
			
		
		}
