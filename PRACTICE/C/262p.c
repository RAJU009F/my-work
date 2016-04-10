#include<stdio.h>
#include<stdlib.h>

struct H 
	{
		int cap;
		int count;
		int *a;
		
	
	
	
	};
	
struct H *create()
	{
		struct H *h=(struct H *)malloc(sizeof(struct H));
		h->count=0;
		h->cap=1;
		h->a=(int *)malloc(sizeof(int));
		
		return h;
	
	}	
void resize(struct H *h)	
	{
		h->a=(int *)realloc(h->a,2*h->cap);
	
	
	}	
int left(struct H *h,int i)
	{
		int le=2*i+1;
		if(le<=0 || le>=h->count)
			return;
		else
			return le;	
		
	
	}	
int right(struct H *h,int i)
	{
		int rt=2*i+1;
		if(rt<=0 || rt>=h->count)
			return;
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
			{
				max=r;
				
			}	
		if(max!=i)
			{
				int t=h->a[max];
				h->a[max]=h->a[i];
				h->a[i]=t;
			
			}	
		//pdown(h,max);	
					
	
	
	}	
void insert(struct H *h,int d)
	{
		
		if(h->count==h->cap)
			resize(h);
		h->count++;	
		int i=h->count-1;	
		if(i==0)
			{
				h->a[i]=d;
				return;
			}
		while(i>=0&&d>h->a[(i-1)/2])
			{
				
				h->a[i]=h->a[(i-1)/2];
				i=(i-1)/2;
				
				if(i==0)
					break;
			
			
			}	
		h->a[i]=d;	
	
	}	
	
void build(struct H *h,int A[],int n)
	{
			int i;
			for(i=0;i<n;i++)	
				insert(h,A[i]);	
	
	
	
	}	
	
void display(struct H *h)
	{
		int i;
		for(i=0;i<h->count;i++)
			{
				printf("[%d]\t",h->a[i]);
			
			}
	
	}	
void heapsort(struct H *h)
	{int i=h->count-1;
		int old=i+1;
		for(i;i>0;i--)
			{
				int t=h->a[0];
				h->a[0]=h->a[h->count-1];
				h->a[h->count-1]=t;
				h->count--;
			pdown(h,i);
			
			}
		h->count=old;	
	
	}	
	
	
main()
	{
		int A[]={12,34,5,6,7,89};
			struct H *h=create();
			build(h,A,6);
			printf("\n\n");
			display(h);
			heapsort(h);
			printf("\n\n");
			display(h);
	
	}	
