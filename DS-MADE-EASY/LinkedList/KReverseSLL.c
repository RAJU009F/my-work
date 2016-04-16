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

/*int hasKnodes(struct SLL *h, int k)
{
	int i=0;
	for(h;h && i<k ; h=h->next)
		i++;
	
	if(i==k)
		return 1;
	printf("%d\n",i);
	return 0;
	
}

struct SLL *kPlus1thNode(struct SLL *h, int k)
{
	int i=0;
	struct SLL *cur,*temp;
	if(!h)
		return h;
	for(cur=h;cur&&i<k;i++)
	{
		temp = cur;
		cur = cur->next;
		
	}
	
	if(i==k && temp)
		return temp;
	
	return h;
}
struct SLL  *kReverseList(struct SLL **h, int k)
{
	
	struct SLL *cur=*h, *temp, *n,*newhead;
	int i;
	if(!cur || !cur->next)
			return cur;
		if(k<=1)
			return cur;
	if(!hasKnodes(cur, k-1))
		return cur;
	//printf("%d\n",newhead->data);	
	newhead = kPlus1thNode(cur,k-1);
	
	while(cur && hasKnodes(cur,k))
	{
		temp = kPlus1thNode(cur,k);	
			i=0;
		while(i<k)
		{
			n = cur->next;
			cur->next = temp;
			temp = cur;
			cur = n;
			
			i++;
		}
	}
return newhead;
	} */

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

struct SLL *kReverseListR(struct SLL *head ,int k)
{
	struct SLL *cur,*n,*prev;
	int count=0;
	cur = head;
	while(cur && count<k)
	{
		n = cur->next;
		cur->next = prev;
		prev= cur;
		cur =n;
		count++;
		
	}
	
	if(n)
			head ->next = kReverseListR(n,k);
	return prev;	
	
	
	
}
int main()
	{
		struct SLL *head1 = newNode(1);
		head1 -> next = newNode(2);
		head1->next->next = newNode(3);
		head1->next->next->next = newNode(4);
		head1->next->next->next->next = newNode(5);
		head1->next->next ->next ->next ->next = newNode(6);
		/*head1->next->next->next->next->next->next = newNode(7);
		head1->next->next->next->next->next->next->next = newNode(800);
		head1->next->next->next->next->next->next->next->next = newNode(9);
		head1->next->next->next->next->next->next ->next ->next ->next = newNode(10);
		*/printf("Before|\n");
		printList(head1);
		head1=kReverseListR(head1 ,3);
		printf("After");
		printList(head1);
	
	
	return 0;
	}