#include<stdio.h>
#include<stdlib.h>



struct Heap 
	{
	int cap;
	int *a;
	int cnt;
	
	
	};


struct Heap *createH(int cap);
void insertH(struct Heap *,int);
void resizeH(struct Heap *);
void printH(struct Heap *);
int parentH(struct Heap *,int );
void childH(struct Heap *, int);
int maxH(struct Heap *);
int lchild(struct Heap *,int );
int rchild(struct Heap *,int );
int parent(struct Heap *,int );
int deletH(struct Heap *);
void heapifyH(struct Heap *,int);
void destroyH(struct Heap *);
void buildH(struct Heap *,int A[],int);



main()
	{
	
		int e,r,ch,i,n=10,arr[n];
		struct Heap *h=createH(1);
		
		while(1)
			{
			
				printf("\n\t\t1 TO INSERT");
				printf("\n\t\t2 TO DELETE");
				printf("\n\t\t3 TO PRINT");
				printf("\n\t\t4 TO PARENT ");
				printf("\n\t\t5 TO CHILDS");
				printf("\n\t\t6 TO MAX");
				printf("\n\t\t7 TO DESTROY");
				printf("\n\t\t8 TO BUILD");
				
				printf("\n\t\t0 TO EXIT\n\tCHOICE:");
				
				
				scanf("%d",&ch);
				
				switch(ch)
					{
					
						default:
							printf("\ninvalid choice :");
							break;					
						case 0:
							exit(0);
							break;
						case 1:
							printf("\nenter the data to be insert:");
							scanf("%d",&e);
							insertH(h,e);	
							break;
						case 2:
							r=deletH(h);
							if(r>0)
								printf("\n max %d deleted succssfully:",r);
							break;
						
						
						case 3:
							printf("\n current MAX HEAP elements: \n ");
							printH(h);
							break;			
						case 4:
							printf("\nenter the position whom to find parent:");
							scanf("%d",&e);
							r=parentH(h,e);
							if(r>=0)
								printf("\nparent of position %d node is: [%d]",e,r);
							else
								printf("\n no parent or invalid pos");
							break;
						case 5:
							printf("\nenter the position whom to find childs:");
							scanf("%d",&e);
							childsH(h,e);
							break;		
						case 6:
							printf("\n max element is: %d",maxH(h));
							break;	
						case 7:
							destroyH(h);
							break;
						case 8:
							printf("\nenter elements to build heap:");
							for(i=0;i<n;i++)
								scanf("%d",&arr[i]);
							buildH(h,arr,n);
							break;		
						
						
					}	
			
			
			}	
	
	
	
	
	
	}

struct Heap *createH(int c)
	{
	
		struct Heap *th=(struct Heap *) malloc(sizeof(struct Heap));
		th->cap=c;
		th->a=(int *)malloc(sizeof(int)*th->cap);
		th->cnt=0;
		return th;
	
	}

void insertH(struct Heap *th,int data)
	{
		int i;
		if(th->cnt==th->cap)
			resizeH(th);
		th->cnt++;
		i=th->cnt-1;
		if(i==0)
			{
				th->a[i]=data;
				return;		
	
			}
		while((i>=0) && (data>=th->a[(i-1)/2]))
			{
				th->a[i]=th->a[(i-1)/2];
				i=(i-1)/2;
				if(i==0)
					break;
			
			}	
		th->a[i]=data;		
	
	
	
	}			
	
void resizeH(struct Heap *th)
	{
		/*int *arr=th->a;
		th->a=*/
		
		th->cap*=2;
		th->a=realloc(th->a,th->cap);
	
	
	
	
	}
		
void printH(struct Heap *th)
	{
		if(!th->cnt)
			{
				printf("\n No elements");
				return;
			}
		int i;
		for(i=0;i<th->cnt;i++)
			{
				printf("[%d]\t",th->a[i]);
			
			
			}
	
	
	}	
int parentH(struct Heap *th,int i)	
	{
		if(i<=0||i>=th->cnt)
			return -1;
		return th->a[(i-1)/2];	
	}
	
void childsH(struct Heap *th,int i)
	{
	
		int lc,rc;
		lc=2*i+1;
		rc=2*i+2;
		if(lc>=th->cnt)
			printf("\nno left child\n");
		else
			printf("\nleft child of %dth node is:[%d]",i,th->a[lc]);
		if(rc>=th->cnt)
			printf("\nno right child\n");
		else
			printf("\nright child of %dth node is:[%d]",i,th->a[rc]);
					
	
	
	  }	
	
	
int maxH(struct Heap *th)
	{
		if(!th->cnt)
			return -1;
		return th->a[0];	
	}	
int deletH(struct Heap *th)
	{
	
		if(!th->cnt)
			return -1;
	
		int i,data;
		i=th->cnt-1;
		data=th->a[0];
		th->a[0]=th->a[i];
		th->cnt--;
		heapifyH(th,0);
		
		
		return data;
		
	
	
	
	}
	
int parent(struct Heap *th,int i)
	{
		if(i<=0 || i>=th->cnt)
			return -1;
		return (i-1)/2;
	
	}
	
int lchild(struct Heap *th,int i)
	{
		int l=2*i+1;
		if(l>=th->cnt)
			return -1;
		return l;
	
	}	

int rchild(struct Heap *th,int i)
	{
		int r=2*i+2;
		if(r>=th->cnt)
			return -1;
		return r;
	
	}
void heapifyH(struct Heap *th,int i)
	{
		int l,r,max,temp;
		l=lchild(th,i);
		r=rchild(th,i);
		if(l!=-1 && th->a[l]>th->a[i])
			max=l;
		else
			max=i;
		if(r!=-1 && th->a[r]>th->a[max] )
			max=r;
		if(max!=i)
			{
				temp=th->a[i];
				th->a[i]=th->a[max];
				th->a[max]=temp;
				heapifyH(th,max);
			}				
		
		else
			return;
	
	
	
	
	}		
		
void destroyH(struct Heap *th)
	{
	
		if(th==NULL)
			return;
		free(th->a);
		free(th);
		th=NULL;	
	
	
	
	}		
void buildH(struct Heap *th, int A[],int n)	
	{
	
		if(th==NULL)
			return;
		while(n>th->cap)
			resizeH(th);
		int i;
		for(i=0;i<n;i++)
			th->a[i]=A[i];
		th->cnt=n;
		for(i=(n-1)/2;i>=0;i--)
			heapifyH(th,i);			
	
	
	
	
	}
	
		

		
