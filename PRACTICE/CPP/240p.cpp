
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
	
struct BT *nn(int d)
	{
	
		struct BT *root=new BT;
		
		root->r=NULL;
		root->l=NULL;
		root->data=d;
	
			return root;
	
	
	}
	
void print_inorder(struct BT *root)
	{
		if(!root)
			return;
		
		
		
		stack<BT *>S;
		
		while(1)
			{
				while(root)
					{
						S.push(root);
						root=root->l;	
						
					
					}
					
					if(S.empty())
							return;
					else		
					{
						
					root=S.top();
					S.pop();
				cout<<"["<<root->data<<"]\t";
					root=root->r;
					
					
					}
			
			
			}
			
			
	
	}	
	
void print_preorder(struct BT *root)
	{
		if(!root)
			return;
			
		stack<BT *>S;
		
		while(1)
			{
			
				while(root)
					{
						cout<<"["<<root->data<<"]\t";
						S.push(root);
						root=root->l;
					
					}
					
					if(S.empty())
						{
							break;
							
						}
			
					else
						{
							root=S.top();
							S.pop();
							root=root->r;
						
						}
			
			
			
			
			}	
	
	
	
	
	}	
	
void print_postorder(struct BT *root)
	{
		if(!root)
			return;
			
			
		stack<BT *>S;
		do
			{
				while(root)
					{
						if(root->r)
							S.push(root->r);
						S.push(root);
						root=root->l;
							
					
					
					
					}
					
					root=S.top();
					
					S.pop();
					
					if(root->r && root->r==S.top())
						{
							S.pop();
							S.push(root);
							root=root->r;
						
						
						}
					else
						{
							cout<<"["<<root->data<<"]\t";
							root=NULL;
						
						
						
						}	
			
			}while(!S.empty());	
	
	
	
	
	}
	
void print_level(struct BT *root)
	{
		if(!root)
			return;
			
			queue<BT *>Q;
			Q.push(root);
			while(!Q.empty())
				
			{
				root=Q.front();
				Q.pop();
				cout<<"["<<root->data<<"]\t";
				
				if(root->l)
					Q.push(root->l);
				if(root->r)
					Q.push(root->r);	
				
			
			
			
			
			
			
			
			}
	
	
	
	
	}	
	
	
	
	void print_level_r(struct BT *root)
	{
		if(!root)
			return;
			
			queue<BT *>Q;
			stack<BT *>S;
			Q.push(root);
			while(!Q.empty())
				
			{
				root=Q.front();
				Q.pop();
				S.push(root);
				
				//cout<<"["<<root->data<<"]\t";
				
				if(root->l)
					Q.push(root->l);
				if(root->r)
					Q.push(root->r);	
				
			
			
			
			
			
			
			
			}
			
			while(!S.empty())
				{
					root=S.top();
					cout<<"["<<root->data<<"]\t";
					S.pop();
					
					
				
				
				
				}	
	
	
	}	
void print_atlevel(struct BT *root,int level)
	{
		if(root)
			{
				if(level==0)
					cout<<"["<<root->data<<"]\t";	
				else
					{
					
					print_atlevel(root->l,level-1);
					print_atlevel(root->r,level-1);
					
					}
			
			
			
			
			}
			
	
	
	
	}	
	
main()
	{
			struct BT *rt=nn(5);
	
			rt->l=nn(6);
			rt->r=nn(4);
			rt->l->r=nn(3);
			rt->l->l=nn(7);
			rt->r->r=nn(8);
		
			rt->r->l=nn(10);
			
			print_inorder(rt);
			cout<<"\n\n";
			print_preorder(rt);
			cout<<"\n\n";
			print_level_r(rt);
			cout<<"\n\n";
			print_level(rt);
			cout<<"\n\n";
			
			print_atlevel(rt,2);
			
			
		
	
	}


