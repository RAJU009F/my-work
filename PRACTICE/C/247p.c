#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BT 
	{
		struct BT *l;
		struct BT *r;
		struct BT *next;
		int data;
	
	};
	
struct BT *nn(int d)
	{
		struct BT *root=(struct BT *)malloc(sizeof(struct BT ));
		
		root->l=NULL;
		root->r=NULL;
		root->next=NULL;
		root->data=d;
		
		return root;
		
		
	
	
	
	}	
void populate(struct BT *root)
	{
		static struct BT *n=NULL;
		
		if(root)
			{
				populate(root->l);
				
				root->next=n;
				
				n=root;
				
				populate(root->r);
				
				
			
			
			
			}
		
	
	
	
	
	}	
	
void increment(struct BT *root, int d)
	{
		if(root->l)
			{
				root->l->data=root->l->data+d;
				increment(root->l,d);
			
			
			}
		else if(root->r)	
	
		{
			root->r->data=root->r->data+d;
			increment(root->r,d);
		
		
		}
	
	
	}	
	
void convert(struct BT *root)
	{
		if(!root || (!root->l&&!root->r))
			return;
			
		else
			{
			
				int lt=0;
				int rt=0;
				convert(root->l);
				convert(root->r);
				if(root->l)
					lt=root->l->data;
				if(root->r)	
					rt=root->r->data;
					
					int diff=lt+rt-root->data;
					
					if(diff>0)
						root->data=root->data+diff;
						
					if(diff<0)
						increment(root,-diff);	
				
				
				
				
				
			
			}	
			
	
	
	
	
	}	
	
int hasch_pro(struct BT *root)
	{
			int lt=0;
			int rt=0;		
		if(!root || (!root->l && !root->r))
			return 1;
		else
			{
				if(root->l)
					lt=root->l->data;
					
				if(root->r)
					rt=root->r->data;
					
				if(root->data==lt+rt && hasch_pro(root->l)&& hasch_pro(root->r))
					return 1;
					
				else
					return 0;			

			
			
			
			
			}	
			
	
	
	
	
	}	
int dia(struct BT *root )
	{
		static int d=0;
		if(!root)
			return 0;
		
		int lt=dia(root->l);
		int rt=dia(root->r);
		
		if(lt+rt>d)
			d=lt+rt;
		return (lt>rt?lt:rt)+1	;
	
	
	
	
	}	
void make_double(struct BT *root)
			{
				if(root)
					{
						make_double(root->l);
						make_double(root->r);
						struct BT *t=root->l;
						
						root->l=nn(root->data);
						root->l->l=t;
						
					
					
					
					}	
			
			
			
			}
void print_pre(struct BT *root)
	{
		if(root)
			{
				printf("[%d]\t",root->data);
				print_pre(root->l);
				print_pre(root->r);
					
							
			
			}
	
	
	
	
	}	
	
void make_mirror(struct BT *root)	
		{
			if(root)
				{
					make_mirror(root->l);
					make_mirror(root->r);
					
					struct BT *t=root->l;
					
					root->l=root->r;
					root->r=t;
				
				
				
				
				}
		
		
		
		
		}
		
int ans(struct BT *root,struct BT *node)	
	{
		if(!root)
			return false;
			
		if(root==node)
			return true;
			
		if(ans(root->l,node)||ans(root->r,node))
			{
			printf("[%d]\t",root->data);
			return true;
			}
					
		return false;			
	
	
	
	
	
	}	
/*int iscomplete(struct BT *root,int flag)
	{
		if(!root)
			return true;
			
			enque(q,root);
			
			while(!isEmpty(q))
				{
					root=dqueue(q);
					if(root->l)
					{
						if(flag==true)
							return flase;
					
								enquqe(q,root->l);
					
					}
					
					flag=true;
					
					
					if(root->r)
						{
							if(flag==true)
								return;
							enqueue(q,root->r);	
						
						
						
						}
				
				
				
				
				}
				
	
			return true;
	}	*/
		
	
main()

	{
		struct BT *rt=nn(4);
		
		
		rt->l=nn(65);
		rt->r=nn(100);
		rt->l->l=nn(102);
		rt->l->r=nn(123);
		rt->r->l=nn(4546);
		rt->r->r=nn(565);
	
		populate(rt);
		
		struct BT *t=rt;
		
		
		while(t)
			{
			
				printf("next of [%d] is : [%d]\n\n",t->data,t->next?t->next->data:0);
				t=t->next;
			
			}
			
			
		convert(rt);
		
		if(hasch_pro(rt))
			printf("\n\nyes:\n");
			
		else
			printf("\n\nNo\n");	
			
		printf("\n diameter is :[%d] \n\n",dia(rt));		
		
		print_pre(rt);
		printf("\n\n");	
		
		make_mirror(rt);
		//make_double(rt);
		printf("\n\n");
		print_pre(rt);
	
	printf("\n diameter is :[%d] \n\n",dia(rt));
	
	printf("ANces:: \n\n");
	
	ans(rt,rt->l->l);
	printf("\n\n");
	
	
	
	}	
	
