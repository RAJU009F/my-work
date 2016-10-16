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
# Problem Statement	: Merg sort on LinkedList
# Description		: 
# Complexity		: 
# =======================
# sample output
# ----------------------

# =======================
# */

class Node:
	def __init__(self, data):
		self.data =  data
		self.next =  None
class LinkedList:
	def __init__(self):
		self.head =  None
		
	def push(self, data):
		node =  Node(data)
		node.next =  self.head
		self.head =  node
	def print_list(self, node):
		cur_node = node
		while cur_node:
			print(cur_node.data)
			cur_node = cur_node.next
			
	def merge_sort(self, node):
		if not node or not node.next:
			return
		a =  None
		b = None
		
			
if __name__=="__main__":
	ll = LinkedList()
	ll.push(5)
	ll.push(9)
	ll.push(4)
	ll.push(8)
	ll.push(3)
	
	
	ll.push(10)
	
	
	ll.push(7)
	ll.push(2)
	ll.push(6)
	
	ll.push(1)
	ll.print_list(ll.head)
	ll.merge_sort(ll.head)