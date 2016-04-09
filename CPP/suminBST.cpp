#include<iostream>
#include<stack>
using namespace std;

struct BT 
	{
	int data;
	struct BT *l;
	struct BT *r;
	};

void merge(struct BT *root1, struct BT *root2)
{
	if(!root1 && !root2)
			return;
	stack<BT *> stack1;
	stack<BT *>stack2;
	int done1=1;
	int done2=1;
	int v1,v2;
	while(1)
	{
		while(done1)
		{
			if(root1)
			{
				stack1.push(root1);
				root1= root1->l;
				
				
			}else
			{
				if(stack1.empty())
				{
					done1=0;
					
					
				}else	
				{
					root1=stack1.top();
					stack1.pop();
					v1 = root1->data;
					//root1= root1->l;
					done1=0;
				}
				
				
			}
			
			
			
		}
		
		
		while(done2)
		{
			if(root2)
			{
				stack2.push(root2);
				root2= root2->l;
				
				
			}else
			{
				if(stack2.empty())
				{
					done2=0;
					
					
				}else	
				{
					root2=stack2.top();
					stack2.pop();
					v2 = root2->data;
					//root2= root2->l;
					done2=0;
				}
				
				
			}
			
			
			
		}
		
		if(v1 > v2)
		{
			
		cout<<"["<<v2<<"]\t";
		root2 = root2->r;
			done2=1;
			
		}else if(v1<v2)
		{
			cout<<"["<<v1<<"]\t";
		root1 = root1->r;
			done1=1;
			
		}else
		{
			
			cout<<"["<<v2<<"]\t";
		root2 = root2->r;
			done2=1;
			root1 = root1->r;
			done1=1;
		}
		
		if(!done1 && !done2 && !root1 && !root2)
			return;
		
	}
	
	
	
}
int findNum(struct BT *root, int sum)
	{
		if(!root)
			return 1;
			
		stack<BT *> stack1;
		stack<BT *> stack2;	
		struct BT *root1 = root;
		struct BT *root2 = root;
		
		int done1 = 1, done2=1;
		
		int v1=0, v2=0;
		while(1)
			{
			while(done1){
			if(done1 && root1 )
				{
					stack1.push(root1);
					//cout<<"root1"<<root1->data;
					root1 = root1 ->l;
					
				}else
					{
						if(stack1.empty())
							{
							done1=0;
							return 0;
							}else
								{
								root1 = stack1.top();
								stack1.pop();
								v1 = root1->data;
								//root1=root1->r;
								done1=0;
								//cout<<"root1"<<root1->data;
								}
					
					
			}}
				while(done2){	
				if(done2 && root2 )
				{
					stack2.push(root2);
					
					root2 = root2 ->r;
				
				}else
					{
						if(stack2.empty())
							{
							done2=0;
							return 0;
							}else
								{
								root2 = stack2.top();
								stack2.pop();
								v2 = root2->data;
								//cout<<"root2"<<root2->data;
								done2=0;
								
								}
					
					
				}}


				if ( v1+v2 == sum )
					{
						cout<<"checked"<< v1 <<"...."<< v2 <<"\n";
						return 1;
					
					}
				else if(v1 + v2 < sum)
					{
						root1 = root1->r;
						done1=1;
						done2=0;
					cout<<"checked"<< v1 <<"...."<< v2 <<"\n";
					}else
					{
					
					root2 = root2->l;
						done2=1;
						done1=0;
					cout<<"checked 2 "<< v1  <<"...."<< v2 <<"\n";
					}
			
			if(v1>v2)
			{
				return 0;
			}
			
			}
	
	
	
	}
	
struct BT *newnode(int data)
{
	struct BT *node = new BT;
	node->data = data;
	node->l = NULL;
	node->r =  NULL;
	
	return node;
}
void inorder(struct BT *root)
{
	
	if(!root)
			return;
	inorder(root->l);
	cout<<"["<<root->data<<"]\t";
	inorder(root->r);
	
}

void inorder_i(struct BT *root)
{
	
	if(!root)
			return;
		stack<BT *> stack1;
		while(1)
		{
			
			if(root)
			{stack1.push(root);
					root = root ->l;
				
				}else
					{
						if(stack1.empty())
							{
							
							return ;
							}else
								{
								root = stack1.top();
								stack1.pop();
							cout<<"["<<root->data<<"]\t";
								root=root->r;
								
								
								}
					
					
					}
			
			
		}

	
}
int main()
	{
	struct BT *root=newnode(60);
	root->l = newnode(40);
	root->r = newnode(70);
	root->l->r = newnode(50);
	root->l->l = newnode(20);
	
	root->l->l->r = newnode(30);
	root->l->l->l = newnode(10);
	root->r->r = newnode(80);
	root->r->l = newnode(65);
	inorder_i(root);
 findNum(root, 150) == 1 ? cout<<"exists\n\n":cout<<"not exists\n\n";
 struct BT *root1=newnode(66);
	root1->l = newnode(47);
	root1->r = newnode(79);
	root1->l->r = newnode(59);
	root1->l->l = newnode(28);
	
	root1->l->l->r = newnode(34);
	root1->l->l->l = newnode(19);
	root1->r->r = newnode(86);
	
 merge(root, root1);
 
	
	}