/* find the Nth node from end of the SLL*/ 

#include<stdio.h>
#include<stdlib.h>

struct Node
	{
	
		int data;
		struct Node *next;
	};

struct Node *createNode();
void insertNodes(struct Node **, int );
int findNthNode(struct Node *, int );
void printList(struct Node *);
void makeCycle( struct Node * );
void findCycle(struct Node *);
void removeLoop(struct Node *, struct Node *);

int main()
	{
	
		struct Node  *h=NULL, *temp;
			int i, find;
			h = createNode(0);
			for (i=0 ; i< 10; i ++ )
				{
					insertNodes(&h,i+1);
					
				
				}
			
			printList(h)	;
			find = findNthNode(h, 2);
			printf("n\n\nNth node from end:[%d]",find);
		makeCycle(h);
		findCycle(h);	
		printList(h)	;
		
		return 0;
	}
void removeLoop(struct Node *Loop, struct Node *h)
		{
			struct Node *ptr1;
			struct Node *ptr2;
			int k=1,i;
			
			ptr1 = Loop;
			ptr2 = Loop;
			//  find the loop length
		
			while(ptr1 != ptr2->next)
				{
					ptr2 = ptr2->next;
				
					k++;
				}
				printf("\n\n\nLoop Lenght :%d\n\n",k);
		// move one node k-nodes away from the head
		ptr2 = h;
		ptr1 = h;
		for(i=0; i<k; i++)
			{
				ptr2 = ptr2->next;
			}
			
		while(ptr1 != ptr2)
			{
				ptr1 = ptr1->next;
				ptr2 = ptr2 -> next;
			
			}
		ptr2 = ptr2 -> next;
		while (ptr2 -> next != ptr1)
			{
				ptr2 = ptr2 ->next;
			
			}
			
	ptr2 -> next = NULL;		
		
		
		
		}

void findCycle(struct Node *h)
		{
			if(!h)
				return;
			int loopexists = 0;	
			struct Node *fastptr, *slowptr;	
			fastptr = slowptr = h;
			while ( fastptr	&& slowptr)
				{
					fastptr = fastptr ->next;
					if (fastptr == slowptr)
						{
							printf ("\n\n Cycle Present");
							loopexists =1;
							removeLoop(slowptr, h);
							return;
						}
					fastptr = fastptr ->next;
						if(!fastptr)
						{	break;
						
						}
						
						if (fastptr == slowptr)
						{
							printf ("\n\n Cycle Present [%d]", slowptr->data);
							loopexists =1;
						removeLoop(slowptr, h);
						return;
						}
							slowptr = slowptr ->next;
					
				
				}
				
				
		/*	if (loopexists)
				{
				printf(" loopexists");
					slowptr = h;
					fastptr = fastptr -> next;
					printf("%d",slowptr->data);
						while(slowptr != fastptr)
							{
								slowptr = slowptr -> next;
								fastptr = fastptr -> next;
							//printf("%d",slowptr->data);
							}
				printf("\n\n\n\t Loop Begins at : [%d]",slowptr -> data);
				
				} */
			
		
		}
void makeCycle(struct Node *h)
		{
			struct Node *current;
			if (!h)
				{return; }
			else	
				{
				current = h;
				while(current -> next)
					{
						current = current -> next;
					
					}
				current -> next = h->next->next->next;	
				
				}
		
		}
int findNthNode(struct Node *h, int n)
		{
			int i, k=0;
			struct Node *Nthnode, *last;
			last = Nthnode=h;
			for (h; last; )
				{
					if (k>=n)
						{
							Nthnode = Nthnode -> next;
						}
					last = last -> next;
					k++;
				}
			if(n>k)
				return -1;
			else	
				{
					return Nthnode->data;
				}
		
		}
struct Node *createNode(int data)	
		{
			struct Node * newnode;
			newnode = (struct Node *) malloc(sizeof(struct Node ));
			if (!newnode)
				{
					printf(" Error in mem allocation\n");
					return NULL;
				}
			newnode -> data  = data;
			newnode -> next = NULL;
			return newnode;
		
		}
void insertNodes(struct Node **h, int data)
			{
				
			struct Node *newnode, *current,*prev;
			newnode = createNode(data);
			if(!*h)
				{
				*h = newnode;
				printf (" insertNodes");
				
				}
			else	
				{
				current = *h;
				while(current){
				prev = current;
				current = current -> next;
				}
			prev -> next = newnode;
			}
		}		
		
void printList(struct Node *h)
				{
				printf("\t");
				if(!h) {
					return;}
				
				while(h)
				{
					printf("[%d]->",h->data);
					h = h->next;
				}
				printf("NULL\n");
				}		
		