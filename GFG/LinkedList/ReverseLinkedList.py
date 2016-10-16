# import java.io.*;
# import java.lang.*;
# import java.util.*;

#!/usr/bin/python -O

# // #include <stdio.h>
# // #include <stdlib.h>
# // #include <string.h>
# // #include<stdbool.h>
# // #include<limits.h>

# // #include<iostream>
# // #include<algorithm>
# // #include<string>
# // #include<vector>
# //using namespace std;

# /*

# Author			: @RAJ009F
# Topic or Type 	: GFG/LinkedList
# Problem Statement	: Reverse Linked List ,  both iterative and recursive
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
		
	def push(self,data):
		node =  Node(data)
		node.next =  self.head
		self.head = node
		
	def print_list(self):
		cur =  self.head
		while cur:
			print (cur.data,  )
			cur =  cur.next
	def reverse_list(self):
		prev = None
		cur = self.head
		temp = None
		while cur != None:
			temp = prev
			prev = cur
			cur = cur.next
			prev.next = temp
		self.head = prev
	
	def reverse_list_rec_util(self,head):
		if not head: 
			return
		if not head.next:	
			 self.head = head
			 return
		self.reverse_list_rec_util(head.next)
		head.next.next = head
		head.next = None
		# temp = cur.next
		# cur.next = prev 
		# self.reverse_list_rec_util(temp, cur)
		#return self.head
	def reverse_list_rec(self):
		self.reverse_list_rec_util(self.head)
		pass
	def insert_node(self, key):
		if not self.head :
			self.head = Node(key)
		elif self.head.data>key:
			node = Node(key)
			node.next = self.head
			self.head = node
		else:
			prev = self.head
			cur =  self.head
			
			while cur and cur.data<key:
				prev =  cur
				cur =  cur.next
			node =  Node(key)
			prev.next =  node
			node.next = cur 
				
			
		

if __name__ == "__main__":
	ll = LinkedList();
	ll.push(1)
	ll.push(2)
	ll.push(3)
	ll.push(4)
	ll.push(6)
	ll.push(7)
	ll.push(8)
	ll.push(10)
	#ll.print_list()
	print ("reverse List")
	ll.reverse_list()
	#ll.print_list()
	
	ll.reverse_list_rec()
	print ("reverse list using rrecursive")
	ll.reverse_list_rec()
	ll.print_list()
	ll.insert_node(9)
	ll.print_list()
		
	
	
		
		
		