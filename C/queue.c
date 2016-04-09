/* Queue implementation*/


#include<stdio.h>
#include<stdlib.h>

struct Q {
	int f;
	int r;
	int capacity;
	int *a;
	};
struct Q *createQ();
void NQ(struct Q *, int);
int DQ(struct Q *);
int isEmpty(struct Q  *);
int isFull(struct Q *);
int main()
	{
		struct Q *q = createQ();
		int i, s;
		s= size(q);
		
		printf("\t front: %d  rear : %d   capacity: %d   size:%d\n\n",q->f,q->r,q->capacity,s);
		for(i= 0 ; i<5; i++)
			{
				NQ(q,(i+1)*100);
			
			}
				s= size(q);
		
		printf("\t front: %d  rear : %d   capacity: %d   size:%d\n\n",q->f,q->r,q->capacity,s);	
		return 0;
	}
struct Q *createQ()
		{
		
		struct Q *q = (struct Q *) malloc(sizeof(struct Q));
		if(!q)
			return NULL;
		q->r= q->f= -1;
		q->capacity = 5;
		q->a = malloc(sizeof(int )*q->capacity);
		if(!q->a)
			return NULL;
			
		return q;
		
		}
void NQ(struct Q *q,  int data)	
			{
				if(isFull(q))
					{
						printf("\tq is full\n\n");
						return ;
					}
				q->r = (q->r + 1 ) %q->capacity;
				q->a[q->r] = data;	
			if(q->f ==-1)
				q->f = q->r;
			
			}
int DQ(struct Q *q)
			{
			int data;
			if(isEmpty(q))
				{
				printf("\t q is Emtpy\n\n");
				return -1;
				
				}
				
			data = q->a[q->f];
			if(q->r == q->f)
				{
					q->f=q->r=-1 ;
				}else
					{
					q->f = (q->f +1) % q->capacity;
					}
			
				return data;
			
			}
			
int isEmpty(struct Q *q)
				{
				
				return (q->f == -1);
				
				}
int size(struct Q *q)
					{
					
					return (q->capacity - q->f + q->r) %q->capacity;
					
					}

int isFull(struct Q *q)
	{
	
	return ((q->r + 1)%q->capacity == q->f);
	
	}