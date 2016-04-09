#include<stdio.h>
#include<stdlib.h>

struct L
	{
	int data;
	struct L *next;
	};
struct L *newnode(int data)
		{
			struct L *node = (struct L *) malloc(sizeof(struct L));
			if(!node)
				return NULL;
			node->data = data;
			node->next = NULL;
		}

void print(struct L *h)
{
	
	if(!h)
		return;
	else
	{
		
		printf("[%d]->", h->data);
		print(h->next);
		
	}
	
	
}
void revL(struct L *h , struct L **head)
{
	if(!h)
		return ;
	if(h && !h->next)
	{
		*head = h;
		return;
	}else{
		
		revL(h->next, head);
		h->next->next = h;
		h->next = NULL;
		
		
		
	}
	
	
}
int main()
		{
		struct L *h = newnode(0);
		printf("h->data::%d",h->data);
		int i;
		h->next = newnode(10);
		h->next->next = newnode(20);
		h->next->next->next = newnode(30);
		h->next->next->next->next = newnode(40);
		printf("====after=====\n\n");
		print(h);
		printf("====after=====\n\n");
		revL(h, &h);
		print(h);
		}
	