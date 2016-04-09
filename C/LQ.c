/* Q implementation Linked  List*/
#include<stdio.h>
#include<stdlib.h>

struct Node 
	{
		struct Node *next;
		int data;
	};

struct Q
	{
	struct Node *f;
	struct Node *r;
	
	};
	
struct Q *createQ()	;
void nQ(struct Q *q, int data);
int dQ(struct Q *q);
int main()
	{
		
		struct Q *q = createQ();
		int i = 0;
		printf("\tfront: %d rear :%d\n\n",q->f->data, q->r->data);
		for(i=0; i<5; i++)	
			{
			nQ(q,(i+1)*100);
			
			}
			dQ(q);
				printf("\tfront: %d rear :%d\n\n",q->f->data, q->r->data);	
			
		return 0;
		
	}

struct Q *createQ()
	{
		struct Q *q = (struct Q *)malloc(sizeof(struct Q));
		if(!q)
			return NULL;
		 q->f = (struct Node *)malloc(sizeof(struct Node));
		if(!q->f)
			return NULL;
		q->r = (struct Node *)malloc(sizeof(struct Node));
		if(!q->r)
			return NULL;
		return q;	
	}
void nQ(struct Q *q, int data)

	{
			struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
			if(!newNode)
				return;
			newNode -> data = data;
			if(!q)
				{q->f= q->r=newNode;
				}
			q->r->next = newNode;
			q->r = newNode;	
			
			if(q->f == NULL)
				q->f = q->r;
				
	
	}
int dQ(struct Q *q)
		{
			struct Node *temp;
			int data;
			if(!q)
				{
				printf("empty q");
				return -1;
				}
			temp = q->f;
			q->f = q->f->next;
			data= temp->data;
			free(temp);
			return data;
		
		}