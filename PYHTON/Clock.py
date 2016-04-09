#!usr/bin/python

import sys
import os

""" 
Example for Inheritance
Clock class 

"""

class Clock(object):
	def __init__(self, hours=0, minutes=0, seconds=0):
		self.__hours = hours
		self.__minutes = minutes
		self.__seconds = seconds
	
	def set(self, hours, minutes, seconds):
		self.__hours = hours
		self.__minutes = minutes
		self.__seconds = seconds
		
	def tick(self):	
		if(self.__seconds == 59):
			self.__seconds = 0
			if(self.__minutes == 59):
				self.__minutes = 0
				self.__hours =0 if self.__hours == 23 else self.__hours +1
			else:
				self.__minutes +=1
		else:
			self.__seconds +=1
			
	def display(self):
		print("{0}:{1}:{2}".format(self.__hours, self.__minutes, self.__seconds))
	def __str__(self):
		return "%2d:%2d:%2d" %(self.__hours, self.__minutes, self.__seconds)
"""
x= Clock()
print(x)
for i in range(10000):
	x.tick()
print(x)	
"""