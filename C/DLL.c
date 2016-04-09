// DLL 

#include<stdio.h>
#include<stdlib.h>
struct Node
	{
	struct Node *l;
	struct Node *r;
	int data;
	};

struct Node *createnode(int);
void insertnode(struct Node **, int);
void printlist(struct Node *);
int main()
	{
	struct Node *head, *temp;
	int i;
	head =createnode(0);
	for(i=0; i<2;i++)
		{
			insertnode(&head,i+1);
		
		}
	printlist(head);
	return 0;
	}
	
struct Node *createnode(int data)
		{
		struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
		if(!newnode)
			{
				return NULL;
			}
		newnode -> data = data;
		newnode -> l = NULL;
		newnode -> r = NULL;
		
		return newnode;
		}
void insertnode(struct Node **h, int data)
	{
		struct Node *temp, * current, *newnode;
		newnode = createnode(data);
		if(!(*h))
			{
			*h = newnode;
			}
		else{
			current = *h;
			while(current->l)
				{
				current = current->l;
				}
			current -> l = newnode;
			newnode -> r = current;
		
		}
	}

		
void printlist(struct Node *h)
			{
				if(!h)
					return;
				printf("[%d]->",h->data);	
				printlist(h->l);	
				
			
			
			}