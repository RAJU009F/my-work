//#include<bits/stdc++.h>
//using namespace std;
#include<stdio.h>
#include<stdlib.h>
struct LL 
{
	int data;
	struct LL *next;
	
	
};

struct LL *newNode(int data)	
{
	struct LL *node = (struct LL *) malloc(sizeof(struct LL));
		node->data = data;
		node->next = NULL;
	return node;
	
}
void createLL(struct LL **h, struct LL **l)
{
	int i=20;
	struct LL *current=*h, *temp;
	for ( i ; i<100; i+=10)
	{
		while(current->next)
		{
			current=current->next;
			
		}
		temp = newNode(i);
		*l = temp;
		current->next = *l;
		
	}
	
	
	
}

void detectRemoveLoop(struct LL *h)
{
	struct LL *sp, *fp;
	sp = fp=h;
	while(fp && fp ->next)
	{
		sp = sp ->next;
		fp = fp -> next->next;
		if(sp == fp)
		{
			break;
		}
		
		
	}
	
	sp = h;
	
	while(sp != fp->next)
	{
		sp = sp -> next;
		fp = fp ->next;
		
	}
	
	fp ->next = NULL;
	
	
}
void printLL(struct LL *h)
{
	
	while(h)
	{
	//cout<<"["<<h->data<<"]->";
	printf("[%d]->",h->data);
		
	}
	
	
}
int main()
	{
	
	struct LL *head = newNode(10);
	struct LL *last = NULL;
	createLL(&head, &last);
	
	// create Loop
	
	last-> next = head->next->next->next->next;
	
	detectRemoveLoop(head);
	printLL(head);
	
	}