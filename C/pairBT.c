#include<stdio.h>
#include<stdlib.h>

struct BT {
	
	struct BT *r, *l;
	int data;
	
};

struct stack {
	
	struct BT* *arr;
	int top;
	int size;
	
	
};

struct stack *createStack()
{
	
	struct stack *s = (struct stack *)malloc(sizeof(struct stack));
	if(!s)
		return NULL;
	s->size=100;
	s->top=-1;
	s->arr = (struct BT **)malloc(sizeof(struct BT *)*sizeof(100));
	
	return s;
		
	
	
	
}
struct BT *newnode(int data)
{
	
	struct BT *node  = (struct BT *)malloc(sizeof(struct BT));
	node->data =data;
	node->l= node->r =NULL;
	return node;
	
	
}
int isEmpty(struct stack *s)
{
	
	return (s->top==-1);
	
}
int isFulll(struct stack *s)
{
	return (s->top==s->size-1);
	
}

void push(struct stack *s, struct BT *node)
{
	if(isFulll(s))
		return;
	else
		s->arr[++s->top] = node;
	
	
}
struct BT *pop(struct stack *s)
{
	if(isEmpty(s))
			return NULL;
	else
	{
		struct BT *node = s->arr[s->top--];
		return node;
		
	}	
	
}




int  findPair(struct BT *root, int sum)
	{
		if(!root)
			return;
		struct stack *s1 = createStack();
		struct stack *s2 = createStack();
		
		int done1=1, done2=1;
	
	struct BT *root1=root;
	struct BT *root2=root;
	
		while(1)	
			{
			
				while(done1)
					{
						if(root1)
						{
							push(s1, root1);
							root1 = root1->l;
							
							
						}else	
						{
							
							if(isEmpty(s1))
							{
								return 0;
								
								
							}else
							{
								root1= pop(s1);
								
								done1=0;
							}
							
							
							
						}
					
					
					}
					
				while(done2)
					{
						if(root2)
						{
							push(s2, root2);
							root2 = root2->r;
							
							
						}else	
						{
							
							if(isEmpty(s2))
							{
								return 0;
								
								
							}else
							{
								root2= pop(s2);
								
								done2=0;
							}
							
							
							
						}
					
					
					}	
					
					
			if(root1->data + root2->data == sum)
			{
				printf("Pair exists");
				return 1;
				
			}
			
			else if(root1->data + root2->data > sum)
			{
				
				done1=0;
				root2=root2->l;
				done2=1;
				
			}else
			{
				done1=1;
				root1=root1->r;
				done2=0;
				
				
				
			}
			
			if(root1->data>root2->data)
					return 0;
			
			}
	
	
	}
	
int main()
{
	struct BT *root = newnode(10);
		root->l= newnode(5);
		root->r= newnode(18);
		root->l->l = newnode(2);
		root->l->r = newnode(6);
		
		root->r->l = newnode(12);
		root->r->r = newnode(26);
		struct stack *s1 = createStack();
		push(s1, root);
		printf("%d", pop(s1)->data);
		findPair(root, 28)==1?printf("pair existts"):printf("pair doesnt exists");
	
}