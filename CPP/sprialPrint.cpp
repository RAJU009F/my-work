#include<iostream>
#include<stack>
using namespace std;
struct BT
	{
		int data;
		struct BT *l,*r;
	
	};
struct BT *newnode(int data)
		{
			struct BT *root = new struct BT;
			root->data = data;
			root->l  = root->r = NULL;
			
			return root;
		
		
		}
		
void printSprial(struct BT *root)
{
	stack<struct BT *> s1;
	stack<struct BT *> s2;
	
	s1.push(root);
	
	while(!s1.empty() || !s2.empty())
	{
		
		while(!s1.empty())
		{
			struct BT *temp = s1.top();
			s1.pop();
			cout << temp->data<<" ";
			
			if(temp->l)
					s2.push(temp->l);
			if(temp->r)
					s2.push(temp->r);
			
		}
		
		cout<<"\n";
		while(!s2.empty())
		{
			struct BT *temp = s2.top();
			s2.pop();
			cout << temp->data<<" ";
			
			if(temp->r)
					s1.push(temp->r);
			if(temp->l)
					s1.push(temp->l);
			
		}
		
		cout<<"\n";
		
	}
	
	
}
		
int main()
		{
			struct BT *root = newnode(1);
			root->l=newnode(2);
			root->r = newnode(3);
			root->l->l = newnode(4);
			root->l->r = newnode(5);
			
			root->r->l = newnode(6);
			root->r->r= newnode(7);
			
			printSprial(root);
		return 0;
		}