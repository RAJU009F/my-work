#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/String
# Problem Statement	: Tries
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
//const char *ptr;
//char *const ptr; 

struct TST
{
	char data;
	int endof;
	struct TST *l;
	struct TST *eq;
	struct TST *r;	
};

struct TST *insertinTST(struct TST *root, char *word)
{
	if(!root)
	{
		root = (struct TST *)malloc(sizeof(struct TST));
		root->data = *word;
		root->endof = 1;
		root->l = root->eq = root->r = NULL;
	}
	if(*word<root->data)
		root->l = insertinTST(root->l, word);
	else if(*word==root->data)
	{
		if(*(word+1))
			root->eq = insertinTST(root->eq, word+1);
		else
			root->endof =1;
	}
	else
		root->r = insertinTST(root->r, word);
	return root;
	
}

int searchinTST(struct TST *root, char *word)
{
	if(!root)
		return -1;
	if(*word<root->data)
		return (root->l, word);
	else if(*word> root->data)
		return (root->r, word);
	else
	{
		if(root->endof && *(word+1)=='\0')
			return 1;
		else
			return searchinTST(root->eq, ++word);
		
		
	}
	
	
	
}
int main()
{
	struct TST *root = NULL;
	char *word="abcr";
	insertinTST(root, word);
	if(searchinTST(root, word))
		printf("strinng found");
	else
		printf("string doesn't found");
	return 0;
}
