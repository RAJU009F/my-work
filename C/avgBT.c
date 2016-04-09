#include<stdio.h>
#include<stdlib.h>

struct BT
	{
		struct BT *r;
		struct BT *l;
		int data;
		
	
	};
	
	
	
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
void findavg(struct BT *root, int av[])
{
	
	if(!root)
			return;
	else{	
	av[0]+=root->data;
	av[1]+=1;
	findavg(root->l,av);
	findavg(root->r,av);
	}
	
	
}

void inorder(struct BT *root)
{
	if(root)
	{
		inorder(root->l);
		printf("[%d]\t",root->data);
		inorder(root->r);
		
		
	}
	
	
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
		int avg[2] ={0,0};
		findavg(root, avg);
		printf("%d,\t%d\tavg::%d\n",avg[0],avg[1],(avg[0]/avg[1]));
		inorder(root);
		 printf("\new_c_question\by");
			printf("\rbreakinterview");
	}
	