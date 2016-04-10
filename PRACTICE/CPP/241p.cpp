#include<iostream>
using namespace std;
#include<stack>
#include<queue>


struct BT 
	{
		struct BT *l,*r;
		int data;
	
	};

struct BT *nn(int d)
	{
		struct BT *root=new BT;
		root->l=NULL;
		root->r=NULL;
		root->data=d;
		return root;
	
	
	}

void print_post(struct BT *root)
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
int height(struct BT *root)
	{
	
		if(!root)
			return 0;
			
		queue<BT *>q;
		
		q.push(root);
		q.push(NULL);
		
		int level=0;
		while(!q.empty())	
			{
				root=q.front();
				
				q.pop();
				
				if(!root)
					{
						if(!q.empty())
								q.push(NULL);
							
							level++;
					
					
					
					}
			
			else
				{
						
				if(root->l)	
					q.push(root->l);
				if(root->r)
					q.push(root->r);	
				
				}
			
			
			
			}
			
	
		return level;
	
	}	
	
int haspair(struct BT *root,int X)
	{
		if(!root)
			return 0;
		stack<BT *>s1;
		stack<BT *>s2;
		struct BT *r1=root,*r2=root;
		
		int v1,v2;
		int d1=0,d2=0;
		
		while(1)
			{
				while(!d1)
					{
						if(r1)
							{
								s1.push(r1);
								r1=r1->l;
							
							}
							
						if(s1.empty())
							d1=1;
						r1=s1.top();
						v1=r1->data;
						s1.pop();
						d1=1;
					
					}
					
				while(!d2)
					{
						if(r2)	
							{
								s2.push(r2);
								r2=r2->r;
								
							
							
							}
						if(s2.empty())
							d2=1;
						r2=s2.top();
						v2=r2->data;
						s2.pop();
						d2=1;
						
								
					
					
					
					}	
					
					if(v1+v2==X && r1!=r2)
						return 1;
						
					else if(v1+v2>X )
						{
							d2=0;
							r2=r2->l;	
						
						}	
					else
						{
							d1=0;
							r1=r1->l;
						}
					if((!r1 && s1.empty())||(!r2 && s2.empty()))
						return 0;	
			
			
			
			}	
			
	
	
	
	
	
	}
	int ceil(struct BT *root,struct BT *node)
		{
			
			if(!root)
				return -1;
				
			if(root->data==node->data)
				return root->data;
			if(root->data<node->data)
				return ceil(root->r,node);
		
				int c= ceil(root->l,node);			
			return c>=node->data?c:root->data;
		
		
		}	
		
void addsum(struct BT *root,int *sum)
	{
		if(root)
			{
				addsum(root->r,sum);
				*sum+=root->data;
				root->data=*sum;
				addsum(root->l,sum);
			
			
			
			}
	
	
	
	}		
	
void print_in(struct BT *root)
	{
		if(root)
			{
				print_in(root->l);
				cout<<root->data<<"\t";
				print_in(root->r);
			
			
			}
	
	}		
	
void zigzag(struct BT *root)	
	{
		if(!root)
			return;
			
		
			stack<BT *>s1,s2;
			
			int f=1;
			
			
			s1.push(root);
			
			while(!s1.empty())
				{
					root=s1.top();
					s1.pop();
					
					if(root)
						{
							cout<<root->data<<"   ";
						
							if(f)
								{
									if(root->l)
										s2.push(root->l);
									if(root->r)
										s2.push(root->r);	
										
								
								
								}
							else
								{
								
									if(root->r)
										s2.push(root->r);
									if(root->l)
										s2.push(root->l);	
								
								
								
								}	
						
						
						
						}
				if(s1.empty())
					{
						f=1-f;
						stack<BT *>s;
						s=s1;
						s1=s2;
						s2=s;
					cout<<"\n\n";
					
					
					}
				
				
				}
			
	
	
	
	
	}	
	
int 	main()
	{
			struct BT *rt=nn(5);
	
			rt->l=nn(2);
			rt->r=nn(6);
			rt->l->r=nn(3);
			rt->l->l=nn(1);
			rt->r->r=nn(18);
		
			rt->r->l=nn(10);
			
			
			
			cout<<"\n\n\n\n";
			
			
			cout<<height(rt)<<endl;
			
			if(haspair(rt,10))
				cout<<"has pair"<<endl;
			else
				cout<<"No pair\n\n"<<endl;
			cout<<"\n\nc:\n\n"<<ceil(rt,nn(4));	
			
			int sum=0;
			
			addsum(rt,&sum);
			
			print_in(rt);
			
			zigzag(rt);				
				
			
	}
