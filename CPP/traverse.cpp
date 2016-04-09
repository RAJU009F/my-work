#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct BT
	{
		struct BT *r;
		struct BT *l;
		int data;
		
	
	};
	
struct BT *newnode(int data)
{
	struct BT *node = new BT;
	node->data = data;
	node->l = node->r=NULL;
	
	return node;
}
	
void inorder(struct BT *root)
{
	
	if(!root)
			return ;
		
	stack< BT *> S;
	while(1)
	{
		
		while(root)
		{
			S.push(root);
			root =root->l;
			
			
			
		}
		if(S.empty())
			break;
		else
		{
			root = S.top();
			
			cout<<"["<<root->data<<"]";
			S.pop();
			root=root->r;
			
			
		}
		
		
		
	}
	
	
	
}
	
int main()
	{
	struct BT *root = NULL;
	root->l = newnode(2);
		root->r = newnode(3);
		root->l->l = newnode(4);
		root->l->r = newnode(5);
		root->r->l= newnode(6);
		root->r->r = newnode(7);
	cout<<"Inorder trversal";
	inorder(root);	
	
	}