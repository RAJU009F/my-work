#include<stdio.h>
#include<stdlib.h>

struct BT
{
	
	struct BT *r;
	struct BT *l;
	int data;
	
	
};

struct stack 
{
	struct BT *node;
	struct stack *next;
	
};

void push(struct stack **top, struct BT *node)
{
	struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
	temp->node = node;
	temp->next = (*top) ;
	(*top) = temp;
	
	
}

int isEmpty(struct stack *top)
{
	
	return (top==NULL);
	
	
}

struct BT *pop(struct stack **top)
{
	struct stack *temp;
struct BT 	*t;
	
	if(isEmpty(*top))
	{
		return NULL;
		
	}else
	{
		
		temp = *top;
		t=temp->node;
		*top  = temp->next;
		free(temp);
		return t;
	}
	
	
	
}
struct BT *Top(struct stack *s)
{
	if(isEmpty(s))
		return NULL;
	else
		return s->node;
	
	
}

struct BT *newnode(int data)
{
	struct BT *node = (struct BT *)malloc(sizeof(struct BT ));
	if(!node)
			return;
	node->r=NULL;
	node->l = NULL;
	node->data = data;
	return node;
	
	
}

void inorder(struct BT *root)
{
	
	if(!root)
			return;
	struct stack *top ;
	while(1)
	{
		if(root)
		{
			push(&top, root);
		
			root=root->l;
			
			
		}else
		{
		if(isEmpty(top))
		{
			return;
			
		}
			root = pop(&top);
			printf("\t[%d]",root->data);
			root=root->r;
			
			
		}
		
		
	}
	
	free(top);
	
}
void postorder(struct BT *root)
{
	if(!root)
			return;
	struct stack *top;	
	printf("\n\npost oreder traversal :\n");
	while(1)
	{
		if(root)
		{
			push(&top,root);
			root = root->l;
			
			
		}
		else
		{
			if(isEmpty(top))
			{
				printf("");
				return;
				
			}else
			
				if(!(Top(top)->r))
				{
					root = pop(&top);
					printf("\t[%d]",root->data);
					
				if(root==Top(top)->r)
				{
					
					printf("\t[%d]",Top(top)->data);
					pop(&top);
				}
				}
				
				
			
			if(!isEmpty(top))
			{
				root = Top(top)->r;
				
				
			}else
				root =NULL;
			
			
			
			
		}
		
		
		
		
	}
		free(top);
}

int main()
{
	struct BT *root=newnode(1);
		root->l = newnode(2);
		root->r = newnode(3);
		root->l->l = newnode(4);
		root->l->r = newnode(5);
		root->r->l= newnode(6);
		root->r->r = newnode(7);
	
	//inorder(root);
	postorder(root);
	
}


