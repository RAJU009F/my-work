#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Type 				: LinkedLists
# Problem Statement	: 
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/
// Sinlgy Linked List
struct SLL
{
	int data;
	struct SLL *next;
};
struct SLL *newNode(int data)
{
	struct SLL *node =  (struct SLL *) malloc(sizeof(struct SLL));
	if(!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	return node;
	
}

void addNodes(struct SLL **h,  int data)
{
	struct SLL *cur = *h;
	while(cur->next)
	{
		cur = cur->next;
		
	}
	cur->next = newNode(data);
	
}
void extendList(struct SLL **h)
{
	int i,n;
	printf("Enter number of nodes to be added : ");
	scanf("%d",&n);
	srand(n);
	for(i=0;i<n;i++)
	{
		addNodes(h, rand()%100);
		
	}
	
}
void printSLL(struct SLL *h)
{
	while(h)
	{
		printf("[%d]->",h->data);
		h= h->next;
		
		
	}
	
	printf("NULL\n");
	
	
}

void lengthSLL(struct SLL *h)
{
	int count=0;
	while(h)
	{
		h = h->next;
		count++;
	}
	printf("\nLength: %d \n",count);
	
	
}

void insertNodeSLL(struct SLL **h )
{
		int data ,pos;
		struct SLL *p, *q;
		printf("Enter node data and position ::");
		
		scanf("%d %d", &data, &pos);
		
		if(!(*h) && pos>1)
		{
		printf("List is empty and position invalid\n");
		return;
		}
		
		else if(!(*h) && pos==1)
		{
			*h = newNode(data);
			
		}
		else if(pos==1)
		{
			p = newNode(data);
			p->next = *h;
			*h= p;
			
		}
		else
		{
			int k=1;
				p=*h;
			while(p && k<pos)
			{
				q= p;
				p= p->next;
				k++;
				
			}
		struct SLL *nNode = newNode(data);
			nNode->next = p;
			q->next = nNode;
				
			
			
			
		}
		
		
	
	
	
}

void deleteNodeSLL(struct SLL **h)
{
	
	if(!(*h))
	{
		printf("SLL empty\n");
		return ;
		
		
	}
	
		struct SLL *p, *q;
		int pos, k;
		printf("enter node position to be deleted:");
		scanf("%d",&pos);
		
	p = *h;	
	if(pos==1)
	{
		*h = p->next;
		free(p);
		
		
		
	}
	else
	{
		k=1;
		while(p->next &&  k<=pos-1)
		{
			q= p;
			p=p->next;
			k++;
			
		}
		
		if(!p)
		{
			printf("position not exists\n");
		return;
		}
		printf("q=%d, p=%d\n",q->data, p->data);
		q->next = p->next;
		free(p);
	}
	
	
	
}

void iniateSLL(struct SLL **h)
{
	int data;
	printf("Enter Initial node data: ");
	scanf("%d",&data);
	*h =  newNode(data);
	
}

int main()
	{
	
	struct SLL *head = NULL;
	int choice;
	while(1)
	{
		printf("\t Enter preferred choice\n \t1. iniateSLL()\n");
		printf("\t2.extendList()\n");
		printf("\t3.lengthSLL()\n");
		printf("\t4.printList()\n");
		printf("\t5.insertNodeSLL()\n");
		printf("\t6.deleteNodeSLL()\n");
		printf("\t0.exit()\n");
		
		scanf("%d",&choice );
		switch(choice)
		{
			case 1:
				iniateSLL(&head);
				break;
			case 2:
				extendList(&head);
				break;
			case 3:
				lengthSLL(head);
				break;
			case 4:
				printSLL(head);
				break;
			case 5:
				insertNodeSLL(&head);
				break;
			case 6:
				deleteNodeSLL(&head);
				break;
			case 0:
				exit(0);
			default:
				printf("Please enter valid choice:\n");
				break;
			
			
		} 
		
	
	
	}
	return 0;
	}