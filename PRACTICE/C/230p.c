#include<stdio.h>
#include<stdlib.h>



struct BT 
	{
		struct BT *l;
		struct BT *r;
		int data;	
	};
	
struct BT *nn(int d)
	{
		struct BT *root=(struct BT *)malloc(sizeof(struct BT ));
		root->l=NULL;
		root->r=NULL;
		root->data=d;
		return root;	
	
	}	
int search(int in[],int s,int n,int d)
	{
		int i=s;
		for(i;i<=n;i++)
			{	
				if(d==in[i])
					return i;
			
			}
			
	
	
	
	}	
	
	
struct BT *built(int in[] ,int pre[],int start,int n)
	{
		if(start>n)
			return NULL;
			
		
		static int pr=0;
		struct BT *root=nn(pre[pr++]);
		
			
			int i=search(in,start,n,root->data);
			if(start==n)
				return root;
			
		
			else
				{
					root->l=built(in,pre,start,i-1);
					root->r=built(in,pre,i+1,n);
				}
			
		return root;
			
		
		
		
	
	}	
struct BT* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
  static int preIndex = 0;
 
  if(inStrt > inEnd)
     return NULL;
 
  /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
  struct BT *tNode = nn(pre[preIndex++]);
 
  /* If this node has no children then return */
  if(inStrt == inEnd)
    return tNode;
 
  /* Else find the index of this node in Inorder traversal */
  int inIndex = search(in, inStrt, inEnd, tNode->data);
 
  /* Using index in Inorder traversal, construct left and
     right subtress */
  tNode->l = buildTree(in, pre, inStrt, inIndex-1);
  tNode->r = buildTree(in, pre, inIndex+1, inEnd);
 
  return tNode;
}	
	
	struct BT *builtBT(int p[],int i[],int st,int en)
    {
        if(st>en)
            return NULL;
            
         static int pin=0;
         
        struct BT  *root=nn(p[pin]);
        ++pin;
        
        if(st==en)
            return root;
        
        int inin=search(i,st,en,root->data);
        
        root->l=builtBT(p,i,st,inin-1);
        root->r=builtBT(p,i,inin+1,en);
        
        return root;       
    
    
    
    
    
    }
	
void inprint(struct BT *root)
	{
		if(root)
			{
				inprint(root->l);
				printf("[%d]\t",root->data);
				inprint(root->r);
					
			
			
			}
	
	
	}	
	
void preprint(struct BT *root)
	{
		if(root)
			{	
				printf("[%d]\t",root->data);
				preprint(root->l);
				preprint(root->r);
			
			}
	
	
	}	
	
main()
	{
		int pre[]={3,5,2,6,7,1,4};
		
		int in[]={1,2,3,4,5,6,7};
		
		struct BT *rt;
		
		
		int n=sizeof(pre)/sizeof(pre[0]);
		printf("%d",n);
		rt=built(in,pre,0,n-1);
		
		printf("\n\n");
		inprint(rt);
		
		printf("\n\n");
		
		preprint(rt);
		printf("\n\n");
		
		//struct BT *rt1=builtBT(pre,in,0,n-1);
		//inprint(rt1);
		
		//printf("\n\n");
		
		//preprint(rt1);
		//printf("\n\n");
		
	}	
