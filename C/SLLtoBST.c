// sorted list to BST
#include<stdio.h>

struct BT *createBST(struct SLL *head, int l, int r)
{
	if(!head)
		return NULL;
	if(r<l)
		return;
	else
		{
			int m = l+(r-l)/2;
			struct BT *left = createBST(head, l, m-1);
			struct BT *root = (struct BST *)malloc(sizeof(struct BST));
			root->data = head->data;
			root->l = left;
			head = head->next;
			root->r = createBST(head, m+1, r);
			
			return root;
		}



}
int main()
	{
	
	
	return 0;
	}