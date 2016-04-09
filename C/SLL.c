// linked list implementation
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
	
	};

void insertNodes(struct Node **, int );
void printList(struct Node *);	
struct Node *createNode();
void insert_node_pos(struct Node **, int , int);
void delete_node_pos(struct Node **, int);

int length(struct Node *);
void reverse(struct Node **);
void reverse_r(struct Node **, struct Node *);
	
int main()
		{
			struct Node  *h=NULL, *temp;
			int i, len;
			h = createNode(0);
			for (i=0 ; i< 2; i ++ )
				{
					insertNodes(&h,i+1);
					
				
				}
			printf("\t======= initial structure of List ======\n\n");
			printList(h);
			
			insert_node_pos(&h, 100, 1);
			insert_node_pos(&h, 200, 3);
			insert_node_pos(&h, 300, 6);
			printf("\t======= structure of List  after insert nodes at posns======\n\n");		
			printList(h);
			
			printf("\t======= structure of List  reversed ======\n\n");	
			reverse(&h);
			printList(h);
			
			printf("\t======= structure of List  reversed after reverse ======\n\n");	
			reverse_r(&h,h);
			printList(h);
			
			len = length(h);
			printf("\n\n \tLength of the list: %d \n\n",len);
			
			delete_node_pos(&h,  6);
			delete_node_pos(&h,  3);
			
			delete_node_pos(&h,1);
			printf("\t======= structure of List  after delete nodes at posns======\n\n");		
			printList(h);
			return 0;
		}

 void reverse_r(struct Node **h, struct Node *current)
	{
		if(!(*h))
			{
				return;
			}
		if( !(current->next))
			{
				*h= current;
				return;
			}
			
			reverse_r(&(*h), current->next);
			current -> next -> next = current;
			current ->next = NULL;
			
	
	
	
	}
		
void reverse(struct Node **h)
	{
		struct Node *prev, *current = NULL, *head = *h;
		if (!(head) || (!(head->next)))
			{
				return ;
			
			}
		else	{
		
		while(head)
			{
				prev = current;
				current = head;
				head = head -> next;
				current ->next = prev;
			
			
			
			}
			*h = current;
		
		}	
	
	
	}
int length(struct Node *h)
			{
			
			if(!h)
				return 0;
			else
				return 1+length(h->next);
			
			}
void delete_node_pos(struct Node **h, int pos)
	{
		if(!h)
			return;
		struct Node *current, *prev, *temp;
			int k;
		if (pos==1)
			{
				temp = *h;
				*h = (*h)->next;
				free(temp);
			}
		else
			{
			k=1;
			current = *h;
			while(current && k<pos)
				{
				prev = current;
				current = current -> next;
				k++;				
				}
			if (current)
				{
					prev -> next = current->next;
					free(current);
				}
				else{
					printf("Element not exists\n");
				
				}
			
			
			}
		
	
	
	}
void insert_node_pos(struct Node **h, int data, int pos)
			{
			struct Node *current, *temp, *newnode;
			int k;
			newnode = createNode(data);
			if(pos == 1)
				{
					if (*h){
					temp = newnode;
					temp -> next = *h;
					*h = temp;
					}else	{
					
					*h = newnode;
					}
				}
				else	
				{
					current = *h;
					k = 1;
					while(current && k<pos)
						{
						temp = current;
						current = current ->next;
						 k++;
						}
					if(current)
						{
						temp ->next = newnode;
						newnode->next = current;
						
						}
					else{
						
						temp -> next = newnode;
						newnode -> next = NULL;
					
					}	
				
				
				
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