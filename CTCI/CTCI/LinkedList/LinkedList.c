// import java.io.*;
// import java.lang.*;
// import java.util.*;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: CTCI
# Problem Statement	: insert %20 instead of spaces in a string
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

struct Node{
	
	int data;
	struct Node *next; 
	
};

struct Node *newNode(int data)
{
	struct Node *t  =  (struct Node *)malloc(sizeof(struct Node));
	
	t->data = data;
	t->next = NULL;
	
	return t;
	
}

void printList(struct Node *l)
{
	while(l)
	{
		printf("[%d]->",l->data);
		l = l->next;
		
	}

}

struct Node *addLists(struct Node *l1, struct Node *l2)
{
	
	struct Node *res = NULL;
	struct Node *temp ;
	
	//int s ;
	int c = 0;
	int s = 0;
	while(l1 || l2)
	{
	
		s  = (l1?l1->data:0 )+ (l2?l2->data:0);
		s += c;
		c = (s>=10)?1:0;
		s = s%10;
		printf("\n%d",s);
		if(!res)
		{
			temp = newNode(s);
			res = temp;
			
		}else{
		temp->next = newNode(s);
		temp = temp->next;
		}
		if(l1)	
		l1  = l1->next;
		if(l2)
		l2  = l2 -> next;
	}
	
	if(c>0)
		temp->next = newNode(c);
		temp = temp->next;	
	//printList(res);	
	return res;	
}
int main()
{
	struct Node *list = newNode(1);
	list->next = newNode(3);
	list->next->next = newNode(2);
	
	struct Node *list1 = newNode(1);
	list1->next = newNode(3);
	list1->next->next = newNode(9);
	list1->next->next-> next= newNode(9);
	printf("\nList1:	");
	printList(list);
	printf("\nList2:	");
	printList(list1);
	
	struct Node *res=NULL;
    res =addLists(list, list1);
	printf("\nResult:	");
	printList(res);
	
}