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
		self.data = data
		self.next = None
		
class LinkedList:
	def __init__(self):
		self.head = None
		
		
	def push(self, data):
		node = Node(data)
		node.next =  self.head
		self.head =  node
		
	def print_list(self):
		node =  self.head
		while node:
			print (node.data, end=' ')
			node =  node.next;
	def pair_wise_swap(self):
		node =  self.head
		while node and node.next: 
			node.data, node.next.data = node.next.data, node.data
			node =  node.next.next
			
	
if __name__ == "__main__":
		ll =  LinkedList()
		ll.push(1)
		ll.push(2)
		ll.push(3)
		ll.push(4)
		ll.push(5)
		ll.push(6)
		ll.push(7)
		ll.push(8)
		ll.print_list()
		ll.pair_wise_swap()
		ll.print_list()
		