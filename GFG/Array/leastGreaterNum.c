// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<limits.h>

// #include<iostream>


// #include<algorithm>
// #include<string>
// #include<map>
// #include<vector>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: Find Leaaset greater number for every element and it should be right side
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
struct BT 
{
struct BT *l;
int data;
struct BT *r;
};


struct BT *newNode(int data)
{
	struct BT *node = (struct BT *) malloc(sizeof(struct BT ));
	node->data = data;
	node -> l = NULL;
	node->r = NULL;
	
	return node;

}

void insert(struct BT **root, int data, struct BT **succ)
{
	if(*root==NULL)
	{*root = newNode(data);
	return;}
	if((*root)->data>data)
	{
		*succ = *root;
		insert(&(*root)->l, data, succ);
	}else
		insert(&(*root)->r, data, succ);
	
	
	
}

void replace(int arr[], int n)
{
	int i;
	struct BT *root = NULL;
	for(i=n-1; i>=0 ; i--)
	{
		struct BT *succ=NULL;
		
		insert(&root, arr[i], &succ);
		
		if(succ)
			arr[i] = succ->data;
		else
			arr[i] = -1;
	}
	
	
	
	
	
}
void printArray(int arr[],  int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
	int size =  sizeof(arr)/ sizeof(arr[0]);
	printArray(arr, size);
	replace(arr,  size);
	printArray(arr, size);

}