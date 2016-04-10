#include<iostream>
#include<queue>
#include<stack>
#include<stdlib.h>
using namespace std;

struct BT
	{
		struct BT *r;
		struct BT *l;
		int data;
	};
	
struct BT *nn(int d)
	{
	
		 BT *root=new BT;
		root->l=root->r=NULL;
		root->data=d;
		
		return root;
		
	
	
	}
void printpost(struct BT *root)
	
	{
		if(!root)
			return;
			
			
		stack<struct BT *>s;
		
		do
			{
				while(root)
					{
						if(root->r)
							s.push(root->r);
					
						s.push(root);
				
						root=root->l;	
					}
						root=s.top();
						s.pop();
					if(root->r && s.top()==root->r)
						
						{
							s.pop();
							s.push(root);
							root=root->r;
						
						
						
						}	
						
					else
						{
							cout<<"["<<root->data<<"]  ";
						
							root=NULL;
						}	
			}while(!(s.top()==NULL));
	
	
	
	
	
	
	
	
	}	
	

void print(struct BT *root)
	{
		if(root)
			{
				print(root->l);
				print(root->r);
				
				cout<<"["<<root->data<<"] ";
			
			
			
			}
	
	
	}

main()
	{
		struct BT  *rt=nn(6);
		rt->l=nn(45);
		rt->l->l=nn(54);
		rt->l->r=nn(43);
		rt->r=nn(5);
		rt->r->l=nn(65);
		rt->r->r=nn(565);
		print(rt);
		printpost(rt);
	
	
	}
