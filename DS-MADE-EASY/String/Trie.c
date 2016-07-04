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

struct Trie
{
	char data;
	int endof;
	struct Trie *child[26];


};

struct Trie *insertInTrie(struct Trie **root, char *word)
{
	
	if(!*word)
		return;
	if(!*root)
	{
		struct Trie *Node = (struct Trie *)malloc(sizeof(struct Trie));
		Node->data = *word;
		int i;
		for(i=0; i<26;i++)
			Node->child[i] = NULL;
		if(!*(word+1))
		
				Node->endof = 1;
		else{
				Node->child[*word] = insertInTrie(&(Node->child[*word]), word+1);
			return Node;	
		}
	}else
	{(*root)->child[*word] = insertInTrie(&(*root)->child[*word], word+1);
	return (*root);
}
	
}


int searchInTrie(struct Trie *root, char *word)
{
	
	if(!root)
		return -1;
	if(!(*word))
	{
		if(root->endof)
			return 1;
		else
			return -1;
		
	}
	if(root->data == *word)
		return searchInTrie(root->child[*word], word+1);
	else
		return -1;
	
	
	
	
}

int main()
{
	
	struct Trie *root=NULL;
	char *word="abcd";
	insertInTrie(&root, word);
	searchInTrie(root, word);
	
	
}