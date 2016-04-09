#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct node
{
	int data;
	struct node *l;
	struct node *r;
};

 node* newNode(int data)
{
	struct node *temp = new node;
	temp->data = data;
	temp->l = temp->r= NULL;
	return temp;
	
	
}

void reverselevelorder(struct node *root)
{
	if(!root)
			return;
	stack <node *> S;
	queue<node *>Q;
	Q.push(root);
	
	while(Q.empty() == false)
	{
		root = Q.front();
		Q.pop();
		S.push(root);
		if(root->r)
		{Q.push(root->r);
			
		}
			
		if(root->l)
		{Q.push(root->l);
			
		}
		
		
	}
	
	while(S.empty() == false)
	{
		root = S.top();
		cout<<root->data<<"";
		S.pop();
		
	}
	
	
	
}
int main()
	{
	struct node *root = newNode(1);
	root ->l = newNode(2);
	root->r = newNode(3);
	root->l->r = newNode(4);
	root->l->l = newNode(5);	
	root->r->r = newNode(6);
	root->r->l = newNode(7);
	cout<< "level order in reverse";
	reverselevelorder(root);
	return 0;
	}