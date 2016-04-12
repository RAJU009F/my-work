#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: LinkedLists
# Problem Statement	: 
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

struct SLL
{
	int data;
	struct SLL *next;
};

struct SLL *newNode(int data)
{
	struct SLL *node = (struct SLL *)malloc(sizeof(struct SLL));
	
	if(!node)
			return;
		
		node->next = NULL;
		node->data = data;
		
		return node;
	
	
}

void printList(struct SLL *h)
{
	while(h)
	{
		printf("[%d]->",h->data);
		h=h->next;
	}
	printf("NULL\n");
	
	
}

void findIntersectNode(struct SLL *h1, struct SLL *h2)
{
	//  get lenths of both lists
	if(!h1 || !h2)
	{
		printf("no intersection point exists\n");
		return;
		
	}
	int a=0,b=0,i;
	struct SLL *p,*q;
	for(p=h1; p;p=p->next)
		a++; 
	for(p=h2; p;p=p->next)
		b++;
	int diff = a-b;
	p=h1;
	q=h2;
	if(b>a)
	{diff = b-a;
		p=h2;
		q=h1;
    }
	
	for(i=0;i<diff;i++)
	{
		p= p->next;
		
	}
	printf("diff:%d, ",diff);
	while(p&&q&&p!=q)
	{
		
		p=p->next;
		q=q->next;
		
	}
	
	printf("intersect node: [%d]\n",p->data);
	
}

int main()
	{
	
	struct SLL *head1 = newNode(1);
		head1 -> next = newNode(2);
		head1->next->next = newNode(3);
		head1->next->next->next = newNode(4);
		struct SLL *temp=head1->next->next->next->next = newNode(5);
		head1->next->next ->next ->next ->next = newNode(6);
		head1->next->next->next->next->next->next = newNode(7);
		head1->next->next->next->next->next->next->next = newNode(8);
		head1->next->next->next->next->next->next->next->next = newNode(9);
		struct  SLL *last=head1->next->next->next->next->next->next ->next ->next ->next = newNode(10);
		
		struct SLL *head2 = newNode(100);
		head2 ->next = newNode(200);
		head2-> next->next = newNode(300);
		head2->next->next->next = temp;
		printf("List1:\n");
		printList(head1);
		printf("List2:\n");
		printList(head2);
		findIntersectNode(head1, head2);
	
	return 0;
	}