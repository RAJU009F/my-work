/* Trees */

#include<stdio.h>
#include<stdlib.h>

struct BT
	{
		struct BT *l;
		int data;
		struct BT *r;
	
	};
struct S
		{
			struct BT *T;
			struct S *next;
		
		};
	
struct BT *createBT();
struct BT *newNode(int);
void preO(struct BT *);
void inO(struct BT *);
void poO(struct BT *);
struct S *createS();
void push(struct S **, struct BT *);
struct BT *pop(struct S *);
struct BT *top(struct S *);
void ipreO(struct BT *);
void iinO(struct BT *);
void ipoO(struct BT *);
int main()
		{
			struct BT *root= createBT();
			root->l = newNode(1);
			root->r = newNode(2);
			root->l->l = newNode(3);
			root->l->r = newNode(4);
			root->r->l = newNode(5);
			root->r->r = newNode(6);
			
			printf("\n\t===R - preorer ====\n");
			preO(root);
			printf("\n\t==R - inOrder ===\n");
			inO(root);
			printf("\n\t==R - PostOrder ===\n");
			poO(root);
			
			printf("\n\t==R - inOrder ===\n");
			//iinO(root);
			printf("\n\t==R - PostOrder ===\n");
			ipoO(root);
		
		}
		
struct S *createS()
			{
				struct S *s = (struct S *)malloc(sizeof(struct S));
				if(!s)
					return NULL;
				s->	T = (struct BT *)malloc(sizeof(struct BT));
				if(!s->T)
					return NULL;
				return s;	
			
			}
struct S *addNode(struct BT *node)
	{
		struct S *s = (struct S *)malloc(sizeof(struct S));
		if(!node)
			return NULL;
		s->	T = (struct BT *)malloc(sizeof(struct BT));
		s->T=	node;
		
		return s;
	
	}
			
void push(struct S **s, struct BT *node)
				{
					struct S *temp = addNode(node);
					if(!*s)
						*s = temp;
					else	{
					
						temp -> next = *s;
						*s = temp;
						//printf("pushed::%d\n\n\n ",node->data);
					
					}	
						
				
				
				}
int isEmpty(struct S *s)
					{
					
					return (s == NULL);
					}
				
struct BT *pop(struct S *s)
					{
					struct BT *node;
					struct S *temp;
					if (isEmpty(s))
						return NULL;
					temp = s;	
					node = temp->T;
					s= s->next ;	
					free(temp);
					return node;
					
					
					
					}
					
struct BT *top(struct S *s)
					{
					struct BT *node;
					struct S *temp;
					if (isEmpty(s))
						return NULL;
					temp = s;	
					node = temp->T;	
					
					return node;
					
					
					
					}					
struct BT *createBT()
			{
				struct BT *root = (struct BT *)malloc(sizeof(struct BT));
				if(!root)
					return NULL;
				root->l = NULL;
				root->r = NULL;
				root->data = 0;
			return root;	
			
			}
struct BT *newNode(int data)	
	{
		struct BT  *node = (struct BT *) malloc(sizeof(struct BT));
		if (!node)
			return NULL;
		node->l = NULL;
		node->r = NULL;
		node->data = data;
		
		return node;
	
	}
	
void preO(struct BT *root)
{
	if(!root)
		return;
	printf("\t[%d]",root->data);
	preO(root->l);
	preO(root->r);	



}	
void inO(struct BT *root)
{
	if(!root)
		return;
	
	inO(root->l);
	printf("\t[%d]",root->data);
	inO(root->r);	



}	
void poO(struct BT *root)
{
	if(!root)
		return;

	poO(root->l);
	poO(root->r);	
	printf("\t[%d]",root->data);


}	
	
void iinO(struct BT *root)
	{
		if(!root)
			return;
		struct S *s= createS();
		while(1)
			{
				while(root)
					{
						push(&s, root);
						root = root->l;
					
					
					
					
					}
					
			if(isEmpty(s))
				{
					break;
				
				}
			
				root = pop(s);
				printf("\t[%d]", root->data);
				root = root->r;
			
			
		
			
			
			
			}
	
	
	
	}
void ipoO(struct BT *root)
		{
			if(!root)
				return ;
			struct S *s= createS();
				if(root)
					{
						push(&s, root);
						root = root->l;
					
					}
				else	
					{
						if(isEmpty(s))
							return;
						else	
							{
								if(top(s)-> r == NULL)
									{
										root = pop(s);
										printf("\t[%d]",root->data);
										if(root= top(s) -> r)
											printf("\t[%d]",top(s)->data);
											pop(s);
									}
									
							
							
							
							
							}
					
					
					
					
					}
				if(!isEmpty(s))
					root = top(s)->r;
				else
					root = NULL;
		
		
		
		}