// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
// #include<limits.h>

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	: Rev words in a sentence
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


struct Node
 {
     int data;
     struct Node* left, *right;
}; 

/*  Function which returns the  root of 
    the constructed binary tree. */
    
struct Node *newNode(int data)
    {
        Node *root =  new Node();
        
        root->left = root->right = NULL;
        root->data = data;
        
        return root;
        
        
        
    }
void createNodes(struct Node **created, int i, int parent[], struct Node **root)
    {
        if(created[i])
            return;
        created[i] = newNode(i);
        //cout<<created[i]->data<<" ";
        if(parent[i] == -1)
            {
                *root = created[i];
                return;
            }
        if(created[parent[i]]==NULL)
            {
                createNodes(created, parent[i], parent, root);
                
                
            }
            
       
        
        if(created[parent[i]]->left)
            created[parent[i]]->right= created[i];
        else
            created[parent[i]]->left = created[i];
        
    }
struct Node *createTree(int parent[], int n)
{
    Node *created[n];
    Node *root = NULL;
    for(int i=0; i<n; i++ )
        created[i] = NULL;
        
    for(int i=0; i<n; i++)
        createNodes(created, i, parent, &root);
        
return root;
    

}

void inorder(struct Node *root)
{
	if(!root)
			return;
	cout<<root->data<<" ";
		
	inorder(root->left);
		inorder(root->right);
	
}

int main()

{
	int parent[] ={-1, 0, 0 ,1, 1 ,3, 5   };
	
	Node *root = createTree(parent, 7);
	inorder(root);
	
}

