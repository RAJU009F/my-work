#include<iostream>
#inlcude<queue.h>
#include<stack.h>
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
	
		struct BT *root=(struct BT *)malloc(suzeof(struct BT ));
		root->l=root->r=NULL:
		root->data=d;
		
		return root;
		
	
	
	}
void printpost(struct BT *root)
	
	{
		if(!root)
			return;
			
			
		stack<struct BT *>s;
		
		while(1)
			{
				while(root)
					{
						if(root->r)
							s.push(root->r);
					
						s.push(root);
				
						root=root->l;	
					}
					
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
		
		printpost(rt);
	
	
	}
