# // # import java.io.*;
# // # import java.lang.*;
# // # import java.util.*;

#!/usr/bin/python -O

 # include <stdio.h>
# include <stdlib.h>
 # include <string.h>
 # include<stdbool.h>
 # include<limits.h>

# // #include<iostream>
# // #include<algorithm>
# // #include<string>
# // #include<vector>
# //using namespace std;

# /*

# Author			: @RAJ009F
# Topic or Type 	: GFG/LinkedList
# Problem Statement	: pair wise swap elements
# Description		: 
# Complexity		: 
# =======================
# sample output
# ----------------------

# =======================
# */



class Node:
	def __init__(self, data):
		self.data  =  data
		self.next  =  None
		
class LinkedList:
	def __init__(self):
		self.head = None
		
	def push(self, data):
		node = Node(data)
		node.next = self.head
		self.head = node
		
	def print_list(self,  node):
		cur_node =  node
		while cur_node:
			print (cur_node.data)
			cur_node =  cur_node.next
			
	def groupK_reverse(self, node, k):
		cur_node =  node
		prev_node =  None
		temp_node = None
		count = 0
		while count <k and cur_node:
			temp_node = prev_node
			prev_node = cur_node
			cur_node = cur_node.next
			prev_node.next = temp_node
			count = count +1;
		if cur_node :
			node.next =  self.groupK_reverse(cur_node, k)
			
		return prev_node

	def alternativeK_reverse(self, node, k):
		cur_node = node
		prev_node = None
		temp_node = None
		count = 0
		while cur_node and count <k:
			temp_node = prev_node
			prev_node = cur_node
			cur_node = cur_node.next
			prev_node.next = temp_node
			count =  count +1
		if cur_node:
			node.next = cur_node
		count  = 0	
		while cur_node and count < k-1:
			cur_node = cur_node.next
			count = count +1
		if cur_node:	
			cur_node.next = self.alternativeK_reverse(cur_node.next, k)	
		return prev_node
if __name__=='__main__':
	
	ll = LinkedList()
	ll.push(10)
	ll.push(9)
	ll.push(8)
	ll.push(7)
	ll.push(6)
	ll.push(5)
	ll.push(4)
	ll.push(3)
	ll.push(2)
	ll.push(1)
	ll.print_list(ll.head)
	#ll.head =  ll.groupK_reverse(ll.head, 3)
	ll.head =  ll.alternativeK_reverse(ll.head, 3)
	ll.print_list(ll.head)
	