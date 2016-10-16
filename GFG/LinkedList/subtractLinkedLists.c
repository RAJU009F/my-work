// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/LinkedList
# Problem Statement	: subtract Linked Lists
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------
1. compute the lengths 
2.  if same not same length append the zeros in front for smaller list
3. find the list with smaller value
4. recursively subtract it from bigger one 

#sample output
----------------------

=======================
*/

struct Node 
{
	
	struct Node *next;
	int data;
	
};

void printList(struct Node *head)
{
	while(head)
	{
		printf("%d ", head->data);
		head = head ->next;
		
	}
	printf("\n");
}


struct Node *newNode(int data)
{
	struct Node *node =  (struct Node *)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	
	return node;
	
}

int findlen(struct Node *h)
{
	
	int count = 0;
	while(h)
	{
		count++;
		h =  h->next;
	}
	
	return count;
	
}

struct Node *appendZeros(struct Node *h,  int count)
{
	while(count--)
	{
		struct Node *node =  newNode(0);
		node->next = h;
		h =  node;
		
	}
	
	return h;
}

struct Node *subtractUtil(struct Node *a, struct Node *b, int *carry)
{
	
	if(!a && !b && *carry ==0)
		return NULL;
	
	struct Node *NN =  subtractUtil(a?a->next:NULL, b?b->next:NULL, carry);
	
	int adata = a->data;
	int bdata = b->data;
	if(*carry)
	{
		bdata--;

		*carry = 0;
	}
	
	if(adata>bdata)
	{
		*carry = 1;
		bdata = bdata +10;
		
	}
	
	
	struct Node *r =  newNode(bdata-adata);
	
	r->next = NN;

	return r;
	
	
}



struct Node *subtract(struct Node *a,  struct Node *b)
{
	if(!a && !b)
		return NULL;
	if(!a )
		return b;
	if(!b)
		return a;
	
	//  find length
	
	int len1 =  findlen(a);
	int len2 =  findlen(b);
	
	struct Node *sl ;
	struct Node *ll;
	struct Node *a1 =  a;
	struct Node *b1 = b;
	if(len1 == len2)
	{
		while (a->data == b->data)
		{
			if(a->data != b->data)
			{
				sl =  a->data<b->data? a1:b1;
				ll =  a->data>b->data? a1:b1;			
				break ;
			}
			a = a->next;
			b = b->next;
			
		}
		
	}else
	{
		printf("ss");
		sl =  len1<len2? a:b;
		ll = len1>len2? a:b;
		
		sl =  appendZeros(sl, (len1-len2));
		
		
	}
	printf("ss");
	int c =0;
	return subtractUtil(sl, ll, &c);
	
	
}

int main()
{
	struct Node *l1 = NULL;
	l1 = newNode(1);
	l1->next = newNode(0);
	l1->next->next =  newNode(0);
	
	struct Node *l2 =  newNode(1);

	
	struct Node *res =  subtract(l1, l2);
	
		printList(l1);
	printList(l2);
	printList(res);
	
	
	
	
}

